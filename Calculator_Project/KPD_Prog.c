/*
 * KPD_Prog.c
 *
 *  Created on: Aug 13, 2024
 *      Author: user
 */


#include "Std_Types.h"
#include "Error_states.h"

#include "DIO_Interface.h"

#include "KPD_Config.h"
#include "KPD_Private.h"


u8 KPD_GET_PRESSED(void)
{

	u8 local_Pressedkey = KPD_NO_PRESSED_KEY;
	u8 local_Pin_State;
	u8 local_colom_Idx, local_row_Idx;


	static u8 local_KPD_Arr[ROW_NUM][COLOM_NUM] = KPD_ARR_VAL;
	static u8 local_ARR_Coloms_Config[COLOM_NUM][2] = {{KPD_COLOM0_PORT, KPD_COLOM0_PIN},
												{KPD_COLOM1_PORT, KPD_COLOM1_PIN},
												{KPD_COLOM2_PORT, KPD_COLOM2_PIN},
												{KPD_COLOM3_PORT, KPD_COLOM3_PIN}};

	static u8 local_Rows_Config[ROW_NUM][2] = 		   {{KPD_ROW0_PORT, KPD_ROW0_PIN},
									   	   	   {KPD_ROW1_PORT, KPD_ROW1_PIN},
											   {KPD_ROW2_PORT, KPD_ROW2_PIN},
											   {KPD_ROW3_PORT, KPD_ROW3_PIN}};



	for(local_colom_Idx = 0; local_colom_Idx < COLOM_NUM; local_colom_Idx++)
	{

		DIO_enu_Set_Pin_Value(local_ARR_Coloms_Config[local_colom_Idx][SET_PORT_NUM], local_ARR_Coloms_Config[local_colom_Idx][SET_PIN_NUM], LOW);

		for(local_row_Idx = 0; local_row_Idx < ROW_NUM; local_row_Idx++)
		{
			DIO_enu_Get_Pin_Value(local_Rows_Config[local_row_Idx][SET_PORT_NUM], local_Rows_Config[local_row_Idx][SET_PIN_NUM], &local_Pin_State);

			if(local_Pin_State == LOW)
			{

				local_Pressedkey = local_KPD_Arr[local_row_Idx][local_colom_Idx];

				while(local_Pin_State == LOW)
				{
					DIO_enu_Get_Pin_Value(local_Rows_Config[local_row_Idx][SET_PORT_NUM], local_Rows_Config[local_row_Idx][SET_PIN_NUM], &local_Pin_State);

				}
				return local_Pressedkey;
			}
		}

		DIO_enu_Set_Pin_Value(local_ARR_Coloms_Config[local_colom_Idx][SET_PORT_NUM], local_ARR_Coloms_Config[local_colom_Idx][SET_PIN_NUM], HIGH);

	}


	return local_Pressedkey;
}
