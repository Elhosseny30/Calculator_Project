/*
 * Lcd_Prog.c
 *
 *  Created on: Aug 11, 2024
 *      Author: user
 */


#include "Std_Types.h"
#include "Error_states.h"
#include "DIO_Interface.h"

#include "Lcd_Private.h"
#include "Lcd_Config.h"

#include "util/delay.h"


ES_t LCD_enu_intiat(void)
{
	ES_t local_error_state = ES_NOK;

	_delay_ms(35);

	DIO_enu_Set_Pin_Dir(RS_PORT, RS_PIN, OUTPUT);
	DIO_enu_Set_Pin_Dir(RW_PORT, RW_PIN, OUTPUT);
	DIO_enu_Set_Pin_Dir(EN_PORT, EN_PIN, OUTPUT);



	DIO_enu_Set_Pin_Dir(D7_PORT, D7_PIN, OUTPUT);
	DIO_enu_Set_Pin_Dir(D6_PORT, D6_PIN, OUTPUT);
	DIO_enu_Set_Pin_Dir(D5_PORT, D5_PIN, OUTPUT);
	DIO_enu_Set_Pin_Dir(D4_PORT, D4_PIN, OUTPUT);

#if LCD_MODE == EGIHT_BIT
	DIO_enu_Set_Pin_Dir(D3_PORT, D3_PIN, OUTPUT);
	DIO_enu_Set_Pin_Dir(D2_PORT, D2_PIN, OUTPUT);
	DIO_enu_Set_Pin_Dir(D1_PORT, D1_PIN, OUTPUT);
	DIO_enu_Set_Pin_Dir(D0_PORT, D0_PIN, OUTPUT);

	LCD_Send_Command(0x38);
#elif LCD_MODE == FOUR_BIT
	LCD_Send_Command(0x28);

#endif
	_delay_ms(1);
	LCD_Send_Command(0x0f);
	_delay_ms(1);
	LCD_Send_Command(0x01);
	_delay_ms(2);
	LCD_Send_Command(0x06);

	return local_error_state;

}





ES_t LCD_enu_Display_char(u8 Copy_data)
{
	ES_t local_error_state = ES_NOK;


	DIO_enu_Set_Pin_Value(RS_PORT, RS_PIN, HIGH);

	lcd_latch(Copy_data);


	return local_error_state;

}




ES_t LCD_enu_Send_command(u8 Copy_command)
{
	ES_t local_error_state = ES_NOK;

	// set rs selection	command
	DIO_enu_Set_Pin_Value(RS_PORT, RS_PIN, LOW);

	lcd_latch(Copy_command);
	return local_error_state;

}


static void lcd_latch(u8 copy_data)
{
	// set rw as write operation
		DIO_enu_Set_Pin_Value(RW_PORT, RW_PIN, LOW);
		DIO_enu_Set_Pin_Value(EN_PORT, EN_PIN, LOW);


		DIO_enu_Set_Pin_Value(D7_PORT, D7_PIN,((copy_data >> 7) & 1));
		DIO_enu_Set_Pin_Value(D6_PORT, D6_PIN,((copy_data >> 6) & 1));
		DIO_enu_Set_Pin_Value(D5_PORT, D5_PIN,((copy_data >> 5) & 1));
		DIO_enu_Set_Pin_Value(D4_PORT, D4_PIN,((copy_data >> 4) & 1));
		DIO_enu_Set_Pin_Value(D3_PORT, D3_PIN,((copy_data >> 3) & 1));
		DIO_enu_Set_Pin_Value(D2_PORT, D2_PIN,((copy_data >> 2) & 1));
		DIO_enu_Set_Pin_Value(D1_PORT, D1_PIN,((copy_data >> 1) & 1));
		DIO_enu_Set_Pin_Value(D0_PORT, D0_PIN,((copy_data >> 0) & 1));


		DIO_enu_Set_Pin_Value(EN_PORT, EN_PIN, HIGH);
		_delay_ms(10);
		DIO_enu_Set_Pin_Value(EN_PORT, EN_PIN, LOW);
}




static inline void LCD_Send_Command(u8 Copy_command)
{
		// set rs selection	command
		DIO_enu_Set_Pin_Value(RS_PORT, RS_PIN, LOW);

		// set rw as write operation
		DIO_enu_Set_Pin_Value(RW_PORT, RW_PIN, LOW);
		DIO_enu_Set_Pin_Value(EN_PORT, EN_PIN, LOW);


		DIO_enu_Set_Pin_Value(D7_PORT, D7_PIN,((Copy_command >> 7) & 1));
		DIO_enu_Set_Pin_Value(D6_PORT, D6_PIN,((Copy_command >> 6) & 1));
		DIO_enu_Set_Pin_Value(D5_PORT, D5_PIN,((Copy_command >> 5) & 1));
		DIO_enu_Set_Pin_Value(D4_PORT, D4_PIN,((Copy_command >> 4) & 1));
		DIO_enu_Set_Pin_Value(D3_PORT, D3_PIN,((Copy_command >> 3) & 1));
		DIO_enu_Set_Pin_Value(D2_PORT, D2_PIN,((Copy_command >> 2) & 1));
		DIO_enu_Set_Pin_Value(D1_PORT, D1_PIN,((Copy_command >> 1) & 1));
		DIO_enu_Set_Pin_Value(D0_PORT, D0_PIN,((Copy_command >> 0) & 1));


		DIO_enu_Set_Pin_Value(EN_PORT, EN_PIN, HIGH);
		_delay_ms(10);
		DIO_enu_Set_Pin_Value(EN_PORT, EN_PIN, LOW);
}



