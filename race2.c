/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.2 Evaluation
Automatic Program Generator
© Copyright 1998-2011 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 21-10-2018
Author  : Freeware, for evaluation and non-commercial use only
Company : 
Comments: 


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*****************************************************/

#include <mega16.h>
#include <delay.h>
#include <stdlib.h>

// Standard Input/Output functions
#include <stdio.h>

unsigned char USART_Receive(void);
void USART_Transmit(unsigned char data);
void MODE_ONE(unsigned char a);
void USART_Init(unsigned char ubrr);

// Declare your global variables here
char a;
void main(void)
{
// Declare your local variables here

// Input/Output Ports initialization
// Port A initialization
// Func7=Out Func6=Out Func5=Out Func4=Out Func3=Out Func2=Out Func1=Out Func0=Out 
// State7=0 State6=0 State5=0 State4=0 State3=0 State2=0 State1=0 State0=0 
PORTA=0x00;
DDRA=0xFF;

// Port B initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTB=0x00;
DDRB=0x00;

// Port C initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTC=0x00;
DDRC=0x00;

// Port D initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTD=0x00;
DDRD=0x00;

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
// Mode: Normal top=0xFF
// OC0 output: Disconnected
TCCR0=0x00;
TCNT0=0x00;
OCR0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer1 Stopped
// Mode: Normal top=0xFFFF
// OC1A output: Discon.
// OC1B output: Discon.
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=0x00;
TCCR1B=0x00;
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer2 Stopped
// Mode: Normal top=0xFF
// OC2 output: Disconnected
ASSR=0x00;
TCCR2=0x00;
TCNT2=0x00;
OCR2=0x00;

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
MCUCR=0x00;
MCUCSR=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=0x00;

// USART initialization
// Communication Parameters: 8 Data, 1 Stop, No Parity
// USART Receiver: On
// USART Transmitter: On
// USART Mode: Asynchronous
// USART Baud Rate: 9600
UCSRA=0x00;
UCSRB=0x18;
UCSRC=0x86;
UBRRH=0x00;
UBRRL=0x33;

// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
ACSR=0x80;
SFIOR=0x00;

// ADC initialization
// ADC disabled
ADCSRA=0x00;

// SPI initialization
// SPI disabled
SPCR=0x00;

// TWI initialization
// TWI disabled
TWCR=0x00;

while (1)
      {
      a=USART_Receive();
      USART_Transmit(a);
      MODE_ONE(a);
      } 
      }
void USART_Init(unsigned char ubrr)				        /* USART initialize function */
{ 
	UCSRB |= (1<<RXEN) | (1<<TXEN);				        /* Enable USART transmitter and receiver */
    UCSRC |= (1<<URSEL)| (1<<UCSZ0) | (1 << UCSZ1);	    /* Write USCRC for 8 bit data and 1 stop bit */ 
    UBRRL = (unsigned char)ubrr;					        /* Load UBRRL with lower 8 bit of prescale value */
    UBRRH = (unsigned char)(ubrr>>8);				        	/* Load UBRRH with upper 8 bit of prescale value */
}

void USART_Transmit(unsigned char data)						/* Data transmitting function */
{
    UDR = data;										/* Write data to be transmitting in UDR */
    while (!(UCSRA & (1<<UDRE)));					/* Wait until data transmit and buffer get empty */
}

char USART_Receive(void)									/* Data receiving function */
{
	while (!(UCSRA & (1 << RXC)));					/* Wait until new data receive */
	return(UDR);									/* Get and return received data */ 
}

void MODE_ONE(unsigned char a)					/* Send string of USART data function */ 
{
if(a=='F')
    {
         PORTA.0=1;
         PORTA.1=0;
         PORTA.2=0;
         PORTA.3=1;
         delay_ms(300);                               //PORTB=0X05;
    }
else if(a=='B')
    {
        PORTA.0=0;
         PORTA.1=1;
         PORTA.2=1;
         PORTA.3=0;
         delay_ms(300);                                               //PORTB=0X0A;
    }
else if(a=='L')
    {
     PORTA.0=1;
         PORTA.1=0;
         PORTA.2=0;
         PORTA.3=0;
         delay_ms(300);                                                     //PORTB=0X04;
      }                                                                     //delay_ms(2500);
                                                                       //PORTB=0X05;
         
else if(a=='R')
    {
         PORTA.0=0;
         PORTA.1=0;
         PORTA.2=0;
         PORTA.3=1;
         delay_ms(300);                   //PORTB=0X01;
                                        //delay_ms(2500);
                                        //PORTB=0X05;
    }
    else if(a=='S')
    {
         PORTA.0=0;
         PORTA.1=0;
         PORTA.2=0;
         PORTA.3=0;
         delay_ms(300);                                          //PORTB=0X00;    
    }

}