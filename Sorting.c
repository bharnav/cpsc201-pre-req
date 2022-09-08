#include <stdio.h>
#include <stdlib.h>
#include "Sorting.h"

void swap(int * a, int * b)
{
    int temp = * a;
    * a = * b;
    * b = temp;
}

//referred to the Wikipedia algorithm: https://en.wikipedia.org/wiki/Insertion_sort
void insertion_sort(int a[], int n)
{
    int pos;
    int val;
    for(int i = 1; i < n; i++)
    {
        pos = a[i];
        val = i - 1;
        while(val >= 0 && a[val] > pos)
        {
            a[val + 1] = a[val];
            val = val - 1;
        }
        a[val + 1] = pos;
    }
}

//referred to the Wikipedia algorithm: https://en.wikipedia.org/wiki/Quicksort#Algorithm
int partition(int a[], int first, int last)
{
    int p = a[last];
    int j = first - 1;
    for(int k = first; k < last; k++)
    {
        if(a[k] <= p)
        {
            j = j + 1;
            swap(& a[j],& a[k]);
        }
    }
    swap(& a[j + 1], & a[last]);
    return j + 1;
}

void quick_sort(int a[], int first, int last)
{
    if(first < last)
    {
        int p = partition(a, first, last);
        quick_sort(a, first, p - 1);
        quick_sort(a, p + 1, last);
    }
}

//referred to this page for the algorithm, due to the fact that the Wikipedia page was very convoluted: https://www.enjoyalgorithms.com/blog/merge-sort-algorithm
void merge(int a[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for(int i = 0; i < n1; i++)
    {
        L[i] = a[left + i];
    }
    for(int i = 0; i < n2; i++)
    {
        R[i] = a[mid + 1 + i];
    }
    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            a[k] = L[i];
            i = i + 1;
        }
        else
        {
            a[k] = R[j];
            j = j + 1;
        }
        k = k + 1;
    }
    while(i < n1)
    {
        a[k] = L[i];
        i = i + 1;
        k = k + 1;
    }
    while(j < n2)
    {
        a[k] = R[j];
        j = j + 1;
        k = k + 1;
    }
}

void merge_sort(int a[], int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left)/2;
        merge_sort(a, left, mid);
        merge_sort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < n && a[left] > a[largest])
    {
        largest = left;
    }

    if(right < n && a[right] > a[largest])
    {
        largest = right;
    }
    if(largest != i)
    {
        swap(& a[i], & a[largest]);
        heapify(a, n, largest);
    }
}

void heap_sort(int a[], int n)
{
    for(int i = n/2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
    for(int i = n - 1; i >= 0; i--)
    {
        swap(& a[0], & a[i]);
        heapify(a, i, 0);
    }
}

void print(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
    printf("\n");
}