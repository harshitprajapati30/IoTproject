#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>
#include"usart16.h"

void main()
{
usart_init();
 usart_rec();
 char c;
 c==usart_rec();
 DDRB=0B11111111;
 if(c=='A')
 {
 PORTB=0B11111111;
 }


}
