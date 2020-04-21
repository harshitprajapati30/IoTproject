#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>
#include"uart.h"
#include"adc.h"
int main()
{
DDRB=0B11111111;
DDRA=0B10000000;
unsigned int digital1,digital2;
int counterin=0,counterout=0;

//CONNECTING TO NETWORK
uart_string("AT+CWMODE=3\r\n");
_delay_ms(3000);
uart_string("AT+CWJAP=\"G\",\"vinnunikki\"\r\n");
_delay_ms(5000);

adc_init();
uart_init();

while(1)
{
//ENTRY GATE
digital1=getdata(00000000);
//uart_char('1');
uart_char('\n');
uart_num(digital1);
uart_char('\n');
uart_num(counterin);
uart_string("PERSON IN");
uart_char('\n');
if(digital1<700){
   counterin++;
   }
//EXIT GATE
//uart_char('2');
uart_char('\n');
digital2=getdata(00000001);
uart_num(digital2);
uart_char('\n');
uart_num(counterout);
uart_string("PERSON OUT");
uart_char('\n');

if(digital2<600){
   counterout++;
   }
int crowd=counterin-counterout;
   uart_num(crowd);
   uart_char('\n');

//SENDIND CROWD DATA TO THINGSPEAK

uart_num(crowd);
/*uart_string("AT+CPISTART=\"TCP\",\"api>thingspeak>com\",80\r\n");
_delay_ms(3000);
uart_string("AT+CPISEND=51\r\n");
_delay_ms(100);
uart_string("GET /update?api_key=SPVEA7A3J0OMKS96&field3=");
uart_num(crowd);
uart_string("\r\n");
_delay_ms(100);
uart_string("AT+CIPCLOSE\r\n");
_delay_ms(2000);*/
}
}
