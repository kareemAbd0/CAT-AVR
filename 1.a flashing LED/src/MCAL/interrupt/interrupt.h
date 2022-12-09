

#ifndef INTERRUPT_H

#define INTERRUPT_H

#include"../registers.h"
#include"../type.h"
#include"avr/interrupt.h" 
#include"avr/io.h" 



#define ISR(INT_VECT) void INT_VECT (void) __attribute__ ((signal,used));\
void INT_VECT (void)

// #define INT0_VECT __vector_1
// #define INT1_VECT __vector_2
// #define INT2_VECT __vector_3

// #define JTD 7
// #define ISC00 0
// #define ISC01 1
#define INT0 6
#define INT1 7
#define INT2 5



void interrupt_innit_rising();
void interrupt_enable(uint8_t inter);









#endif

