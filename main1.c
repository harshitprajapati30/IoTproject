#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>
#include"uart.h"
#include"adc.h"

void main()
{DDRA=0B10000000;
DDRB=0B11111111;
DDRC=0B11111111;
uart_init();
adc_init();
_delay_ms(1000);
unsigned int digital;
int i,a[3],j;
float sum=0;
while(1)
{
i=getdata(0x00);
uart_num(i);
uart_char('\n');
_delay_ms(1000);

if(i<=25)
{
PORTB=0B11111111;
PORTA=0B11111111;
PORTC=0B00000000;
uart_string("extremely close");
uart_char('\n');
PORTC=0B11111111;
_delay_ms(50);
PORTC=0B00000000;
}
else if(i<=35&&i>25)
{
PORTB=0B11111110;
PORTA=0B11111111;
PORTC=0B00000000;
uart_string("Extremely close");
uart_char('\n');
PORTC=0B11111111;
_delay_ms(100);
PORTC=0B00000000;
}
else if(i<=45 && i>35)
{
PORTB=0B11111100;
PORTA=0B00000000;
uart_string("CLose enough");
uart_char('\n');
PORTC=0B11111111;
_delay_ms(250);
PORTC=0B00000000;

}
else if(i<=55 && i>45 )
{
PORTB=0B11111000;
PORTA=0B00000000;
uart_string("close");
uart_char('\n');
PORTC=0B11111111;
_delay_ms(250);
PORTC=0B00000000;


}
else if(i<=65 && i>55)
{PORTA=0B00000000;
PORTB=0B11110000;
uart_string("close");
uart_char('\n');

PORTC=0B11111111;
_delay_ms(250);
PORTC=0B00000000;

}
else if (i<=75 && i>65)
{PORTB=0B11100000;
PORTA=0B00000000;
PORTC=0B00000000;
uart_string("far enough");
uart_char('\n');}
else if (i<=85 && i>75 )
{PORTB=0B11000000;
PORTA=0B00000000;
PORTC=0B00000000;
uart_string("far");
uart_char('\n');}
else if (i<=95 && i >85)
{PORTB=0B10000000;
PORTA=0B00000000;
PORTC=0B00000000;
uart_string("very far");
uart_char('\n');}
else if(i>95)
{PORTB=0B00000000;
PORTA=0B00000000;
PORTC=0B00000000;}
}
}
