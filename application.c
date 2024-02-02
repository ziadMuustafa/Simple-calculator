/* 
 * File:   application.c
 * Author: el msria
 *
 * Created on December 25, 2023, 1:25 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include"application.h"
/*
 * 
 */




#define _XTAL_FREQ 4000000UL 
 char count = 99 ; int counter = 0 ;  char first_term_ones = '0';
 char first_term_tens = '0';
 char operation = '0';  char sec_term_ones  = '0';char sec_term_tens  = '0';
  int y = 0 ;
 char equality = '0' ; char result = '0' ; int error = 0 ; int check1 = 0 ; int check2 =0 ;
  
   

int main(){
   //IMPORTANT NOTE 
  //PUSH BUTTON NEED THE BOTH FUNCTION INIT AND READ STATE  
 
   

   k_pad_init(&k1) ;
   lcd_8bit_init(&lcd1);
  
 //   motor_move_left(&motor1);
   while(1){
      
    evaluate_operation() ;
     
   
   } 
    
    
    return (EXIT_SUCCESS); 
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void swich_operation(char operation){
switch(operation){
          
           
           case '+' :
             result = sum(first_term_ones , first_term_tens , sec_term_ones , sec_term_tens) ;
             if (((result)-'0')/10 == 0){lcd_8bit_send_char_data(&lcd1 , ((result)-'0')%10 + '0') ;} 
             else{ 
                 lcd_8bit_send_char_data(&lcd1 , ((result)-'0')/10 + '0') ;
                 lcd_8bit_send_char_data(&lcd1 , ((result)-'0')%10 + '0') ;  }          
                 ; __delay_ms(700);break ;
           
           
           
           case '-' :
             result = minus(first_term_ones , first_term_tens , sec_term_ones , sec_term_tens) ;
             if (((result)-'0')/10 == 0){lcd_8bit_send_char_data(&lcd1 , ((result)-'0')%10 + '0') ;} 
             else{
                 lcd_8bit_send_char_data(&lcd1 , ((result)-'0')/10 + '0') ;
                 lcd_8bit_send_char_data(&lcd1 , ((result)-'0')%10 + '0') ;  } 
                ; __delay_ms(700);break ;
           
           
           
           case '*' :
             result = multiply(first_term_ones , first_term_tens , sec_term_ones , sec_term_tens) ;
             if (((result)-'0')/10 == 0){lcd_8bit_send_char_data(&lcd1 , ((result)-'0')%10 + '0') ;} 
             else{ 
                 lcd_8bit_send_char_data(&lcd1 , ((result)-'0')/10 + '0') ;
                 lcd_8bit_send_char_data(&lcd1 , ((result)-'0')%10 + '0') ;  }
                ; __delay_ms(700);break ;
           
           
           
           case '/' :
             result = devide(first_term_ones , first_term_tens , sec_term_ones , sec_term_tens) ; 
             if (((result)-'0')/10 == 0){lcd_8bit_send_char_data(&lcd1 , ((result)-'0')%10 + '0') ;} 
             else{
                 lcd_8bit_send_char_data(&lcd1 , ((result)-'0')/10 + '0') ;
                 lcd_8bit_send_char_data(&lcd1 , ((result)-'0')%10 + '0') ;  }
                 ; __delay_ms(700);break ;  
           
           
           default :
            __delay_ms(500); lcd_8bit_send_command(&lcd1 , LCD_CLEAR) ; __delay_ms(500) ; 
             lcd_8bit_send_string(&lcd1 , "ERROR") ;  
             error = 1 ;__delay_ms(500);lcd_8bit_send_command(&lcd1 , LCD_CLEAR) ; break  ;
       
       
       }
       
       
       if(error != 1){
       lcd_8bit_send_command(&lcd1 , LCD_CLEAR); __delay_ms(500) ;
              lcd_8bit_send_string(&lcd1 ,"operation done");__delay_ms(500) ; 
              lcd_8bit_send_command(&lcd1 , LCD_CLEAR) ; }              
              error  = 0  ;
} ;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void evaluate_operation(void){
       while(1){
 k_pad_read_number(&k1 , &count) ;
       if(count != 99 && counter != 7){
           counter ++ ; 
         switch(counter){
              
             case 1 : 
                 first_term_ones = count ;lcd_8bit_send_char_data(&lcd1 , first_term_ones);   break ;
               
             
             case 2 : 
                   if((count == '+') || (count == '-') || (count == '*') || (count == '/')){
                       counter++ ; lcd_8bit_send_char_data(&lcd1 , ' '); first_term_tens = first_term_ones ;first_term_ones = '0' ; }
                              else {first_term_tens = count ;lcd_8bit_send_char_data(&lcd1 , first_term_tens);    
                                    lcd_8bit_send_char_data(&lcd1 , ' ');  break ; }  
               
             
             case 3 : 
                   operation = count ;lcd_8bit_send_char_data(&lcd1 , operation);    lcd_8bit_send_char_data(&lcd1 , ' ');  break ;        
               
             
             case 4 :
                   sec_term_ones = count ;lcd_8bit_send_char_data(&lcd1 , sec_term_ones);   break ;    
               
             
             
             case 5 :
                   if((count == '=')){counter++ ; lcd_8bit_send_char_data(&lcd1 , ' '); sec_term_tens = sec_term_ones ;sec_term_ones = '0'  ;}
                   else {sec_term_tens = count ;lcd_8bit_send_char_data(&lcd1 , sec_term_tens) ;
                             ;lcd_8bit_send_char_data(&lcd1 , ' '); break ;}  
               
             
             
             case 6 :
                   equality = count ;lcd_8bit_send_char_data(&lcd1 , equality);    lcd_8bit_send_char_data(&lcd1 , ' ');   break ; 
              
           }  
         
         count = 99 ;
         if(counter == 6){counter = 0 ; break ;}    
         
         
         
       }
    
    }
          __delay_ms(500) ;    
       
          swich_operation(operation) ;
              
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char sum(char ones_1, char tens_1 , char ones_2 , char tens_2){
    
    
    int int_ones_1 = ones_1 - '0' ; 
    int int_tens_1 = tens_1 - '0' ;
    int int_ones_2 = ones_2 - '0' ; 
    int int_tens_2 = tens_2 - '0' ;
    int result_first_term ; int result_sec_term ; 
   
    
  
        int temp1 = int_ones_1 ;          int temp = int_ones_2 ;   
        int_ones_1 =int_tens_1 ;          int_ones_2 =int_tens_2 ;
        int_tens_1 =temp1 ;               int_tens_2 =temp ;   
   
     result_first_term = int_ones_1 + (int_tens_1 * 10) ;
     result_sec_term   = int_ones_2 + (int_tens_2 * 10) ;
    
        
    int result = result_first_term + result_sec_term ; 
    char char_result = result +'0' ;  
    
    return char_result;
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
char minus(char ones_1, char tens_1 , char ones_2 , char tens_2){
    
    
    int int_ones_1 = ones_1 - '0' ; 
    int int_tens_1 = tens_1 - '0' ;
    int int_ones_2 = ones_2 - '0' ; 
    int int_tens_2 = tens_2 - '0' ;
    int result_first_term ; int result_sec_term ; 
   
     
        int temp1 = int_ones_1 ;          int temp = int_ones_2 ;   
        int_ones_1 =int_tens_1 ;          int_ones_2 =int_tens_2 ;
        int_tens_1 =temp1 ;               int_tens_2 =temp ;   
     
   
    
     result_first_term = int_ones_1 + (int_tens_1 * 10) ;
     result_sec_term   = int_ones_2 + (int_tens_2 * 10) ;
    
        
    int result = result_first_term - result_sec_term ;
    char char_result = result +'0' ; 
    
    return char_result;
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char multiply(char ones_1, char tens_1 , char ones_2 , char tens_2){
    
    
    int int_ones_1 = ones_1 - '0' ; 
    int int_tens_1 = tens_1 - '0' ;
    int int_ones_2 = ones_2 - '0' ; 
    int int_tens_2 = tens_2 - '0' ;
    int result_first_term ; int result_sec_term ; 
   
     
        int temp1 = int_ones_1 ;             int temp = int_ones_2 ;   
        int_ones_1 =int_tens_1 ;             int_ones_2 =int_tens_2 ;
        int_tens_1 =temp1 ;                  int_tens_2 =temp ;   
     
   
    
     result_first_term = int_ones_1 + (int_tens_1 * 10) ;
     result_sec_term   = int_ones_2 + (int_tens_2 * 10) ;
    
        
    int result = result_first_term * result_sec_term ;
    char char_result = result +'0' ; 
    
    return char_result;
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char devide(char ones_1, char tens_1 , char ones_2 , char tens_2){
    
    
    int int_ones_1 = ones_1 - '0' ; 
    int int_tens_1 = tens_1 - '0' ;
    int int_ones_2 = ones_2 - '0' ; 
    int int_tens_2 = tens_2 - '0' ;
    int result_first_term ; int result_sec_term ; 
   
   
        int temp1 = int_ones_1 ;          int temp = int_ones_2 ;   
        int_ones_1 =int_tens_1 ;          int_ones_2 =int_tens_2 ;
        int_tens_1 =temp1 ;               int_tens_2 =temp ;   
      
    
   
    
     result_first_term = int_ones_1 + (int_tens_1 * 10) ;
     result_sec_term   = int_ones_2 + (int_tens_2 * 10) ;
    
        
    int result = result_first_term / result_sec_term ;
    char char_result = result +'0' ; 
    
    return char_result;
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
