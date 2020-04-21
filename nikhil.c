#define F_CPU8000000UL
#include<avr/io.h>
#include<util/delay.h>
#include"USART_Interrupt.h"
#include"uart.h"


void main()
{
//USART_Init(115200);
//_delay_ms(1000);
//USART_TxChar('A');
//_delay_ms(1000);
uart_init();
while(1)
{

uart_string("NIKHIL\n");
_delay_ms(1000);
}

}
