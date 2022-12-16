
#include"MCAL/Timer Driver/timer.h"
#include"MCAL/DIO Driver/DIO.h"


int main(void)
{
    DIO_init('A',0,OUT);
    while (1)
    {
        DIO_toggle('A',0);
        timer_delay_ms(1000);
    }


    return 0;
}