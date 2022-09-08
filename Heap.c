#include <stdio.h>
#include <stdlib.h> 
#include "Heap.h"

//I recieved help from Andrew Wen on this project

/*
Add a priority, value pair to the priority queue
Print out all priority, value pairs
Remove the element with highest priority
Get the value with highest priority without removing it (peek).
Turn an array of priority value pairs into a valid heap (heapify).
*/

void init(struct node * pq)
{
    pq -> size = 0;
    pq -> capacity = 2;
    pq -> val = malloc(sizeof(struct element)  * 2);
}

void swap(int * a, int * b)
{
    int temp = * a;
    * a = * b;
    * b = temp;
}

void add_heap(struct node * pq, int i)
{
    struct element * num = pq -> val;
    int temp_parent = (i - 1)/2;
    if(num[temp_parent].priority > 0)
    {
        if(num[temp_parent].priority < num[i].priority)
        {
            swap(&num[i].priority, &num[temp_parent].priority);
            swap(&num[i].value, &num[temp_parent].value);
            add_heap(pq, temp_parent);
        }
    }
}

void add(struct node * pq, int priority, int value)
{
    struct element * num = pq -> val;
    if(pq -> size >= pq -> capacity)
    {
        pq -> capacity = pq -> capacity * 2;
        pq -> val = realloc(pq -> val, sizeof(struct element)*(pq -> capacity));
    }
    pq -> size++;
    int n = pq -> size - 1;
    num[n].priority = priority;
    num[n].value = value;
    add_heap(pq, n);
}

void heapify(struct node * pq, int i)
{
    int largest = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;
    if(left < pq -> size && (pq -> val)[left].priority > (pq -> val)[largest].priority)
    {
        largest = left;
    }

    if(right < pq -> size && (pq -> val)[right].priority > (pq -> val)[largest].priority)
    {
        largest = right;
    }
    if(largest != i)
    {
        swap(&(pq -> val)[i].priority, &(pq -> val)[largest].priority);
        swap(&(pq -> val)[i].value, &(pq -> val)[largest].value);
        heapify(pq, largest);
    }
}

void build_heaps(struct node * pq)
{
    struct element * num = pq -> val;
    for(int i = (pq -> size)/2 - 1; i >= 0; i--)
    {
        heapify(pq, i);
    }
}

void print_heap(struct node * pq)
{
    struct element * num = pq -> val;
    for(int i = 0; i < pq -> size; i++)
    {
        printf("priority: ");
        printf("%d", num[i].priority);
        printf(", value: ");
        printf("%d\n", num[i].value);
    }
}

int peek(struct node * pq)
{
    struct element * num = pq -> val;
    return num[0].value;
}

void remove_highest_priority(struct node * pq)
{
    struct element * num = pq -> val;
    int n = pq -> size - 1;
    num[0].priority = num[n].priority;
    num[0].value = num[n].value;
    pq -> size--;
    heapify(pq, 0);
}