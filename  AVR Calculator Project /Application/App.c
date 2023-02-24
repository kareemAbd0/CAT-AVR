//
// Created by kareem on 2/23/23.
//
#include "../MCAL/err.h"
#include "../MCAL/type.h"
#include "../MCAL/Timer Driver/timer.h"
#include "../MCAL/DIO Driver/DIO.h"
#include "../ECUAL/LCD/LCD.h"
#include "../ECUAL/keypad/keypad.h"
#include "App.h"

void calc_init()

{
    key_pad_init();
    LCD_init();
    uint8_t nflag ,cflag = 0;
    unsigned long result ;

    unsigned long num1;
    unsigned long num2;
    char s_result [MAX_ELEMENT] = {0};
    uint8_t operation = NOT_READ;

    while (1) {

        num1 = 0;
        num2 = 0;
        nflag = 0;

        operation = NOT_READ;
        result = 0;


        while (1) {
            uint8_t key = NOT_READ;

            while (key == NOT_READ) {
                key_pad_pressed_key(&key);
            }


            // clear if full  number is entered
            if(cflag == 1) LCD_send_command(0x01);
            cflag = 0;
            // clear at clear button
            if(key == 'c') { LCD_send_command(0x01); break;}

            // calculate if = is pushed and first number was entered
            if (key == '=' && nflag == 1)
            {

                switch (operation) {
                    case '+' :
                        result = num1 + num2;
                        break;

                    case '-' :
                        result = num1 - num2;
                        break;

                    case '/' :
                        result = num1 / num2;
                        break;

                    case 'X' :
                        result = num1 * num2;
                        break;
                    default:
                        break;

                }
                //clear to start printing result
                LCD_send_command(0x01);

               //convert to string to display on LCD
                int_to_string(result,s_result);
                int k = 0;

                while (s_result[k] != '\0')
                {

                    LCD_display_char(s_result[k]);

                    k++;

                }
                //to clear display for the next calculation
                cflag = 1;
                //go to next calculation
                break;

           // this is for the first number
            } else if (key != '+' && key != '/' && key != 'X' && key != '-' && key!= '=' && nflag == 0) {
                LCD_display_char(key);
                num1 = num1 * 10 + (key - '0');
            //if operation is entered save it
            } else if(nflag == 0 && key!= '=') {
                operation = key;
                nflag = 1;
                cflag = 1;
                continue;
            }
            //this is for the second number, starts when an operation is entered
            if (nflag == 1) {

                LCD_display_char(key);
                num2 = num2 * 10 + (key - '0');

            }
        }
    }
}


void int_to_string(unsigned long num,char string[MAX_ELEMENT])
{

    unsigned long len = 0;
    unsigned  long rem ;
    unsigned long tnum = num;

    while (tnum != 0)
    {

        tnum /= 10;

        len++;
    }


    for (int i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        string[len - (i + 1)] = rem + '0';
    }
    string[len] = '\0';

}



