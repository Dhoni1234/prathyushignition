#include <avr/io.h>
#include"ADC.h"
#include"pwm.h"
#include<stdint.h>
#include<avr/interrupt.h>

#define SET_BIT(PORT,PIN) PORT|=(1<<PIN)
#define CLR_BIT(PORT,PIN) PORT&=~(1<<PIN)
#define READ_BIT(PORT,PIN) PORT&(1<<PIN)



typedef struct
{
    volatile unsigned int FLAG_BIT:1;
    } FLAG;

FLAG  engine_flag;
int main(void)
{
   uint16_t ADC_value1;
   uint16_t ADC_value2;
   int out;


    CLR_BIT(DDRD,PD2);//engine interrupt
    CLR_BIT(DDRD,PD3);//knock
    SET_BIT(DDRD,PD7);//Engine ON Indicator
    CLR_BIT(DDRD,PC0);// speed sensor
    CLR_BIT(DDRD,PC1);// load sensor

    SET_BIT(DDRD,PD6);  // Output





    EICRA|=(1<<ISC00);
    EICRA|=(1<<ISC01);



    EIMSK|=(1<<INT0);


   InitADC();
    ADC_EN();
    PWM_in();

    sei();

 int speed_inc=0,load_inc=0;
 PWM_enable();
 while(1)
 {
   if(engine_flag.FLAG_BIT==1)
   {

      SET_BIT(PORTD,PD7);
      channel_select(0);
      ADC_value1=Read_ADC();


    channel_select(1);
    ADC_value2=Read_ADC();


   if(ADC_value1>=10&&ADC_value2>=10)
   {


    speed_inc=ADC_value1/100;

    switch(speed_inc)
    {
    	case 1:
    	out=64;
    	break;

    	case 2:
    	out=77;
    	break;

    	case 3:
    	out=90;
    	break;

        case 4:
        out=102;
        break;

        case 5:
        out=115;
        break;

        case 6:
        out=140;
        break;

        case 7:
        out=155;
        break;

        case 8:
        out=170;
        break;

        case 9:
        out=180;
        break;

        case 10:
        out=195;
        break;

        default:
        out=55;
        break;
    }


    load_inc=ADC_value2/100;
     switch(load_inc)
    {
       case 1:
       out=out-2;
       break;
       case 2:
       out=out-4;
       break;
       case 3:
       out=out-6;
       break;
       case 4:
       out=out-8;
       break;
       case 5:
       out=out-10;
       break;
       case 6:
       out=out-12;
       break;
       case 7:
       out=out-14;
       break;
       case 8:
       out=out-16;
       break;
       case 9:
       out=out-18;
       break;
       case 10:
       out=out-20;
       break;
       default:
       out=out;
       break;
    }


if(READ_BIT(PIND,PD3))
    {

    out = out - 12.75;
    }
  else out = out;
    }


}
  else {
    CLR_BIT(PORTD,PD7);
    out = 0;
}

PWM_SET(out);
 }

 return 0;
    }

ISR(INT0_vect)                                    //engine interrupt//
{

  if(engine_flag.FLAG_BIT==1)
   {
   engine_flag.FLAG_BIT=0;
   } else engine_flag.FLAG_BIT = 1;

  }













