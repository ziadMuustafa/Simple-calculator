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
/**
 * //this function is switching to determine which operation will be done 
 * @param operation
 */
void swich_operation(char operation){
switch(operation){
          
           
           case '+' :
             result = sum(first_term_ones , first_term_tens , sec_term_ones , sec_term_tens) ;
             
             //converting char to integer and check if the tens equals 0 then just print the ones ( 05 --> 5 ) and convert it to char again
             if (((result)-'0')/10 == 0){lcd_8bit_send_char_data(&lcd1 , ((result)-'0')%10 + '0') ;}   
             else{ 
                 //else we will split the number to its ones and tens then print each of them 
                 lcd_8bit_send_char_data(&lcd1 , ((result)-'0')/10 + '0') ; 
                 lcd_8bit_send_char_data(&lcd1 , ((result)-'0')%10 + '0') ;  }          
                 ; __delay_ms(400);break ;
           //AND SAME TECHNIQUE FOR ALL OPERATIONS
           
           
           case '-' :
             result = minus(first_term_ones , first_term_tens , sec_term_ones , sec_term_tens) ;
             if (((result)-'0')/10 == 0){lcd_8bit_send_char_data(&lcd1 , ((result)-'0')%10 + '0') ;} 
             else{
                 lcd_8bit_send_char_data(&lcd1 , ((result)-'0')/10 + '0') ;
                 lcd_8bit_send_char_data(&lcd1 , ((result)-'0')%10 + '0') ;  } 
                ; __delay_ms(400);break ;
           
           
           
           case '*' :
             result = multiply(first_term_ones , first_term_tens , sec_term_ones , sec_term_tens) ;
             if (((result)-'0')/10 == 0){lcd_8bit_send_char_data(&lcd1 , ((result)-'0')%10 + '0') ;} 
             else{ 
                 lcd_8bit_send_char_data(&lcd1 , ((result)-'0')/10 + '0') ;
                 lcd_8bit_send_char_data(&lcd1 , ((result)-'0')%10 + '0') ;  }
                ; __delay_ms(400);break ;
           
           
           
           case '/' :
             result = devide(first_term_ones , first_term_tens , sec_term_ones , sec_term_tens) ; 
             if (((result)-'0')/10 == 0){lcd_8bit_send_char_data(&lcd1 , ((result)-'0')%10 + '0') ;} 
             else{
                 lcd_8bit_send_char_data(&lcd1 , ((result)-'0')/10 + '0') ;
                 lcd_8bit_send_char_data(&lcd1 , ((result)-'0')%10 + '0') ;  }
                 ; __delay_ms(400);break ;  
           
           
           default :
            __delay_ms(500); lcd_8bit_send_command(&lcd1 , LCD_CLEAR) ; __delay_ms(500) ; 
             lcd_8bit_send_string(&lcd1 , "ERROR") ;  
             error = 1 ;__delay_ms(500);lcd_8bit_send_command(&lcd1 , LCD_CLEAR) ; break  ;
       
       
       }
       
       
       if(error != 1){
           //HERE CHECK IF THE ERROR SIGNAL NEVER BE ASSIGNED TO 1 THEN WILL PRINT "operation done" AND CLEAR THE LCD
           
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
       
    if(count == 'o'){lcd_8bit_send_command(&lcd1 , LCD_CLEAR); counter = 0 ;}  //CHECK IF THE USER ENTERED 'O' TO CLEAR THE LCD OR NOT  
       else if(count != 99 && counter != 7){ //CHECK IF THE K_PAD READING DIDNT CHANGE WHICH MEANS WE DIDNT ENTER ANY THING YET AND  
           counter ++  ;                     //THE COUNTER DIDNT FINISH THE ALL CASES OR NOT
         
           switch(counter){
              
             case 1 : 
                 first_term_ones = count ;lcd_8bit_send_char_data(&lcd1 , first_term_ones);   break ;
                 //STORING THE FIRST ONE
             
             
             case 2 : 
                   if((count == '+') || (count == '-') || (count == '*') || (count == '/')){
                       counter++ ; lcd_8bit_send_char_data(&lcd1 , ' '); first_term_tens = first_term_ones ;first_term_ones = '0' ; }
                      //CHECK IF THE USER JUST ENTERED ONE DIGIT NUMBER OR NOT 
                     //THEN IF HE DID THAT WE WILL SWAP THE ONES WITH THE TENS AS ALL ONES AND TENS WILL BE SWAPPED AT END
                   
                   else {first_term_tens = count ;lcd_8bit_send_char_data(&lcd1 , first_term_tens);    
                                    lcd_8bit_send_char_data(&lcd1 , ' ');  break ; } 
                   //ELSE JUST STORE THE TENS
                   
             
             case 3 : 
                   operation = count ;lcd_8bit_send_char_data(&lcd1 , operation);    lcd_8bit_send_char_data(&lcd1 , ' ');  break ;        
                   
             
             case 4 :
                   sec_term_ones = count ;lcd_8bit_send_char_data(&lcd1 , sec_term_ones);   break ;    
                     
             
             case 5 :
                   if((count == '=')){counter++ ; lcd_8bit_send_char_data(&lcd1 , ' '); sec_term_tens = sec_term_ones ;sec_term_ones = '0'  ;}
                  //CHECK IF THE USER ENTERED '=' WHICH MEANS HE ENTERED ONE DIGIT NUMBER
                   else {sec_term_tens = count ;lcd_8bit_send_char_data(&lcd1 , sec_term_tens) ;
                             ;lcd_8bit_send_char_data(&lcd1 , ' '); break ;}  
               
             
             
             case 6 :
                   equality = count ;lcd_8bit_send_char_data(&lcd1 , equality);    lcd_8bit_send_char_data(&lcd1 , ' ');   break ; 
              
           }  
         
         count = 99 ; //RESET THE COUNT VALUE TO 99 AGAIN TO PREVENT ENTERING THE SWITCH CASE BEFORE GETTING THE K_PAD READDING
         if(counter == 6){counter = 0 ; break ;} // CHECK IF THE COUNTER TERMINATED THE RESET IT TO 0 AND BREAK THE WHILE(1) THEN GO 
                                                 //FOR THE NEXT STEP TO SWITCH FOR THE OPERATION
         
         
         
       }
    
    }
          __delay_ms(500) ;    
       
          swich_operation(operation) ;  // HERE SWICHING FOR THE OPERATION THEN PRINT THE RESULT
              
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
char sum(char ones_1, char tens_1 , char ones_2 , char tens_2){
    
    
    int int_ones_1 = ones_1 - '0' ;  //
    int int_tens_1 = tens_1 - '0' ;  //--> HERE ALL THIS LINES WE CONVERT THE ALL THE TENS AND ONES INTO INTEGERS
    int int_ones_2 = ones_2 - '0' ;  //
    int int_tens_2 = tens_2 - '0' ;  //
    int result_first_term ; int result_sec_term ; 
   
    
  
        int temp1 = int_ones_1 ;          int temp = int_ones_2 ;   //
        int_ones_1 =int_tens_1 ;          int_ones_2 =int_tens_2 ;  // --> ALL THIS LINES WE ARE SWAPPING THE ONES AND TENS TO 
        int_tens_1 =temp1 ;               int_tens_2 =temp ;        //     GET THE RIGHT VALUE OF THEM --> REMEMBER WE RECIVED THEM SWAPPED 
                                                                    //     FROM THE PREV FUNCTION evaluate_operation()
     result_first_term = int_ones_1 + (int_tens_1 * 10) ;  //
     result_sec_term   = int_ones_2 + (int_tens_2 * 10) ;  // --> HERE IN THIS LINES COLLECTING THE NUMBER BY SUMMING THE ONES AND TENS
                                                           //     OF THE TWO NUMBERS OF THE OPERATION A + B = C ;;
        
    int result = result_first_term + result_sec_term ;   // --> HERE WE FINNALY EVALUATE THE RESULT OF THE OPERATION 
    char char_result = result +'0' ;       // --> HERE WE CONVERT THE FINAL RESULT TO A CHAR
    
    return char_result;                   // HERE WE RETURN THE FINAL RESULT
}
///////////////////////////////////////////////////////////////////////////////
// SAME COMMENTS AND LOGIC FOR ALL OPERATIONS - , * OR /
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
