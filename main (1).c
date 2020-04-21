#include<avr/io.h>
#include<util/delay.h>
#include"uart.h"
#include"adc.h"

void main()
{DDRA=0B10000000;
uart_init();
adc_init();
DDRB=0B11111111;
DDRC=0B11111111;
unsigned char digital;
int i,a[5],n,j;
float sum=0;
while(1)
{
for(j=0;j<5;j++)
{
digital=getdata(0x00);
uart_num(digital);
uart_char('\n');
a[j]=digital;}
for(j=0;j<5;j++)
sum=sum+a[j];
n=sum/5;
i=n;
if(i<=25)
{
PORTB=0B11111111;
PORTA=0B11111111;
uart_string("extremely close");
}
else if(i<=35&&i>25)
{
PORTB=0B11111110;
PORTA=0B11111111;
uart_string("Extremely close");
}
else if(i<=45 && i>35)
{
PORTB=0B11111100;
uart_string("CLose enough");
PORTC=0b11111111;
_delay_ms(500);
}
else if(i<=55 && i>45 )
{
PORTB=0B11111000;
uart_string("close");
PORTC=0B11111111;
_delay_ms(500);
}
else if(i<=65 && i>55)
{
PORTB=0B11110000;
uart_string("close");
PORTC=0B11111111;
_delay_ms(500);
}
else if (i<=75 && i>65)
{PORTB=0B11100000;
uart_string("far enough");}
else if (i<=85 && i>75 )
{PORTB=0B11000000;
uart_string("far");}
else if (i<=95 && i >85)
{PORTB=0B10000000;
uart_string("very far");}
else 
PORTB=0B00000000;
}
}
