

#include "Error_states.h"
#include "Std_Types.h"
#include "DIO_Private.h"
#include "DIO_Config.h"


ES_t DIO_enu_Intiat(void)
{
	ES_t local_error_state = ES_NOK;
	DDRA = CONC(PA_PIN7_DIR,PA_PIN6_DIR,PA_PIN5_DIR,PA_PIN4_DIR,PA_PIN3_DIR,PA_PIN2_DIR,PA_PIN1_DIR,PA_PIN0_DIR);
	DDRB = CONC(PB_PIN7_DIR,PB_PIN6_DIR,PB_PIN5_DIR,PB_PIN4_DIR,PB_PIN3_DIR,PB_PIN2_DIR,PB_PIN1_DIR,PB_PIN0_DIR);
	DDRC = CONC(PC_PIN7_DIR,PC_PIN6_DIR,PC_PIN5_DIR,PC_PIN4_DIR,PC_PIN3_DIR,PC_PIN2_DIR,PC_PIN1_DIR,PC_PIN0_DIR);
	DDRD = CONC(PD_PIN7_DIR,PD_PIN6_DIR,PD_PIN5_DIR,PD_PIN4_DIR,PD_PIN3_DIR,PD_PIN2_DIR,PD_PIN1_DIR,PD_PIN0_DIR);

	PORTA = CONC(PA_PIN7_VALUE,PA_PIN6_VALUE,PA_PIN5_VALUE,PA_PIN4_VALUE,PA_PIN3_VALUE,PA_PIN2_VALUE,PA_PIN1_VALUE,PA_PIN0_VALUE);
	PORTB = CONC(PB_PIN7_VALUE,PB_PIN6_VALUE,PB_PIN5_VALUE,PB_PIN4_VALUE,PB_PIN3_VALUE,PB_PIN2_VALUE,PB_PIN1_VALUE,PB_PIN0_VALUE);
	PORTC = CONC(PC_PIN7_VALUE,PC_PIN6_VALUE,PC_PIN5_VALUE,PC_PIN4_VALUE,PC_PIN3_VALUE,PC_PIN2_VALUE,PC_PIN1_VALUE,PC_PIN0_VALUE);
	PORTA = CONC(PD_PIN7_VALUE,PD_PIN6_VALUE,PD_PIN5_VALUE,PD_PIN4_VALUE,PD_PIN3_VALUE,PD_PIN2_VALUE,PD_PIN1_VALUE,PD_PIN0_VALUE);

	local_error_state = ES_OK;
	return local_error_state;

}




ES_t DIO_enu_Set_Port_Dir(u8 Copy_Port_id, u8 Copy_value)
{
	ES_t local_error_state = ES_NOK;
	if(Copy_Port_id <= DIO_PORTD)
	{
		switch(Copy_Port_id)
		{
		case DIO_PORTA:
			DDRA = Copy_value;
			break;
		case DIO_PORTB:
			DDRB = Copy_value;
			break;
		case DIO_PORTC:
			DDRC = Copy_value;
			break;
		case DIO_PORTD:
			DDRD = Copy_value;
			break;
		}
		local_error_state = ES_OK;
	}
	else
	{
		local_error_state = OUT_OF_RANGE;
	}

	return local_error_state;
}



ES_t DIO_enu_Set_Port_Value(u8 Copy_Port_id, u8 Copy_value)
{
	ES_t local_error_state = ES_NOK;
	if (Copy_Port_id <= DIO_PORTD)
	{
		switch (Copy_Port_id)
		{
		case DIO_PORTA:
			PORTA = Copy_value;
			break;
		case DIO_PORTB:
			PORTB = Copy_value;
			break;
		case DIO_PORTC:
			PORTC = Copy_value;
			break;
		case DIO_PORTD:
			PORTD = Copy_value;
			break;
		}
		local_error_state = ES_OK;
	}
	else
	{
		local_error_state = OUT_OF_RANGE;
	}
	return local_error_state;
}





ES_t DIO_enu_Tog_Port_Value(u8 Copy_Port_id)
{
	ES_t local_error_state = ES_NOK;
	if (Copy_Port_id <= DIO_PORTD)
	{
		switch (Copy_Port_id)
		{
		case DIO_PORTA:
			PORTA = ~PORTA;
			break;
		case DIO_PORTB:
			PORTB = ~PORTB;
			break;
		case DIO_PORTC:
			PORTC = ~PORTC;
			break;
		case DIO_PORTD:
			PORTD = ~PORTD;
			break;
		}
		local_error_state = ES_OK;
	}
	else
	{
		local_error_state = OUT_OF_RANGE;
	}
	return local_error_state;
}



ES_t DIO_enu_Get_Port_Value(u8 Copy_Port_id, u8 * Copy_value)
 {
	ES_t local_error_state = ES_NOK;
	if(Copy_value != NULL)
	{
		if (Copy_Port_id <= DIO_PORTD)
		{
			switch (Copy_Port_id)
			{
			case DIO_PORTA:
				*Copy_value = PINA;
				break;
			case DIO_PORTB:
				*Copy_value = PINB;
				break;
			case DIO_PORTC:
				*Copy_value = PINC;
				break;
			case DIO_PORTD:
				*Copy_value = PIND;
				break;
			}
			local_error_state = ES_OK;
		}
		else
		{
			local_error_state = OUT_OF_RANGE;
		}
	}
	else
	{
		local_error_state = ES_NULL_POINTER;
	}
	return local_error_state;
}




