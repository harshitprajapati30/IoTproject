#include<avr/io.h>
#include<util/delay.h>
void main()
{

DDRB=0B11111111;
while(1)
{
PORTB=0B11111111;
_delay_ms(1000);
PORTB=0B00000000;
_delay_ms(1000);
}}
