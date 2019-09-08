/******************************************************************************
* File Name: pwm.c
* Description:  This file contains function Prototypes of TCD module
* Tool-Chain:  WinAVR-20100110
*
* Modification History:
*  Created by:     PRATHYUSH  V1.0      8/August/19
*  Description:     V1.0
*
******************************************************************************/



/******************************************************************************
*                      Includes
******************************************************************************/
#include "pwm.h"
#include <avr/io.h>


/******************************************************************************
*                      Public functions
******************************************************************************/

/******************************************************************************
* Name: void PWM_in(void)
* Description:  Initializes registers for fast PWM Mode

* Arguments: None
* Returns: None
******************************************************************************/
void PWM_in(){



TCCR0A|=((1<<WGM01)|(1<<WGM00));

TCCR0A|=(1<<COM0A1);
TCCR0A&=~(1<<COM0A0);


TCNT0=0x00;

OCR0A=0x00;



sei();

}


/******************************************************************************
* Name: void PWM_SET(uint8_t value)
* Description:  Sets PWM duty cycle

* Arguments: Duty cycle in percentage
* Returns: None
******************************************************************************/

void PWM_SET( uint8_t value)
{
    OCR0A=value;
    _delay_ms(500);
    OCR0A=value;
    _delay_ms(500);
        }









/******************************************************************************
* Name: void PWM_enable(void)
* Description:  Enables PWM

* Arguments: None
* Returns: None
******************************************************************************/


void PWM_enable()
{
TCCR0B|=((1<<CS02)|(1<<CS00));
TCCR0B&=~(1<<CS01);


        }





/******************************************************************************
* Name: void PWM_disable(void)
* Description:  Disables PWM

* Arguments: None
* Returns: None
******************************************************************************/


void PWM_disable()
{

TCCR0B&=0X00;

}


/******************************************************************************
*                      End of File
******************************************************************************/
