/*
 * stack_float.h
 *
 *  Created on: Aug 15, 2024
 *      Author: user
 */

#ifndef STACK_FLOAT_H_
#define STACK_FLOAT_H_


#define type_f float


typedef struct stacknode_f
{
    type_f data;
    struct stacknode *next;

}StackNode_f;


typedef struct stack_f
{
    StackNode_f *top;
    int size;
}Stack_f;

void CreatStack_f(Stack_f *ps);
void push_f(type_f item, Stack_f *ps);
void pop_f(type_f *pe, Stack_f *ps);
int StackFull_f(Stack_f *ps /*is not necessary*/);
int StackEmpty_f(Stack_f *ps);
void clear_f(Stack_f *ps);
type_f gettop_f(Stack_f *ps);
int getsize_f(Stack_f *ps);
void display_f(type_f element);
void Traverse_f(Stack_f *ps, void(*pf)(type_f));



#endif /* STACK_FLOAT_H_ */
