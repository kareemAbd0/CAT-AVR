//
// Created by kareem on 2/23/23.
//

#ifndef AVR_CALCULATOR_APP_H
#define AVR_CALCULATOR_APP_H
#define NOT_READ    0xfe
#define MAX_ELEMENT 15
void calc_init();
void int_to_string(unsigned long num,char string[MAX_ELEMENT]);


#endif //AVR_CALCULATOR_APP_H
