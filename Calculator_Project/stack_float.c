/*
 * stack_float.c
 *
 *  Created on: Aug 15, 2024
 *      Author: user
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Std_Types.h"


#include "stack_float.h"



void CreatStack_f(Stack_f *ps)
{
    ps->top = NULL;
    ps->size = 0;
}

void push_f(type_f item, Stack_f *ps)
{
    StackNode_f *pn = (StackNode_f *)malloc(sizeof(StackNode_f));
    pn->data = item;
    pn->next = ps->top;
    ps->top = pn;
    ps->size++;
}

void pop_f(type_f *pe, Stack_f *ps)
{
    StackNode_f *pn = ps->top;
    *pe = pn->data;
    ps->top = ps->top->next;
    free(pn);
    ps->size--;
}

int StackFull_f(Stack_f *ps /*is not necessary*/)
{
    return 0;
}

int StackEmpty_f(Stack_f *ps)
{
    return !ps->size;
}

void clear_f(Stack_f *ps)
{
    StackNode_f *pn = ps->top;
    while(pn)
    {
        ps->top = ps->top->next;
        free(pn);
        pn = ps->top;
    }
    ps->size = 0;
}

type_f gettop_f(Stack_f *ps)
{
    return ps->top->data;
}

int getsize_f(Stack_f *ps)
{
    return ps->size;
}

void display_f(type_f element)
{
    printf("item : %0.1f\n", element);
}

void Traverse_f(Stack_f *ps, void(*pf)(type_f))
{
    StackNode_f *pn = ps->top;
    while(pn)
    {
        (*pf)(pn->data);
        pn = pn->next;
    }
}



