/* 
 * File:   HAL_GPIO.h
 * Author: el msria
 *
 * Created on October 31, 2023, 6:33 PM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

#ifdef	__cplusplus
extern "C" {
#endif

/*INCLUDES*/
    
    #include "pic18f4620.h"
    #include "../../MCAL_LAYER/DEVICE_CONFIG.h"
    #include "../../MCAL_LAYER/STD_TYPES.h"

    /*MACROS */    
    #define MAX_PIN_NUM  7
    #define MAX_PORT_NUM 4
    #define PORT_PIN_CONFIGRATION CONFIG_ENABLE
   /*MACRO FUNCS*/ 
    #define HWREG8(REG) (*((volatile uint8*)(REG)))
    #define SET_BIT(REG,LOC) (REG |= (1<<LOC))
    #define CLEAR_BIT(REG,LOC) (REG &= ~(1<<LOC))
    #define TOGGLE_BIT(REG,LOC) (REG ^= (1<<LOC))
    #define READ_BIT(REG,LOC)   ((1>>LOC) & REG) 
    #define READ_BIT(REG,LOC)   ((REG >> LOC) & 1)
   
   /*DATA TYPE DECLERATION*/
    
    typedef enum{
        LOW=0,
        HIGH=1,
    }logic_t ;
    
    
     typedef enum{
        OUTPUT=0,
        INPUT=1,            
    }direction_t ;
    
    
     typedef enum{
        PIN0,
        PIN1,
        PIN2,
        PIN3,
        PIN4,
        PIN5,
        PIN6,
        PIN7,
     }pin_index_t ;
    
     
    typedef enum{
        PORTA_INDEX,
        PORTB_INDEX,
        PORTC_INDEX,
        PORTD_INDEX,
        PORTE_INDEX, 
     }port_index_t ;

     
     typedef struct{
         uint8 pin_port :3 ;     //usinf bit field
         uint8 pin_num  :3 ;
         uint8 pin_direction :1 ;
         uint8 pin_state :1;
     
     }pin_config ;
   /*FUNCS DECLERATION*/ 
     Std_ReturnType gpio_pin_direction_init(const pin_config* PIN) ;
     Std_ReturnType gpio_pin_get_direction_state(const pin_config* PIN, direction_t *ptr) ;
     Std_ReturnType gpio_pin_write_logic(const pin_config* PIN ,logic_t logic) ;
     Std_ReturnType gpio_pin_read_logic(const pin_config* PIN ,logic_t *logic) ;
     Std_ReturnType gpio_pin_toggle_logic(const pin_config* PIN ) ;
     Std_ReturnType gpio_pin_init(const pin_config* PIN) ;
     

     Std_ReturnType gpio_port_direction_init(port_index_t port , uint8 direction) ;
     Std_ReturnType gpio_port_get_direction_state(port_index_t port, uint8* ptr) ;
     Std_ReturnType gpio_port_write_logic(port_index_t port,uint8 logic) ;
     Std_ReturnType gpio_port_read_logic(port_index_t port,uint8* ptr) ;
     Std_ReturnType gpio_port_toggle_logic(port_index_t port) ;



#ifdef	__cplusplus
}
#endif

#endif	/* HAL_GPIO_H */

