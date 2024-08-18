/*
 * main.c
 *
 *  Created on: Aug 11, 2024
 *      Author: user
 */

#include "Error_states.h"
#include "Std_Types.h"


#include "stack_char.h"
#include "stack_float.h"
#include "stack_int.h"

#include "needed_function.h"




#include "DIO_Interface.h"


#include "Lcd_Config.h"
#include "Lcd_Interface.h"
#include "KPD_Interface.h"
#include "KPD_Config.h"
#include "util/delay.h"

extern Stack s;
extern Stack_f pos_s;
extern Stack_i s2;



u8 num_pressed(u8 copy_keypressed);
void which_key_pressed(u8 copy_keypessed);



int main()
{
	CreatStack(&s);
	CreatStack_f(&pos_s);
	CreatStack_i(&s2);


	DIO_enu_Intiat();
	LCD_enu_intiat();



//LCD_enu_Display_char(53);

	u8 local_keypressed;
	char expression[100];
	u8 i = 0;

	while(1)
	{

		do
		{
			local_keypressed = KPD_GET_PRESSED();
		}while(local_keypressed == KPD_NO_PRESSED_KEY);


		which_key_pressed(local_keypressed);

		if(local_keypressed != 15)
		{
			switch (local_keypressed)
			{
			case 1: //7
				expression[i] = '7';
				i++;
				break;
			case 2: // 8
				expression[i] = '8';
				i++;
				break;
			case 3: // 9
				expression[i] = '9';
				i++;
				break;
			case 4: // /
				expression[i] = '/';
				i++;
				break;
			case 5: // 4
				expression[i] = '4';
				i++;
				break;
			case 6: // 5
				expression[i] = '5';
				i++;
				break;
			case 7: // 6
				expression[i] = '6';
				i++;
				break;
			case 8: // *
				expression[i] = '*';
				i++;
				break;
			case 9: // 1
				expression[i] = '1';
				i++;
				break;
			case 10: // 2
				expression[i] = '2';
				i++;
				break;
			case 11: // 3
				expression[i] = '3';
				i++;
				break;
			case 12: // -
				expression[i] = '-';
				i++;
				break;
			case 14: // 0
				expression[i] = '0';
				i++;
				break;
			case 16: // +
				expression[i] = '+';
				i++;
				break;
			}

		}
		else
		{
			expression[i] = '\0';
			LCD_enu_Send_command(0xc0);

			char * ptr = Post_exp(expression);
			float res = evaluate(ptr);
			if(res == .9999999)
			{
				LCD_enu_Display_char('E');
				LCD_enu_Display_char('R');
				LCD_enu_Display_char('R');
				LCD_enu_Display_char('O');
				LCD_enu_Display_char('R');
			}
			else if(res < 0)
			{
				LCD_enu_Display_char('-');
				int int_res = -res;
				int num_1 = int_res;

				int popped;
				while (num_1 != 0) {
					push_i((num_1 % 10), &s2);
					num_1 /= 10;
				}

				while (!StackEmpty_i(&s2))
				{
					LCD_enu_Display_char(num_pressed(gettop_i(&s2)));
					pop_i(&popped, &s2);
				}

				LCD_enu_Display_char('.');
				float int_res_2 = -(res - (-int_res));
				int num = int_res_2 * 10;
				LCD_enu_Display_char(num_pressed(num));
			}
			else
			{

				int int_res = res;
				int num_1 = int_res;
				if(res == 0)
					LCD_enu_Display_char('0');
				if(res > 0 && res < 1)
				{
					LCD_enu_Display_char('0');
				}
				int popped;

				while (num_1 != 0)
				{
					push_i((num_1 % 10), &s2);
					num_1 /= 10;
				}

				while (!StackEmpty_i(&s2))
				{
					LCD_enu_Display_char(num_pressed(gettop_i(&s2)));
					pop_i(&popped, &s2);
				}

				LCD_enu_Display_char('.');
				float int_res_2 = res - int_res;
				int num = int_res_2 * 10;
				LCD_enu_Display_char(num_pressed(num));
			}
		}

		if(local_keypressed == 13)
		{
			LCD_enu_Send_command(0x01);
			i = 0;
			for(int i = 0; i < 100; i++)
			{
				expression[i] = 0;
			}
		}


	}

	return 0;

}




u8 num_pressed(u8 copy_keypressed)
{
	u8 var;
	switch(copy_keypressed)
	{
	case 0:

		var = 48;
		break;
	case 1:
		var = 49;
		break;
	case 2:
		var = 50;
		break;
	case 3:
		var = 51;
		break;
	case 4:
		var = 52;
		break;
	case 5:
		var = 53;
		break;
	case 6:
		var = 54;
		break;
	case 7:
		var = 55;
		break;
	case 8:
		var = 56;
		break;
	case 9:
		var = 57;
		break;
	}

	return var;
}



void which_key_pressed(u8 copy_keypessed)
{


	switch (copy_keypessed)
	{
	case 1: //7
		LCD_enu_Display_char(55);
		break;
	case 2: // 8
		LCD_enu_Display_char(56);
		break;
	case 3: // 9
		LCD_enu_Display_char(57);
		break;
	case 4: // /
		LCD_enu_Display_char(47);
		break;
	case 5: // 4
		LCD_enu_Display_char(52);
		break;
	case 6: // 5
		LCD_enu_Display_char(53);
		break;
	case 7: // 6
		LCD_enu_Display_char(54);
		break;
	case 8: // *
		LCD_enu_Display_char(42);
		break;
	case 9: // 1
		LCD_enu_Display_char(49);
		break;
	case 10: // 2
		LCD_enu_Display_char(50);
		break;
	case 11: // 3
		LCD_enu_Display_char(51);
		break;
	case 12: // -
		LCD_enu_Display_char(45);
		break;
	case 14: // 0
		LCD_enu_Display_char(48);
		break;
	case 15: // =
		LCD_enu_Display_char(61);
		break;
	case 16: // +
		LCD_enu_Display_char(43);
		break;
	}

}

