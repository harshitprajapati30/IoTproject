
#include<avr/io.h>
#include<util/delay.h>
#include"uart.h"
int main()
{
char c;
DDRB=0b11111111;
DDRA=0b11111111;
uart_init();
_delay_ms(100);
while(1)
{
c=uart_read();
if(c=='A'){
   PORTB=0b11111111;
   PORTA=0b11111111;
   _delay_ms(20000);
   PORTA=0b00000000;
   _delay_ms(20000);
   }
if(c=='B'){
   PORTB=0b00000000;
   }
}
}
