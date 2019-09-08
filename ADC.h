/******************************************************************************
* File Name: ADC.h
* Description:  This file contains function Prototypes of TCD module
* Tool-Chain: IAR Systems iccrl78
*
* Modification History:
*  Created by:      PRATHYUSH  V1.0      8/august/19
*  Description:     V1.0
*
******************************************************************************/




#ifndef ADC_H
#define ADC_H



/******************************************************************************
*                      Includes
******************************************************************************/
#include<avr/io.h>
#include<avr/interrupt.h>
#include<stdint.h>

/******************************************************************************
*                      Defines and data types
******************************************************************************/
#define ADC_EN() ADCSRA|=(1<<ADEN);
#define ADC_DIS() ADCSRA&=~(1<<ADEN);


/******************************************************************************
*                      Public function prototypes
******************************************************************************/

extern void InitADC();

extern uint16_t Read_ADC();

extern void channel_select(uint8_t i);

#endif
/******************************************************************************
*                      End of File
******************************************************************************/
