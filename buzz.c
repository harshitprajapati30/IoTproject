#define F_CPU 16000000UL
#include<avr/io.h>

#include<util/delay.h>
void main()
{

DDRC=0B00000001;
while(1)
{
PORTC=0B00000001;
_delay_ms(1000);
PORTC=0B00000000;
_delay_ms(1000);}
}

