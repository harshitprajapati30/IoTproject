#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>
#include"uart.h"
void main()
{
    uart_init();
	uart_delay(100);
	while(1);
	{uart_string("hello");}

}
