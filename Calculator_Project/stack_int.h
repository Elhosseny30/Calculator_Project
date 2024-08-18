/*
 * stack_int.h
 *
 *  Created on: Aug 15, 2024
 *      Author: user
 */

#ifndef STACK_INT_H_
#define STACK_INT_H_

#include "Std_Types.h"

#define type_i int


typedef struct stacknode_i
{
    type_i data;
    struct stacknode *next;

}StackNode_i;


typedef struct stack_i
{
    StackNode_i *top;
    int size;
}Stack_i;

void CreatStack_i(Stack_i *ps);
void push_i(type_i item, Stack_i *ps);
void pop_i(type_i *pe, Stack_i *ps);
int StackFull_i(Stack_i *ps /*is not necessary*/);
int StackEmpty_i(Stack_i *ps);
void clear_i(Stack_i *ps);
type_i gettop_i(Stack_i *ps);
int getsize_i(Stack_i *ps);
void display_i(type_i element);
void Traverse_i(Stack_i *ps, void(*pf)(type));


#endif /* STACK_INT_H_ */
