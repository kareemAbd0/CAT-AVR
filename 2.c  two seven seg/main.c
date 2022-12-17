#include "ECUAL/7-segment/7-segment.h"
#include "MCAL/type.h"
#include "MCAL/DIO Driver/DIO.h"
#include "MCAL/Timer Driver/timer.h"
int main()
{
    Seven_Seg_Cathode_Innit('C');
    Seven_Seg_Cathode_Innit('D');
    DIO_init('A',0,IN);
    DIO_init('A',1,IN);
    uint8_t num1=5;
    char num2=0;
    Seven_Seg_Cathode_Display_Num(num1,'C');
    Seven_Seg_Cathode_Display_Num(num2,'D');


    while (1)
    {

        uint8_t value1 = 0;
        uint8_t value2 = 0;
        DIO_read('A',0,&value1);
        DIO_read('A',1,&value2);
        timer_delay_ms(300);

        if (value1 == 1 && num2 <= 9)
        {
           num2++;
            if (num2 == 10 && num1 < 9)
            {
                num1 ++;
                num2 = 0;
            }
        }

        if (value2 == 1 && num2 >= 0)
        {
            num2--;
            if (num2 == -1 && num1 > 0)
            {
                num1 --;
                num2 = 9;
            }
        }
        Seven_Seg_Cathode_Display_Num(num1,'C');
        Seven_Seg_Cathode_Display_Num(num2,'D');

    }


}