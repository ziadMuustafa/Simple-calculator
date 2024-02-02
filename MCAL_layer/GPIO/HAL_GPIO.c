#include "HAL_GPIO.h"
#include <stdio.h>

volatile uint8* tris_registers[] ={&TRISA, &TRISB, &TRISC,&TRISD,&TRISE } ;
volatile uint8* lat_registers[] ={&LATA, &LATB, &LATC,&LATD,&LATE } ;
volatile uint8* port_registers[] ={&PORTA, &PORTB, &PORTC,&PORTD,&PORTE } ;
uint8 ret ;
/**
 * 
 * @param PIN
 * @return 
 */
///////////////////////////////////////////////////////////////////////////////   
#if PORT_PIN_CONFIGRATION==CONFIG_ENABLE
        Std_ReturnType gpio_pin_direction_init(const pin_config* PIN) {
                                  Std_ReturnType ret = E_OK ;    
     
     if(NULL == PIN){ret = E_NOT_OK ;} 
     
     else if(PIN->pin_num <0 || PIN->pin_num > MAX_PIN_NUM || PIN->pin_port <0 || PIN->pin_port > MAX_PORT_NUM){ret= E_NOT_OK ;}
                                  
     else{                             
     
         switch(PIN->pin_direction){
            case (OUTPUT) : 
                CLEAR_BIT(*tris_registers[PIN->pin_port],PIN->pin_num); break ;
            case (INPUT) :
                SET_BIT(*tris_registers[PIN->pin_port],PIN->pin_num); break ;
            default :
                ret = E_NOT_OK ;
                    }  
                 }
            return ret ;      
            }
         
           #endif 
///////////////////////////////////////////////////////////////////////////////
        
        
        
/**
  * 
  * @param PIN
  * @param ptr
  * @return 
  */   
       

#if PORT_PIN_CONFIGRATION==CONFIG_ENABLE

     Std_ReturnType gpio_pin_get_direction_state(const pin_config* PIN, direction_t *ptr){
      Std_ReturnType ret = E_OK ;    
     
     if(NULL == PIN || ptr == NULL || PIN->pin_num >7 ){ret = E_NOT_OK ;} 
     
     else if(PIN->pin_num <0 || PIN->pin_num > MAX_PIN_NUM || PIN->pin_port <0 || PIN->pin_port > MAX_PORT_NUM){ret= E_NOT_OK ;}
                                  
     else{                             
             
     *ptr = READ_BIT(*tris_registers[PIN->pin_port], PIN->pin_num) ;        
            }  return ret ;   
     }
#endif

     
////////////////////////////////////////////////////////////////////////////////////
#if PORT_PIN_CONFIGRATION==CONFIG_ENABLE
     Std_ReturnType gpio_pin_write_logic(const pin_config* PIN ,logic_t logic) {
         if(NULL == PIN || PIN->pin_num >7 ){ret = E_NOT_OK;}
         else{
         
             switch(logic){
                 case (LOW) :
                       CLEAR_BIT(*lat_registers[PIN->pin_port],PIN->pin_num); break ;
                 case (HIGH) :
                       SET_BIT(*lat_registers[PIN->pin_port],PIN->pin_num); break ;                     
                 default : ret = E_NOT_OK ;
             }
         }
     return ret ;}
     
#endif 
////////////////////////////////////////////////////////////////////////////////////     
          
         
#if PORT_PIN_CONFIGRATION==CONFIG_ENABLE

     Std_ReturnType gpio_pin_read_logic(const pin_config* PIN ,logic_t *logic) {
       if(NULL == PIN || PIN->pin_num >7 || logic == NULL ){ret = E_NOT_OK;}
         else{
         *logic = READ_BIT(*port_registers[PIN->pin_port], PIN->pin_num) ;       
         
         }
             
     return ret ;}
#endif


/////////////////////////////////////////////////////////////////////////////////////     
#if PORT_PIN_CONFIGRATION==CONFIG_ENABLE

     Std_ReturnType gpio_pin_toggle_logic(const pin_config* PIN ) {
         if(NULL == PIN || PIN->pin_num >7  ){ret = E_NOT_OK;}
         else{
         TOGGLE_BIT(*lat_registers[PIN->pin_port],PIN->pin_num)  ;
         
         }
             
     return ret ;}
#endif
  ///////////////////////////////////////////////////////////////////////////////////
     
     #if PORT_PIN_CONFIGRATION==CONFIG_ENABLE

     Std_ReturnType gpio_pin_init(const pin_config* PIN){
     if(NULL == PIN || PIN->pin_num >7  ){ret = E_NOT_OK;}
         else{
        ret = gpio_pin_direction_init(PIN) ;
        ret = gpio_pin_write_logic(PIN,PIN->pin_state) ;
         
         
         }
       return ret ; 
     }
    #endif
   
     ///////////////////////////////////////////////////////////////////////////////////
    #if PORT_PIN_CONFIGRATION==CONFIG_ENABLE
     
     Std_ReturnType gpio_port_direction_init(port_index_t port , uint8 direction ) {
      if(port > MAX_PORT_NUM) {ret = E_NOT_OK ;}
           else{
              *tris_registers[port]= direction ;
         
        }
       return ret ;  
     }
     #endif 
     ///////////////////////////////////////////////////////////////////////////////////

    #if PORT_PIN_CONFIGRATION==CONFIG_ENABLE
     
     Std_ReturnType gpio_port_get_direction_state(port_index_t port, uint8* ptr) {
         if(NULL == ptr || port > MAX_PORT_NUM){ret = E_NOT_OK ;}
         else{
               
              *ptr =*tris_registers[port] ;      
         }
        return ret ; 
    }
    #endif
   
     //////////////////////////////////////////////////////////////////////////////
    #if PORT_PIN_CONFIGRATION==CONFIG_ENABLE
     Std_ReturnType gpio_port_write_logic(port_index_t port,uint8 logic) {
     if( port > MAX_PORT_NUM){ret = E_NOT_OK ;}
         else{
               
           *lat_registers[port] =   logic    ;      
         }
        return ret ; 
     }
    #endif
     ////////////////////////////////////////////////////////////////////////////////
     #if PORT_PIN_CONFIGRATION==CONFIG_ENABLE
     Std_ReturnType gpio_port_read_logic(port_index_t port,uint8* ptr) {
        if(NULL == ptr || port > MAX_PORT_NUM){ret = E_NOT_OK ;}        
        else{
         *ptr = *lat_registers[port] ;
          }
       return ret ; }
        
     #endif
    ////////////////////////////////////////////////////////////////////////////////
     #if PORT_PIN_CONFIGRATION==CONFIG_ENABLE

     Std_ReturnType gpio_port_toggle_logic(port_index_t port) {
         if(port > MAX_PORT_NUM){ret = E_NOT_OK ;}
         else{
           /*  for(int i=0 ;i<(MAX_PIN_NUM+1) ;i++){     // ANOTHER WAY TO MAKE THE TOGGLE
                 TOGGLE_BIT(*lat_registers[port],i) ;
             } */
            *lat_registers[port] = *lat_registers[port] ^ 0xFF ;
         }
       

         return ret ;}
     #endif
  ///////////////////////////////////////////////////////////////////////////////////   

