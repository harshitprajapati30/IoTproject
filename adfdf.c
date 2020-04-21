#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>
#include"uart.h"
#include"adc.h"
#include<stdlib.h>
int main()
{
DDRB=0B11111111;
DDRA=0B11111110;


float kilo=0;
const float qov=2.5;
float voltage;
float sensitivity=0.100;
unsigned long start,end;
char current1[10];
//char power1[10];
char kilo1[10];
//timer

adc_init();
uart_init();
while(1)
{int avg1=0,avg2=0;
for(int i=0;i<200;i++)
{
avg1=getdata(0x00);
if(avg2<avg1)
avg2=avg1;
}
float v=(5.0/1023.0)*avg2;
voltage=v-qov+0.027;
if(voltage>0)
{
float current=voltage/sensitivity;
uart_num(current);
//gcvt(current,5,current1);
uart_string("CURRENT: ");

//uart_string(current1);
float power=230*current*0.0707;
//millis end;
float time;//edit
time=time/1000000;
time=time/3600;
kilo=kilo+(power*time);
uart_num(kilo);
//gcvt(kilo,10,kilo1);
//uart_string(kilo1);
uart_string("Kwh");
_delay_ms(5000);}
}
}






