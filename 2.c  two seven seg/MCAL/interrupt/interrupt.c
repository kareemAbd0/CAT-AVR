#include "interrupt.h"



void interrupt_innit_rising()
{

  //enable global interrupts
   sei(); 
 // chhose interrupt sense (logic) will make it on rising edge (choice controlled by 2 registers)
  MCUCR |= (1<<ISC00) | (1<<ISC01);
   
   
  

}

void interrupt_enable(uint8_t inter)
{
//enable external inturrupt
  
  GICR |= (1<<inter);

}














