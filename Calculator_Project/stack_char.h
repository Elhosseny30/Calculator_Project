/*
 * stack_char.h
 *
 *  Created on: Aug 15, 2024
 *      Author: user
 */

#ifndef STACK_CHAR_H_
#define STACK_CHAR_H_


#define type char


typedef struct stacknode
{
    type data;
    struct stacknode *next;

}StackNode;


typedef struct stack
{
    StackNode *top;
    int size;
}Stack;

void CreatStack(Stack *ps);
void push(type item, Stack *ps);
void pop(type *pe, Stack *ps);
int StackFull(Stack *ps /*is not necessary*/);
int StackEmpty(Stack *ps);
void clear(Stack *ps);
type gettop(Stack *ps);
int getsize(Stack *ps);
void display(type element);
void Traverse(Stack *ps, void(*pf)(type));


#endif /* STACK_CHAR_H_ */
