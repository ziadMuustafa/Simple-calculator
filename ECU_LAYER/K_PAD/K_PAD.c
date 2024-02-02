
#include <stdio.h>
#include "C:\Program Files\Microchip\MPLABX\v6.15\packs\Microchip\PIC18Fxxxx_DFP\1.4.151\xc8\pic\include\builtins.h"    
#include "K_PAD.h"
#define _XTAL_FREQ 4000000UL 

Std_ReturnType ret = E_OK ;

static const uint8 kpad[K_PAD_RAWS][K_PAD_COLOMS] ={
{  '7',  '8',  '9'  , '/'  },                              
{  '4',  '5',  '6'  , '*'  },
{  '1',  '2',  '3'  , '-'  },
{  'o',  '0',  '='  , '+'  },    
} ; 
////////////////////////////////////////////////////
Std_ReturnType k_pad_init(k_pad_t *k1){
    if(NULL == k1){ret = E_NOT_OK ;}
    else{
    
        uint8 raw_counter = 0 , colom_counter = 0 ; 
       
        for(raw_counter = 0 ;raw_counter<K_PAD_RAWS ; raw_counter++){ret =gpio_pin_direction_init(&(k1->K_PAD_PINS_ROWS[raw_counter])) ;}
        for(colom_counter = 0 ;colom_counter<K_PAD_COLOMS ; colom_counter++){ret =gpio_pin_direction_init(&(k1->K_PAD_PINS_COLOMS[colom_counter])) ;}
        
     
    }
    return ret ;
};
////////////////////////////////////////////////////////

Std_ReturnType k_pad_read_number(k_pad_t *k1 , uint8 *num){
 
    if(NULL == k1 || NULL == num ){ret = E_NOT_OK ;}
    else{
        
       
       
    uint8 raws  ,raws1 , coloms =0 ; uint8 colom_logic = 0 ;
     
    for( raws=0 ; raws < K_PAD_RAWS ; raws++){
        for(raws1  =0 ;raws1 < K_PAD_RAWS ; raws1++)
        { 
            gpio_pin_write_logic(&(k1->K_PAD_PINS_ROWS[raws1]), LOW)  ;          
        } 
        gpio_pin_write_logic(&(k1->K_PAD_PINS_ROWS[raws]), HIGH) ;  
    
        for(int coloms = 0 ; coloms < K_PAD_COLOMS ; coloms++ ){
            ret = gpio_pin_read_logic(&(k1->K_PAD_PINS_COLOMS[coloms]),&colom_logic) ;
            if(colom_logic == 1){*num = kpad[raws][coloms]; __delay_ms(800) ;  }
            __delay_ms(6) ;
        }
    
    }        
                                                                       // ------------> this is scanning systen        
                                                                      // ************> ACTIVATE EACH RAW
                                                                     // ============> CHECK ALL COLOMS OF THIS RAW 
           
        
    }  //   
 
 
    
    
    /* if(nub == 1 ){*num = 7 ;}    
   if(reading[0] == 1 && reading[5] == 1){*num = 8 ;}     
   if(reading[0] == 1 && reading[6] == 1){*num = 9 ;}    
   if(reading[0] == 1 && reading[7] == 1){*num = '/' ;}  
   if(reading[1] == 1 && reading[4] == 1){*num = 4 ;}    
   if(reading[1] == 1 && reading[5] == 1){*num = 5 ;}     
   if(reading[1] == 1 && reading[6] == 1){*num = 6 ;}    
   if(reading[1] == 1 && reading[7] == 1){*num = '*' ;}  
   if(reading[2] == 1 && reading[4] == 1){*num = 1 ;}    
   if(reading[2] == 1 && reading[5] == 1){*num = 2 ;}     
   if(reading[2] == 1 && reading[6] == 1){*num = 3 ;}    
   if(reading[2] == 1 && reading[7] == 1){*num = '-' ;}  
   if(reading[3] == 1 && reading[4] == 1){*num = 999 ;}    
   if(reading[3] == 1 && reading[5] == 1){*num = 0 ;}     
   if(reading[3] == 1 && reading[6] == 1){*num = '=' ;}    
   if(reading[3] == 1 && reading[7] == 1){*num = '+' ;}  */  
    
    
  } ;