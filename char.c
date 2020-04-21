#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>
#include"uart.h"
int main()
{
char c;
DDRB=0b11111111;
uart_init();
_delay_ms(100);
while(1)
{
c=uart_read();

if (c=='A')


PORTB=0B11111111;
if(c=='B')

PORTB=0B00000000;

}
}
