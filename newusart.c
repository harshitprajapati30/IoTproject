#define F_CPU 8000000UL
//#define SREG    _SFR_IO8(0x3f)

#include <avr/io.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "USART_Interrupt.h"
//#include"uart.h"
void main()
{
USART_Init(115200);
_delay_ms(100);
sei();
_delay_ms(100);
USART_TxChar('A');

}
