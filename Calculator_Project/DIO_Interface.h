#ifndef _INTERFACE_H_
#define _INTERFACE_H_


#define DIO_PORTA   	0
#define DIO_PORTB   	1
#define DIO_PORTC		2
#define DIO_PORTD		3

#define DIO_PIN0		0
#define DIO_PIN1		1
#define DIO_PIN2		2
#define DIO_PIN3		3
#define DIO_PIN4		4
#define DIO_PIN5		5
#define DIO_PIN6		6
#define DIO_PIN7		7


#define INPUT			0
#define OUTPUT			1
#define LOW				0
#define HIGH			1
#define PULL_UP			1
#define FLOAT			0








ES_t DIO_enu_Intiat(void);
ES_t DIO_enu_Set_Port_Dir(u8 Copy_Port_id, u8 Copy_value);
ES_t DIO_enu_Set_Port_Value(u8 Copy_Port_id, u8 Copy_value);
ES_t DIO_enu_Tog_Port_Value(u8 Copy_Port_id);
ES_t DIO_enu_Get_Port_Value(u8 Copy_Port_id, u8 * Copy_value);

ES_t DIO_enu_Set_Pin_Dir(u8 Copy_Port_id, u8 Copy_Pin_id, u8 Copy_value);
ES_t DIO_enu_Set_Pin_Value(u8 Copy_Port_id, u8 Copy_Pin_id, u8 Copy_value);
ES_t DIO_enu_Tog_Pin_Value(u8 Copy_Port_id, u8 Copy_Pin_id);
ES_t DIO_enu_Get_Pin_Value(u8 Copy_Port_id, u8 Copy_Pin_id, u8 * Copy_value);




#endif
