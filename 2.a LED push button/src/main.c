
#include"MCAL/Timer Driver/timer.h"
#include"MCAL/DIO Driver/DIO.h"
#include "ECUAL/LED Driver/LED.h"
int main(void)
{
    LED_innit('A',0);
    LED_innit('A',1);
    DIO_init('B',0,IN);
    DIO_init('B',1,IN);
    DIO_init('B',2,IN);

    while (1)
    {
        uint8_t value1= 0;
        uint8_t value2= 0;
        uint8_t value3= 0;
        DIO_read('B',0,&value1);
        DIO_read('B',1,&value2);
        DIO_read('B',2,&value3);

         if(value1 == 1)
         {
             LED_on('A',0);

             LED_off('A',1);
         } else if (value2 == 1)
         {

             LED_on('A',1);
             LED_off('A',0);
         } else if(value3 == 1)
         {

             LED_on('A',0);
             LED_on('A',1);

         }

    }



    return 0;
}