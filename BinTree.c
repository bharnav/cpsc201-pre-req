#include <stdio.h>
#include <stdlib.h> 
#include "BinTree.h"


void add(struct node ** proot, int key, int data)
{
    if (*proot == 0)
    {
        *proot = malloc(sizeof(struct node));
        (*proot)->key = key;
        (*proot)->data = data;
        (*proot)->left = 0;
        (*proot)->right = 0;
    }
    else
    {
        if (key > (*proot)->key)
        {
            add(&((*proot)->right), key, data);
        }
        else 
        {
            add(&((*proot)->left), key, data);
        }
    }
}

void printInOrder(struct node ** proot)
{
    if (*proot != 0)
    {
        printInOrder(&((*proot)->left));
        printf("%d: %d\n", (*proot)->key, (*proot)->data);
        printInOrder(&((*proot)->right));
    }
}

int search(struct node ** proot, int key)
{
    if((*proot) == NULL)
    {
        return 0;
    }
    else
    {
        if((*proot) -> key == key)
        {
            return 1;
        }
        else
        {
            if((*proot) -> key < key)
            {
                if((*proot) -> right == NULL)
                {
                    return 0;
                }
                else
                {
                    return search(&((*proot) -> right), key);
                }
            }
            else
            {
                if((*proot) -> left == NULL)
                {
                    return 0;
                }
                else
                {
                    return search(&((*proot) -> left), key);
                }
            }
        }
    }
}

int find_value(struct node ** proot, int key)
{
    if((*proot) == NULL)
    {
        return 0;
    }
    else
    {
        if((*proot) -> key == key)
        {
            return((*proot) -> data);
        }
        else
        {
            if((*proot) -> key > key)
            {
                if((*proot) -> left == NULL)
                {
                    return 0;
                }
                else
                {
                    return find_value(&((*proot) -> left), key);
                }
            }
            else
            {
                if((*proot) -> right == NULL)
                {
                    return 0;
                }
                else
                {
                    return find_value(&((*proot) -> right), key);
                }
            }
        }
    }
}

void remove_from_tree(struct node ** phead, int key)
{
    if(key < (*phead) -> key)
    {
        remove_from_tree(&((*phead) -> left), key);
    }
    else if(key > (*phead) -> key)
    {
        remove_from_tree(&((*phead) -> right), key);
    }
    else
    {
        if((*phead) -> left == 0 && (*phead) -> right == 0)
        {
            free(*phead);
            *phead = 0;
        }
        else if((*phead) -> left == NULL)
        {
            struct node * temp = (*phead) -> right;
            free (*phead);
            *phead = temp;
        }
        else if((*phead) -> right == NULL)
        {
            struct node * temp = (*phead) -> left;
            free(*phead);
            *phead = temp;
        }
        else
        {
            struct node ** curr = phead;
            curr = &((*curr) -> left);
            while((*curr) -> right != NULL)
            {
                curr = &((*curr) -> right);
            }
            struct node * temp = (*curr) -> left;
            (*phead) -> key = (*curr) -> key;
            (*phead) -> data = (*curr) -> data;
            free(*curr);
            *curr = temp;
        }
    }
}

void change_value(struct node ** proot, int key, int data)
{
    if((*proot) -> key == key)
    {
        (*proot) -> data = data;
    }
    else if((*proot) -> key > key && (*proot) -> left != NULL)
    {
        change_value(&((*proot) -> left), key, data);
    }
    else if((*proot) -> right != NULL)
    {
        change_value(&((*proot) -> right), key, data);
    }
}

void destroy(struct node ** proot)
{
    if((*proot) -> right != NULL)
    {
        destroy(&((*proot) -> right));
    }
    if((*proot) -> left != NULL)
    {
        destroy(&((*proot) -> left));
    }
    free(*proot);
    (*proot) = NULL;
}