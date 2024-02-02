/* 
 * File:   STD_TYPES.h
 * Author: el msria
 *
 * Created on October 31, 2023, 6:43 PM
 */

#ifndef STD_TYPES_H
#define	STD_TYPES_H

#ifdef	__cplusplus
extern "C" {
#endif

/*SECTION : INCLUDES*/
  
    /*MACROS */    
   #define STD_HIGH 0x01
   #define STD_LOW  0x00
 
   #define STD_ON   0x01
   #define STD_OFF  0x00

   #define ACTIVE   0x01
   #define IDLE     0x00
   
   #define E_OK     (Std_ReturnType)0x01
   #define E_NOT_OK     (Std_ReturnType)0x00
  
   #define CONFIG_ENABLE 0x01 
   #define CONFIG_DISABLE 0x00 


    /*MACRO FUNCS*/ 
    
   
   /*DATA TYPE DECLERATION*/
   typedef unsigned char uint8 ;
   typedef unsigned short uint16 ;
   typedef unsigned int uint32 ;
   
   typedef uint8 Std_ReturnType ;

   
    
   /*FUNCS DECLERATION*/ 



#ifdef	__cplusplus
}
#endif

#endif	/* STD_TYPES_H */

