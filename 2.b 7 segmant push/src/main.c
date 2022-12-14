
#include"MCAL/Timer Driver/timer.h"
#include"MCAL/DIO Driver/DIO.h"
#include "ECUAL/LED Driver/LED.h"
#include "ECUAL/7-segment/7-segment.h"
int main(void)
{
    Seven_Seg_Cathode_Innit('C');
    DIO_init('A',0,IN);
    DIO_init('A',1,IN);
    uint8_t num = 0;
    while (1)
    {

        uint8_t state1= 0;
        uint8_t state2 = 0;
        DIO_read('A',0,&state1);
        DIO_read('A',1,&state2);
        timer_delay_ms(300);
        if (state1 == 1 && num <9)
        {
            num++;

        }
        if (state2 == 1 && num > 0)
        {
            num --;
        }
        Seven_Seg_Cathode_Display_Num(num,'C');
    }
}