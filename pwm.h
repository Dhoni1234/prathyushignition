
/******************************************************************************
* File Name: pwm.h
* Description:  This file contains function Prototypes of TCD module
* Tool-Chain:  WinAVR-20100110
*
* Modification History:
*  Created by:      PRATHYUSH   V1.0      8/august/19
*  Description:     V1.0
*
******************************************************************************/

#ifndef pwm_H
#define pwm_H




/******************************************************************************
*                      Includes
******************************************************************************/

#include<avr/io.h>
#include<avr/interrupt.h>
#include<stdint.h>
#include<util/delay.h>



/******************************************************************************
*                      Public function prototypes
******************************************************************************/


extern void PWM_in();
extern void PWM_SET(uint8_t);
extern void PWM_disable();
extern void PWM_enable();


#endif
/******************************************************************************
*                      End of File
******************************************************************************/