ES_t DIO_enu_Set_Pin_Dir(u8 Copy_Port_id, u8 Copy_Pin_id, u8 Copy_value)
{
	ES_t local_error_state = ES_NOK;
	if((Copy_Port_id <= DIO_PORTD) && (Copy_Pin_id <= DIO_PIN7) && (Copy_value <= OUTPUT))
	{
		switch(Copy_Port_id)
		{
		case DIO_PORTA:
			DDRA &= ~(DIO_MASK_BIT << Copy_Pin_id);
			DDRA |= (Copy_value << Copy_Pin_id);
			break;
		case DIO_PORTB:
			DDRB &= ~(DIO_MASK_BIT << Copy_Pin_id);
			DDRB |= (Copy_value << Copy_Pin_id);
			break;
		case DIO_PORTC:
			DDRC &= ~(DIO_MASK_BIT << Copy_Pin_id);
			DDRC |= (Copy_value << Copy_Pin_id);
			break;
		case DIO_PORTD:
			DDRD &= ~(DIO_MASK_BIT << Copy_Pin_id);
			DDRD |= (Copy_value << Copy_Pin_id);
			break;
		}
		local_error_state = ES_OK;
	}
	else
	{
		local_error_state = OUT_OF_RANGE;
	}
	return local_error_state;
}


ES_t DIO_enu_Set_Pin_Value(u8 Copy_Port_id, u8 Copy_Pin_id, u8 Copy_value)
{
	ES_t local_error_state = ES_NOK;
	if((Copy_Port_id <= DIO_PORTD) && (Copy_Pin_id <= DIO_PIN7) && (Copy_value <= OUTPUT))
	{
		switch(Copy_Port_id)
		{
		case DIO_PORTA:
			PORTA &= ~(DIO_MASK_BIT << Copy_Pin_id);
			PORTA |= (Copy_value << Copy_Pin_id);
			break;
		case DIO_PORTB:
			PORTB &= ~(DIO_MASK_BIT << Copy_Pin_id);
			PORTB |= (Copy_value << Copy_Pin_id);
			break;
		case DIO_PORTC:
			PORTC &= ~(DIO_MASK_BIT << Copy_Pin_id);
			PORTC |= (Copy_value << Copy_Pin_id);
			break;
		case DIO_PORTD:
			PORTD &= ~(DIO_MASK_BIT << Copy_Pin_id);
			PORTD |= (Copy_value << Copy_Pin_id);
			break;
		}
		local_error_state = ES_OK;
	}
	else
	{
		local_error_state = OUT_OF_RANGE;
	}
	return local_error_state;

}
ES_t DIO_enu_Tog_Pin_Value(u8 Copy_Port_id, u8 Copy_Pin_id)
{

	ES_t local_error_state = ES_NOK;
	if((Copy_Port_id <= DIO_PORTD) && (Copy_Pin_id <= DIO_PIN7))
	{
		switch(Copy_Port_id)
		{
		case DIO_PORTA:
			PORTA ^= (DIO_MASK_BIT << Copy_Pin_id);
			break;
		case DIO_PORTB:
			PORTB ^= (DIO_MASK_BIT << Copy_Pin_id);
			break;
		case DIO_PORTC:
			PORTC ^= (DIO_MASK_BIT << Copy_Pin_id);
			break;
		case DIO_PORTD:
			PORTD ^= (DIO_MASK_BIT << Copy_Pin_id);
			break;
		}
		local_error_state = ES_OK;
	}
	else
	{
		local_error_state = OUT_OF_RANGE;
	}
	return local_error_state;

}




ES_t DIO_enu_Get_Pin_Value(u8 Copy_Port_id, u8 Copy_Pin_id, u8 * Copy_value)
{
	ES_t local_error_state = ES_NOK;
	if(Copy_value != NULL)
	{
		if((Copy_Port_id <= DIO_PORTD) && (Copy_Pin_id <= DIO_PIN7))
		{
			switch (Copy_Port_id)
			{
			case DIO_PORTA:
				*Copy_value = ((PINA >> Copy_Pin_id) & DIO_MASK_BIT);
				break;
			case DIO_PORTB:
				*Copy_value = ((PINB >> Copy_Pin_id) & DIO_MASK_BIT);
				break;
			case DIO_PORTC:
				*Copy_value = ((PINC >> Copy_Pin_id) & DIO_MASK_BIT);
				break;
			case DIO_PORTD:
				*Copy_value = ((PIND >> Copy_Pin_id) & DIO_MASK_BIT);
				break;
			}
			local_error_state = ES_OK;
		}
		else
		{
			local_error_state = OUT_OF_RANGE;
		}
	}
	else
	{
		local_error_state = ES_NULL_POINTER;
	}
	return local_error_state;
}
