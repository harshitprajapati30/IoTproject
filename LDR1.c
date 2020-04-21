#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>
#include"uart.h"
#include"adc.h"
int main()
{

unsigned int digital,digital2,cin=0,cout=0,crowd;
adc_init();
uart_init();
uart_init(); 
_delay_ms(1000);
uart_string("AT+CWMODE=3\r\n");
_delay_ms(3000);
uart_string("AT+CWJAP=\"G\",\"vinnunikki\"\r\n");
_delay_ms(5000);
while(1)
{digital=getdata(0x00);
//uart_num(digital);
digital2=getdata(00000001);
//uart_num(digital2);
if(digital<300)
{cin++;}
//uart_num(cin);
if(digital2<300)
{cout++;}
//uart_num(cout);

crowd=cin-cout;
uart_num(crowd);
uart_char('\n');
_delay_ms(100);
uart_string("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80\r\n");
	_delay_ms(30);
	uart_string("AT+CIPSEND=100\r\n");
	_delay_ms(10);
	uart_string("GET /update?api_key=SPVEA7A3J0OMKS96&field3=");
	uart_num(crowd);
	uart_string("\r\n");
	_delay_ms(10);
	uart_string("AT+CIPCLOSE\r\n");


}}
