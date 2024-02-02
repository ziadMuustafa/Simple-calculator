#include "LCD.h"
#include <stdio.h>
#include <string.h>

Std_ReturnType ret = E_OK ;
//////////////////////////////////////////////////////////////////////////////
static Std_ReturnType lcd_send_4_bits(lcd_4bit_t *lcd1 ,uint8 data_command) ;     // STATIC FUNCTION
static Std_ReturnType lcd_send_4_bits_enable(lcd_4bit_t *lcd1) ;
//////////////////////////////////////////////////////////////////////////////
  Std_ReturnType lcd_8bit_init(const lcd_8bit_t *lcd1){
  if(NULL == lcd1 ){ret == E_NOT_OK ;}
      
      else{
          for(int i =0 ;i<8 ; i++){ret = gpio_pin_init(&(lcd1->data_pins[i])) ;}
         ret = gpio_pin_init(&(lcd1->rs_pin)) ;
         ret = gpio_pin_init(&(lcd1->enable_pin)) ;    
           
         __delay_ms(20);
         lcd_8bit_send_command(lcd1, LCD_8BIT_MODE_2_LINE) ;
         __delay_ms(5);
         lcd_8bit_send_command(lcd1, LCD_8BIT_MODE_2_LINE) ;
         __delay_us(150);
         lcd_8bit_send_command(lcd1, LCD_8BIT_MODE_2_LINE) ;
         lcd_8bit_send_command(lcd1, LCD_CLEAR) ;
         lcd_8bit_send_command(lcd1, LCD_RETURN_HOME) ;
         lcd_8bit_send_command(lcd1, LCD_ENTRY_MODE) ;
         lcd_8bit_send_command(lcd1, LCD_CURSOR_OFF_DISPLAY_ON) ;
         lcd_8bit_send_command(lcd1, LCD_8BIT_MODE_2_LINE) ;
         lcd_8bit_send_command(lcd1, 0x80) ;

                  
         
      }
      return ret  ;
  };
  ////////////////////////////////////////////////////////////////////////////////////
  Std_ReturnType lcd_8bit_send_command(const lcd_8bit_t *lcd1 ,uint8 command){
   if(NULL == lcd1){ret = E_NOT_OK ;}
         else{
         ret = gpio_pin_write_logic(&(lcd1->rs_pin), LOW) ;
         for(int i =0 ;i< 8 ;i++){gpio_pin_write_logic(&(lcd1->data_pins[i]) ,command%2) ;command= command/2;}
          
      }
            ret = gpio_pin_write_logic(&(lcd1->enable_pin) , HIGH) ;
            __delay_us(6) ;
            ret = gpio_pin_write_logic(&(lcd1->enable_pin) , LOW) ;
            __delay_us(6) ;
        
   
   return ret ; 
 
  }; 
  //////////////////////////////////////////////////////////////////////////////////////
  Std_ReturnType lcd_8bit_send_char_data(const lcd_8bit_t *lcd1 , uint8 data ){
  
  if(NULL == lcd1){ret = E_NOT_OK ;}
         else{
         ret = gpio_pin_write_logic(&(lcd1->rs_pin), HIGH ) ;
         for(int i =0 ;i< 8 ;i++){gpio_pin_write_logic(&(lcd1->data_pins[i]) ,data%2) ;data= data/2;}
     
      }
            ret = gpio_pin_write_logic(&(lcd1->enable_pin) , HIGH) ;
            __delay_us(6) ;
            ret = gpio_pin_write_logic(&(lcd1->enable_pin) , LOW) ;
            __delay_us(6) ;
  };
  ///////////////////////////////////////////////////////////////////////////////////////
  Std_ReturnType lcd_8bit_send_data_pos(const lcd_8bit_t *lcd1 ,uint8 row , uint8 colom, uint8 data ){
  
      if(NULL == lcd1){ret = E_NOT_OK ;}
      else{
          colom-- ;
          switch(row){
              case 1 : lcd_8bit_send_command(lcd1, 0x80 + colom) ; break ;
              case 2 : lcd_8bit_send_command(lcd1, 0xc0 + colom) ; break ;
              case 3 : lcd_8bit_send_command(lcd1, 0x94 + colom) ; break ;
              case 4 : lcd_8bit_send_command(lcd1, 0xd4 + colom) ; break ;                    
          }
          lcd_8bit_send_char_data(lcd1 , data) ;
      
      }
      
  };
  //////////////////////////////////////////////////////////////////////////////
  Std_ReturnType lcd_8bit_send_string(const lcd_8bit_t *lcd1 , uint8 *str ){
  
       if(NULL == lcd1 & NULL == str){ret = E_NOT_OK ;}
      else{
          for(int i=0 ; i<strlen(str) ;i++){
              lcd_8bit_send_char_data(lcd1,str[i]) ;
          }
      
      
      }
  
  }; 
  //////////////////////////////////////////////////////////////////////////////
  Std_ReturnType lcd_8bit_send_string_pos(const lcd_8bit_t *lcd1 ,uint8 row , uint8 colom, uint8 *str ){
      if(NULL == lcd1){ret = E_NOT_OK ;}
      else{
       colom-- ;
          switch(row){
              case 1 : lcd_8bit_send_command(lcd1, 0x80 + colom) ; break ;
              case 2 : lcd_8bit_send_command(lcd1, 0xc0 + colom) ; break ;
              case 3 : lcd_8bit_send_command(lcd1, 0x94 + colom) ; break ;
              case 4 : lcd_8bit_send_command(lcd1, 0xd4 + colom) ; break ;                    
          }
      
          lcd_8bit_send_string(lcd1, str) ;
      
      
      
      }
  
  
  };
  ////////////////////////////////////////////////////////////////////////////// 
  Std_ReturnType lcd_8bit_send_custom_char(const lcd_8bit_t *lcd1 ,uint8 row , uint8 colom, uint8 custom_char[] , uint8 mem_pos){
  
  Std_ReturnType ret = E_OK;
    uint8 lcd_counter = 0;
    if(NULL == lcd1){
        ret = E_NOT_OK;
    }
    else{    
        ret = lcd_8bit_send_command(lcd1, (LCD_CGRAM_START+(mem_pos*8)));
        for(lcd_counter=0; lcd_counter<=7; ++lcd_counter){
            ret = lcd_8bit_send_char_data(lcd1, custom_char[lcd_counter]);
        }
        ret = lcd_8bit_send_data_pos(lcd1, row, colom, mem_pos);
    }
    return ret;

  
  
  
  };
  ////////////////////////////////////////////////////////////////////////////// 

  
  // 4bit lcd functions // 
  
 ////////////////////////////////////////////////////////////////////////////////
 ////////////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////////// 
 
  
  
  
  
 // //  // // // // // // // // // // // // // // // // // // // // // // // //  
  Std_ReturnType lcd_4bit_init(const lcd_4bit_t *lcd1){
      if(NULL == lcd1 ){ret == E_NOT_OK ;}
      
      else{
         ret = gpio_pin_init(&(lcd1->enable_pin)) ;
         ret = gpio_pin_init(&(lcd1->rs_pin)) ;              
         for(int i =0 ;i<4 ; i++){ret = gpio_pin_init(&(lcd1->data_pins[i])) ;}
         __delay_ms(20);
         lcd_4bit_send_command(lcd1, LCD_4BIT_MODE_2_LINE) ;
         
         lcd_4bit_send_command(lcd1, LCD_4BIT_MODE_2_LINE) ;
         __delay_us(150);
         lcd_4bit_send_command(lcd1, LCD_8BIT_MODE_2_LINE) ;
         lcd_4bit_send_command(lcd1, LCD_CLEAR) ;
         lcd_4bit_send_command(lcd1, LCD_RETURN_HOME) ;
         lcd_4bit_send_command(lcd1, LCD_ENTRY_MODE) ;
         lcd_4bit_send_command(lcd1, LCD_CURSOR_OFF_DISPLAY_ON) ;
         lcd_4bit_send_command(lcd1, LCD_8BIT_MODE_2_LINE) ;
         lcd_4bit_send_command(lcd1, 0x80) ;   
      }
      return ret  ;
  };
 // //  // // // // // // // // // // // // // // // // // // // // // // // // 
 Std_ReturnType lcd_4bit_send_command(const lcd_4bit_t *lcd1 ,uint8 command){
  
      if(lcd1 == NULL){ret = E_NOT_OK ;}
      else{
            ret = gpio_pin_write_logic(&(lcd1->rs_pin) , LOW) ;
            uint8 temp_command = command >> 4; 
         
          
          
            gpio_pin_write_logic(&(lcd1->data_pins[0]), (temp_command >> 0) & 0x01 );
            gpio_pin_write_logic(&(lcd1->data_pins[1]), (temp_command >> 1) & 0x01 );
            gpio_pin_write_logic(&(lcd1->data_pins[2]), (temp_command >> 2) & 0x01 );
            gpio_pin_write_logic(&(lcd1->data_pins[3]), (temp_command >> 3) & 0x01 );
       
            ret = gpio_pin_write_logic(&(lcd1->enable_pin) , HIGH) ;
            __delay_us(6) ;
            ret = gpio_pin_write_logic(&(lcd1->enable_pin) , LOW) ;
            __delay_us(6) ;
 
          
               
            gpio_pin_write_logic(&(lcd1->data_pins[0]), (command >> 0) & 0x01 );
            gpio_pin_write_logic(&(lcd1->data_pins[1]), (command >> 1) & 0x01 );
            gpio_pin_write_logic(&(lcd1->data_pins[2]), (command >> 2) & 0x01 );
            gpio_pin_write_logic(&(lcd1->data_pins[3]), (command >> 3) & 0x01 );
    
            ret = gpio_pin_write_logic(&(lcd1->enable_pin) , HIGH) ;
            __delay_us(6) ;
            ret = gpio_pin_write_logic(&(lcd1->enable_pin) , LOW) ;
            __delay_us(6) ;

            }
          
  };
  
   // //  // // // // // // // // // // // // // // // // // // // // // // // // 
  Std_ReturnType lcd_4bit_send_char_data(const lcd_4bit_t *lcd1 , uint8 data ){
  
      if(NULL == lcd1 ){ret = E_NOT_OK ;}
      else{
        ret = gpio_pin_write_logic(&(lcd1->rs_pin), HIGH) ;
      
       uint8 temp_data = data >> 4 ;
       for(int i =0 ; i< 4 ;i++){
           ret = gpio_pin_write_logic(&(lcd1->data_pins[i]), (temp_data >> i) & 0x01  );
       }
            ret = gpio_pin_write_logic(&(lcd1->enable_pin) , HIGH) ;
            __delay_ms(600) ;
            ret = gpio_pin_write_logic(&(lcd1->enable_pin) , LOW) ;
            __delay_ms(600) ;
            
            
       for(int i =0 ;i< 4 ;i++){gpio_pin_write_logic(&(lcd1->data_pins[i]),(data >> i) & 0x01) ; }     
            ret = gpio_pin_write_logic(&(lcd1->enable_pin) , HIGH) ;
            __delay_ms(600) ;
            ret = gpio_pin_write_logic(&(lcd1->enable_pin) , LOW) ;
            __delay_us(6) ;
      
      }
  };
  // //  // // // // // // // // // // // // // // // // // // // // // // // // // //
  Std_ReturnType lcd_4bit_send_data_pos(const lcd_4bit_t *lcd1 ,uint8 row , uint8 colom, uint8 data ){
  
  if(NULL == lcd1){ret = E_NOT_OK ;}
      else{
          colom-- ;
          switch(row){
              case 1 : lcd_8bit_send_command(lcd1, 0x80 + colom) ; break ;
              case 2 : lcd_8bit_send_command(lcd1, 0xc0 + colom) ; break ;
              case 3 : lcd_8bit_send_command(lcd1, 0x94 + colom) ; break ;
              case 4 : lcd_8bit_send_command(lcd1, 0xd4 + colom) ; break ;                    
          }
          lcd_4bit_send_char_data(lcd1 , data) ;
      
      }
  

   };
   // // // // // // // // // // // // // // // // // // // // // // // // // // // // 
  Std_ReturnType lcd_4bit_send_string(const lcd_4bit_t *lcd1 , uint8 *str ){
  
      if(NULL == lcd1 & NULL == str){ret = E_NOT_OK ;}
      else{
          for(int i=0 ; i<strlen(str) ;i++){
              lcd_4bit_send_char_data(lcd1,str[i]) ;
          }
      
      
      }
  
 
  };
   // //  // // // // // // // // // // // // // // // // // // // // // // // // 
  Std_ReturnType lcd_4bit_send_string_pos(const lcd_4bit_t *lcd1 ,uint8 row , uint8 colom, uint8 *str ){
      if(NULL == lcd1){ret = E_NOT_OK ;}
      else{
          colom-- ;
          switch(row){
              case 1 : lcd_8bit_send_command(lcd1, 0x80 + colom) ; break ;
              case 2 : lcd_8bit_send_command(lcd1, 0xc0 + colom) ; break ;
              case 3 : lcd_8bit_send_command(lcd1, 0x94 + colom) ; break ;
              case 4 : lcd_8bit_send_command(lcd1, 0xd4 + colom) ; break ;                    
          }
          lcd_4bit_send_string(lcd1 , str) ;
      
      }
      
      
      
  };
  // //  // // // // // // // // // // // // // // // // // // // // // // // // 
 Std_ReturnType lcd_4bit_send_custom_char(const lcd_4bit_t *lcd1 ,uint8 row , uint8 colom, uint8 custom_char[] , uint8 mem_pos){
  
  
  
  
  };
  //////////////////////////////////////////////////////////////////////////////









  //////////////////////////////////////////////////////////////////////////////  
static Std_ReturnType lcd_send_4_bits_enable(lcd_4bit_t *lcd1){
    
       
            ret = gpio_pin_write_logic(&(lcd1->enable_pin) , HIGH) ;
            __delay_ms(600) ;
            ret = gpio_pin_write_logic(&(lcd1->enable_pin) , LOW) ;
            __delay_ms(600) ;

        
       
        return ret ;
    
    } ;
static Std_ReturnType lcd_send_4_bits(lcd_4bit_t *lcd1 ,uint8 data_command){
        gpio_pin_write_logic(&(lcd1->data_pins[0]), 1);
    
    }    // STATIC FUNCTION
