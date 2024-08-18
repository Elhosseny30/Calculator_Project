/*
 * Lcd_Private.h
 *
 *  Created on: Aug 11, 2024
 *      Author: user
 */

#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_


#define EGIHT_BIT		5
#define FOUR_BIT		9

static inline void LCD_Send_Command(u8 Copy_command);

static void lcd_latch(u8 copy_data);




#endif /* LCD_PRIVATE_H_ */
