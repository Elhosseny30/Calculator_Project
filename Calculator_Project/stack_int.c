/*
 * stack_int.c
 *
 *  Created on: Aug 15, 2024
 *      Author: user
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Std_Types.h"


#include "stack_int.h"


void CreatStack_i(Stack_i *ps)
{
    ps->top = NULL;
    ps->size = 0;
}

void push_i(type_i item, Stack_i *ps)
{
    StackNode_i *pn = (StackNode_i *)malloc(sizeof(StackNode_i));
    pn->data = item;
    pn->next = ps->top;
    ps->top = pn;
    ps->size++;
}

void pop_i(type_i *pe, Stack_i *ps)
{
    StackNode_i *pn = ps->top;
    *pe = pn->data;
    ps->top = ps->top->next;
    free(pn);
    ps->size--;
}

int StackFull_i(Stack_i *ps /*is not necessary*/)
{
    return 0;
}

int StackEmpty_i(Stack_i *ps)
{
    return !ps->size;
}

void clear_i(Stack_i *ps)
{
    StackNode_i *pn = ps->top;
    while(pn)
    {
        ps->top = ps->top->next;
        free(pn);
        pn = ps->top;
    }
    ps->size = 0;
}

type_i gettop_i(Stack_i *ps)
{
    return ps->top->data;
}

int getsize_i(Stack_i *ps)
{
    return ps->size;
}

void display_i(type_i element)
{
    printf("item : %d\n", element);
}

void Traverse_i(Stack_i *ps, void(*pf)(type))
{
    StackNode_i *pn = ps->top;
    while(pn)
    {
        (*pf)(pn->data);
        pn = pn->next;
    }
}

