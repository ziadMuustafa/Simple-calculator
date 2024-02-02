/* 
 * File:   K_PAD.h
 * Author: el msria
 *
 * Created on October 31, 2023, 7:54 PM
 */

#ifndef K_PAD_H
#define	K_PAD_H

#ifdef	__cplusplus
extern "C" {
#endif
//INCLUDES
 #include "K_PAD_CFG.h"
 #include "../../MCAL_LAYER/GPIO/HAL_GPIO.h"   


//MACROS
#define LINE_ACTIVE 1
#define LINE_LOW 0    

#define K_PAD_RAWS 4
#define K_PAD_COLOMS 4
    
//USER DEFINED DATA TYPES
 typedef struct{
 
     pin_config K_PAD_PINS_ROWS[K_PAD_RAWS] ; 
     pin_config K_PAD_PINS_COLOMS[K_PAD_COLOMS] ; 
    
 }k_pad_t;
 
 //FUNCTIONS DECELERATIONS 
 
 Std_ReturnType k_pad_init(k_pad_t *k1) ;
 Std_ReturnType k_pad_read_number(k_pad_t *k1 , uint8 *num) ;
 
 
#ifdef	__cplusplus
}
#endif

#endif	/* K_PAD_H */

