/* 
 * File:   LCD.h
 * Author: el msria
 *
 * Created on November 3, 2023, 2:52 AM
 */

#ifndef LCD_H
#define	LCD_H

#ifdef	__cplusplus
extern "C" {
#endif

//INCLUDES
#include "LCD_CFG.h"    
#include "../../MCAL_LAYER/GPIO/HAL_GPIO.h"
#include "C:\Program Files\Microchip\MPLABX\v6.15\packs\Microchip\PIC18Fxxxx_DFP\1.4.151\xc8\pic\include\builtins.h"
    
  
    
//MACROS
  #define LCD_CLEAR                  0x01
  #define LCD_RETURN_HOME            0x02
  #define LCD_ENTRY_MODE             0x06
  #define LCD_CURSOR_OFF_DISPLAY_ON  0x0C
  #define LCD_CURSOR_OFF_DISPLAY_OFF 0x08
  #define LCD_BLINK_ON_CURSOR_ON     0x0F
  #define LCD_BLINK_OFF_CURSOR_ON    0x0E
  #define LCD_DISPLAY_RIGHT_SHIFT    0x1C
  #define LCD_DISPLAY_RIGHT_SHIFT    0x1C
  #define LCD_DISPLAY_LEFT_SHIFT     0x18
  #define LCD_8BIT_MODE_2_LINE       0x38
  #define LCD_4BIT_MODE_2_LINE       0x28
  #define LCD_CGRAM_START            0x40
  #define LCD_DDRAM_START            0x80

  #define _XTAL_FREQ 4000000UL 
    
    
    
    
//USRER_DEFINED_DATA_TYPES    
  typedef struct{
      pin_config data_pins[4] ;
      pin_config rs_pin ;
      pin_config enable_pin ;
  
  
  }lcd_4bit_t;
  
  typedef struct {
      pin_config data_pins[8] ;
      pin_config rs_pin ;
      pin_config enable_pin ;
  
  
  
  }lcd_8bit_t;
  
  
  
//FUNCTIONS DECLERATIONS
  Std_ReturnType lcd_4bit_init(const lcd_4bit_t *lcd1) ;
  Std_ReturnType lcd_8bit_init(const lcd_8bit_t *lcd1) ;
  
  Std_ReturnType lcd_4bit_send_command(const lcd_4bit_t *lcd1 ,uint8 command) ;
  Std_ReturnType lcd_8bit_send_command(const lcd_8bit_t *lcd1 ,uint8 command) ;
  
  Std_ReturnType lcd_4bit_send_char_data(const lcd_4bit_t *lcd1 , uint8 data ) ;
  Std_ReturnType lcd_8bit_send_char_data(const lcd_8bit_t *lcd1 , uint8 data ) ;
  
  Std_ReturnType lcd_4bit_send_data_pos(const lcd_4bit_t *lcd1 ,uint8 row , uint8 colom, uint8 data ) ;
  Std_ReturnType lcd_8bit_send_data_pos(const lcd_8bit_t *lcd1 ,uint8 row , uint8 colom, uint8 data ) ;
  
  Std_ReturnType lcd_4bit_send_string(const lcd_4bit_t *lcd1 , uint8 *str ) ;
  Std_ReturnType lcd_8bit_send_string(const lcd_8bit_t *lcd1 , uint8 *str ) ;

  Std_ReturnType lcd_4bit_send_string_pos(const lcd_4bit_t *lcd1 ,uint8 row , uint8 colom, uint8 *str ) ;
  Std_ReturnType lcd_8bit_send_string_pos(const lcd_8bit_t *lcd1 ,uint8 row , uint8 colom, uint8 *str ) ;
   
  Std_ReturnType lcd_4bit_send_custom_char(const lcd_4bit_t *lcd1 ,uint8 row , uint8 colom, uint8 custom_char[] , uint8 mem_pos) ;
  Std_ReturnType lcd_8bit_send_custom_char(const lcd_8bit_t *lcd1 ,uint8 row , uint8 colom, uint8 custom_char[] , uint8 mem_pos) ;

  
  void convert_byte_to_string(uint8 num ,uint8 *ptr1);
  void convert_short_to_string(uint16 num ,uint8 *ptr1);
  void convert_int_to_string(uint32 num ,uint8 *ptr1);
  


#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

