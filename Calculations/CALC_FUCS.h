/* 
 * File:   CALC_FUCS.h
 * Author: el msria
 *
 * Created on January 28, 2024, 7:45 PM
 */

#ifndef CALC_FUCS_H
#define	CALC_FUCS_H

#ifdef	__cplusplus
extern "C" {
#endif

 
#include "C:\Program Files\Microchip\MPLABX\v6.15\packs\Microchip\PIC18Fxxxx_DFP\1.4.151\xc8\pic\include\builtins.h"  
#include "C:\EMBEDDED_SYSTEMS\PIC\pic.X\MCAL_LAYER\STD_TYPES.h"    

    k_pad_t k1 = {
 
 

.K_PAD_PINS_ROWS[0].pin_direction =OUTPUT ,.K_PAD_PINS_ROWS[0].pin_num = 0 ,
.K_PAD_PINS_ROWS[0].pin_port =PORTD_INDEX ,.K_PAD_PINS_ROWS[0].pin_state = LOW ,

.K_PAD_PINS_ROWS[1].pin_direction =OUTPUT ,.K_PAD_PINS_ROWS[1].pin_num = 1 ,
.K_PAD_PINS_ROWS[1].pin_port =PORTD_INDEX ,.K_PAD_PINS_ROWS[1].pin_state = LOW ,

.K_PAD_PINS_ROWS[2].pin_direction =OUTPUT ,.K_PAD_PINS_ROWS[2].pin_num = 2 ,
.K_PAD_PINS_ROWS[2].pin_port =PORTD_INDEX ,.K_PAD_PINS_ROWS[2].pin_state = LOW ,

.K_PAD_PINS_ROWS[3].pin_direction =OUTPUT ,.K_PAD_PINS_ROWS[3].pin_num = 3 ,
.K_PAD_PINS_ROWS[3].pin_port =PORTD_INDEX ,.K_PAD_PINS_ROWS[3].pin_state = LOW ,

.K_PAD_PINS_COLOMS[0].pin_direction =INPUT , .K_PAD_PINS_COLOMS[0].pin_num = 4 ,
.K_PAD_PINS_COLOMS[0].pin_port =PORTD_INDEX ,.K_PAD_PINS_COLOMS[0].pin_state = LOW ,

.K_PAD_PINS_COLOMS[1].pin_direction =INPUT , .K_PAD_PINS_COLOMS[1].pin_num = 5 ,
.K_PAD_PINS_COLOMS[1].pin_port =PORTD_INDEX ,.K_PAD_PINS_COLOMS[1].pin_state = LOW ,

.K_PAD_PINS_COLOMS[2].pin_direction =INPUT , .K_PAD_PINS_COLOMS[2].pin_num = 6 ,
.K_PAD_PINS_COLOMS[2].pin_port =PORTD_INDEX ,.K_PAD_PINS_COLOMS[2].pin_state = LOW ,

.K_PAD_PINS_COLOMS[3].pin_direction =INPUT , .K_PAD_PINS_COLOMS[3].pin_num = 7 ,
.K_PAD_PINS_COLOMS[3].pin_port =PORTD_INDEX ,.K_PAD_PINS_COLOMS[3].pin_state = LOW , 

 
 }; 


lcd_8bit_t lcd1 ={
.data_pins[0].pin_direction = OUTPUT , .data_pins[0].pin_num =0 ,
.data_pins[0].pin_port =PORTB_INDEX  , .data_pins[0].pin_state =HIGH ,

.data_pins[1].pin_direction = OUTPUT , .data_pins[1].pin_num =1 ,
.data_pins[1].pin_port =PORTB_INDEX  , .data_pins[1].pin_state =HIGH ,

.data_pins[2].pin_direction = OUTPUT , .data_pins[2].pin_num =2 ,
.data_pins[2].pin_port =PORTB_INDEX  , .data_pins[2].pin_state =HIGH ,

.data_pins[3].pin_direction = OUTPUT , .data_pins[3].pin_num =3 ,
.data_pins[3].pin_port =PORTB_INDEX  , .data_pins[3].pin_state =HIGH ,

.data_pins[4].pin_direction = OUTPUT , .data_pins[4].pin_num =4 ,
.data_pins[4].pin_port =PORTB_INDEX  , .data_pins[4].pin_state =HIGH ,

.data_pins[5].pin_direction = OUTPUT , .data_pins[5].pin_num =5 ,
.data_pins[5].pin_port =PORTB_INDEX  , .data_pins[5].pin_state =HIGH ,

.data_pins[6].pin_direction = OUTPUT , .data_pins[6].pin_num =6 ,
.data_pins[6].pin_port =PORTB_INDEX  , .data_pins[6].pin_state =HIGH ,

.data_pins[7].pin_direction = OUTPUT , .data_pins[7].pin_num =7 ,
.data_pins[7].pin_port =PORTB_INDEX  , .data_pins[7].pin_state =HIGH ,

.rs_pin.pin_direction = OUTPUT , .rs_pin.pin_num = 6 ,
.rs_pin.pin_port = PORTC_INDEX , .rs_pin.pin_state = HIGH ,

.enable_pin.pin_direction = OUTPUT , .enable_pin.pin_num =7 ,
.enable_pin.pin_port = PORTC_INDEX , .enable_pin.pin_state =HIGH ,   
};

// FUNCTIONS DECLERATIONS///////////////////////////////////////////////
void swich_operation(char operation) ;
void evaluate_operation(void) ;
char sum(char ones_1, char tens_1 , char ones_2 , char tens_2) ;
char devide(char ones_1, char tens_1 , char ones_2 , char tens_2) ;
char multiply(char ones_1, char tens_1 , char ones_2 , char tens_2) ;
char minus(char ones_1, char tens_1 , char ones_2 , char tens_2) ;

    
    


#ifdef	__cplusplus
}
#endif

#endif	/* CALC_FUCS_H */

