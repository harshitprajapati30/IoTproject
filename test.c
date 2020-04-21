#define F_CPU16000000UL
#include<avr/io.h>
#include<util/delay.h>
#include"uart.h"

void main()
{
uart_init();
_delay_ms(1000);
while(1)
{

uart_string("welcome\r\n");
_delay_ms(2000);
uart_num(100);
_delay_ms(2000);
}
}
