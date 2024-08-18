/*
 * needed_function.c
 *
 *  Created on: Aug 15, 2024
 *      Author: user
 */
//#include "stdio.h"


#include "stack_char.h"
#include "stack_float.h"
#include "stack_int.h"
#include "needed_function.h"
#include <ctype.h>
#include "Std_Types.h"


//#include "Lcd_Interface.h"



Stack s;
Stack_f pos_s;
Stack_i pos_s2;
Stack_i s2;







int priority(char op)
{
    if(op == '+' || op == '-')
    {
        return 1;
    }
    else if(op == '*' || op == '/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}


char * Post_exp(char exp [])
{

    char poped;
    static char return_exp[100];
    int j = 0;
    for(int i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == ' ')
        {
            continue;
        }
        else if(isdigit(exp[i]) || isalpha(exp[i]))
        {
        	while (isdigit(exp[i]))
        	{
        	   return_exp[j] = exp[i];
        	   j++;
        	   i++;
        	}
        	return_exp[j] = ' ';
        	j++;
        	i--;
        }
        else if(exp[i] == '(')
        {
            push(exp[i], &s);
        }
        else if(exp[i] == ')')
        {
            while(gettop(&s) != '(')
            {
                return_exp[j] = gettop(&s);
                pop(&poped, &s);
                j++;
            }
            pop(&poped, &s);
        }
        else
        {
            while(!StackEmpty(&s) && priority(exp[i]) <= priority(gettop(&s)))
            {
                return_exp[j] = gettop(&s);
                j++;
                return_exp[j] = ' ';
                j++;
                pop(&poped,&s);
            }
            push(exp[i], &s);
        }
    }
    while(!StackEmpty(&s))
    {
        return_exp[j] = gettop(&s);
        j++;
        return_exp[j] = ' ';
        j++;
        pop(&poped,&s);
    }
    return_exp[j] = '\0';

    //LCD_enu_Send_command(0xc0);
    /*for(int l = 0;  return_exp[l] != '\0'; l++)
    {
    	LCD_enu_Display_char(return_exp[l]);
    }*/
    return return_exp;
}





float evaluate(char * ptr_exp) // 35+2-
{

    float popped;
    char ch;
    float return_res;
    float op1;
    float op2;

    for(int i = 0; ptr_exp[i] != '\0'; i++)
    {
    	ch = ptr_exp[i];
        if(isdigit(ch))
        {
        	int num = 0;
        	while (ptr_exp[i] != ' ')
        	{
        	   num  = (num * 10) + (ptr_exp[i] - '0');
        	   i++;
        	}
        	i--;
            push_f(num, &pos_s);
      	   *((u8 *)0x43) = gettop_f(&pos_s);
      	   	//pop_f(&popped, &pos_s);
      	   	//push_f(num, &pos_s);
      	   	*((u8 *)0x53) = gettop_f(&pos_s);
        }
        else if(ptr_exp[i] == ' ')
        {
        	continue;
        }
        else
        {
            op2 = gettop_f(&pos_s);
            pop_f(&popped, &pos_s);
            op1 = gettop_f(&pos_s);
            pop_f(&popped, &pos_s);

            if(ch == '+')
            {
            	return_res = op1 + op2;
            }
            else if(ch == '-')
            {
            	return_res = op1 - op2;
            }
            else if(ch == '*')
            {
             	return_res = op1 * op2;
            }
            else if(ch == '/')
            {
            	if(op2 == 0)
            	{
            		return .9999999;
            		break;
            	}
             	return_res = op1 / op2;
            }
            push_f(return_res, &pos_s);

        }
    }


    return gettop_f(&pos_s);
}





/*
int math(int op1, int op2, char operator)
{
	u8 result;
    switch(operator)
    {
    case '+':
    	result =  op1 + op2;
    	break;
    case '-':
    	result =  op1 - op2;
    	break;
    case '*':
    	result =  op1 * op2;
    	break;
    case '/':
    	result =  op1 / op2;
    	break;
    default:
    	result = 3;
    	break;
    }
    return result;


}*/
