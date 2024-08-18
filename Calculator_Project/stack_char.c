/*
 * stack_char.c
 *
 *  Created on: Aug 15, 2024
 *      Author: user
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Std_Types.h"
#include "stack_char.h"






void CreatStack(Stack *ps)
{
    ps->top = NULL;
    ps->size = 0;
}

void push(type item, Stack *ps)
{
    StackNode *pn = (StackNode *)malloc(sizeof(StackNode));
    pn->data = item;
    pn->next = ps->top;
    ps->top = pn;
    ps->size++;
}

void pop(type *pe, Stack *ps)
{
    StackNode *pn = ps->top;
    *pe = pn->data;
    ps->top = ps->top->next;
    free(pn);
    ps->size--;
}

int StackFull(Stack *ps /*is not necessary*/)
{
    return 0;
}

int StackEmpty(Stack *ps)
{
    return !ps->size;
}

void clear(Stack *ps)
{
    StackNode *pn = ps->top;
    while(pn)
    {
        ps->top = ps->top->next;
        free(pn);
        pn = ps->top;
    }
    ps->size = 0;
}

type gettop(Stack *ps)
{
    return ps->top->data;
}

int getsize(Stack *ps)
{
    return ps->size;
}

void display(type element)
{
    printf("item : %c\n", element);
}

void Traverse(Stack *ps, void(*pf)(type))
{
    StackNode *pn = ps->top;
    while(pn)
    {
        (*pf)(pn->data);
        pn = pn->next;
    }
}



