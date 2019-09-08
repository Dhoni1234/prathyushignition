
/******************************************************************************
* File Name: ADC.c
* Description:  This file contains function Prototypes of TCD module
* Tool-Chain:  WinAVR-20100110
*
* Modification History:
*  Created by:      PRATHYUSH   V1.0      8/august/19
*  Description:     V1.0
*
******************************************************************************/



/******************************************************************************
*                      Includes
******************************************************************************/

#include"ADC.h"
#include <avr/io.h>
#define SET_BIT(PORT,PIN) PORT|=(1<<PIN)
#define CLR_BIT(PORT,PIN) PORT&=~(1<<PIN)
#define READ_BIT(PORT,PIN) PORT&(1<<PIN)




/******************************************************************************
*                      Public functions
******************************************************************************/

/******************************************************************************
* Name: void InitADC(void)
* Description:  Initializes registers for ADC conversion

* Arguments: None
* Returns: None
******************************************************************************/
void InitADC()
{

// Select Vref=AVcc
  CLR_BIT(ADMUX,REFS1);
  SET_BIT(ADMUX,REFS0);
  ADCSRA|= (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0); //set pre-scaler to 128
}




/******************************************************************************
* Name: void Read_ADC(void)
* Description:  converts analog to digital value and returns it.

* Arguments: None
* Returns: ADC_value
******************************************************************************/

uint16_t Read_ADC()
{   uint16_t ADC_value=0;
    ADCSRA|= (1<< ADSC);
     while(ADCSRA&(1<<ADSC));
        ADC_value=ADC;
      return ADC_value;
}

 void channel_select(uint8_t i)
{
    if (i==0)
    {


     CLR_BIT(ADMUX,MUX0);
     CLR_BIT(ADMUX,MUX1);
     CLR_BIT(ADMUX,MUX2);
     CLR_BIT(ADMUX,MUX3);

    }
     if (i==1)
    {


     SET_BIT(ADMUX,MUX0);
     CLR_BIT(ADMUX,MUX1);
     CLR_BIT(ADMUX,MUX2);
     CLR_BIT(ADMUX,MUX3);

    }
    }

 /******************************************************************************
*                      End of File
******************************************************************************/
