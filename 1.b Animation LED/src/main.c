
#include"MCAL/Timer Driver/timer.h"
#include"MCAL/DIO Driver/DIO.h"


int main(void)
{
    DIO_init('A',0,OUT);
    DIO_init('A',1,OUT);
    DIO_init('A',2,OUT);
    DIO_init('A',3,OUT);
    DIO_init('A',4,OUT);
    DIO_init('A',5,OUT);
    DIO_init('A',6,OUT);
    DIO_init('A',7,OUT);

    DIO_write('A',3,HIGH);
    DIO_write('A',4,HIGH);
    while (1)
    {
        DIO_write('A',2,HIGH);
        DIO_write('A',5,HIGH);
        timer_delay_ms(500);

        DIO_write('A',1,HIGH);
        DIO_write('A',6,HIGH);
        timer_delay_ms(500);

        DIO_write('A',0,HIGH);
        DIO_write('A',7,HIGH);
        timer_delay_ms(500);

        DIO_write('A',0,LOW);
        DIO_write('A',7,LOW);
        timer_delay_ms(500);

        DIO_write('A',1,LOW);
        DIO_write('A',6,LOW);
        timer_delay_ms(500);


        DIO_write('A',2,LOW);
        DIO_write('A',5,LOW);
        timer_delay_ms(500);


    }


    return 0;
}