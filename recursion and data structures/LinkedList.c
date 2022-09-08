#include <stdio.h>
#include <stdlib.h> 
#include "LinkedList.h"

void push(struct node ** head, int data)
{
    struct node * toAdd = malloc(sizeof(struct node));
    toAdd->data = data;
    toAdd->next = *head;
    *head = toAdd;
}

void print(struct node ** head)
{
    struct node * cur = *head;
    while (cur != NULL)
    {
        printf("%d\n", cur->data);
        cur = cur->next;
    }
}

void remove_from_head(struct node ** head)
{
    struct node * temp_head;
    temp_head = * head;
    * head = (* head) -> next;
    free(temp_head);
}

void add_at_position_x(struct node ** head, int data, int pos) //check method with andrew
{
    struct node * insert_pos_1 =  malloc(sizeof(struct node));
    insert_pos_1 -> data = data;
    insert_pos_1 -> next = NULL;

    if(pos == 0)
    {
        insert_pos_1 -> next = *head;
        *head = insert_pos_1;
    }
    else
    {
        struct node * temp = *head;
        for(int i = -1; i < pos - 2; i++)
        {
            temp = temp -> next;
        }
        insert_pos_1 -> next = temp -> next;
        temp -> next = insert_pos_1;
    }
}

void remove_at_position_x(struct node ** head, int x)
{
    if(x == 0){
        remove_from_head(head);
    }
    else{
        remove_at_position_x(&((**head).next), x-1);
    }
}

int get_data_at_position_x(struct node ** head, int x)
{
    struct node * current = *head;

    int count = 0;
    while(current != NULL) 
    {
        if(count == x)
            //printf("%d\n", current->data); check with andrew
            return (current->data);
        count++;
        current = current->next;
    }
}

int sum_data(struct node ** head)
{
    struct node * current = *head;

    int sum = 0;
    while(current != NULL)
    {
        int data_at_index = current -> data;
        sum += data_at_index;
        current = current -> next;
    }
    //printf("%d\n", sum); check with andrew
    return sum;
}

int get_min(struct node ** head)
{
    struct node * current = *head;

    int min = current -> data;
    while(current != NULL)
    {
        int data_at_index = current -> data;
        if(data_at_index < min)
        {
            min = data_at_index;
        }
        current = current -> next;
    }
    //printf("%d\n", min); check with andrew
    return min;
}

int get_max(struct node ** head)
{
    struct node * current = *head;

    int max = current -> data;
    while(current != NULL)
    {
        int data_at_index = current -> data;
        if(data_at_index > max)
        {
            max = data_at_index;
        }
        current = current -> next;
    }
    //printf("%d\n", max); check with andrew
    return max;
}

void reverse(struct node ** head)
{
    struct node * previous = NULL;
    struct node * current = *head;
    struct node * next = NULL;
    while(current != NULL)
    {
        next = current -> next;
        current -> next = previous;
        previous = current;
        current = next;
    }
    *head = previous;
}

void destroy(struct node ** head)
{
    struct node * current = *head;
    struct node * next;

    while(current != NULL)
    {
        next = current -> next;
        free(current);
        current = next;
    }
    *head = NULL;
}