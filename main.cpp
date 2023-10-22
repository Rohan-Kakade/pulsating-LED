/*Program to make gradually increase an LED's brightness
Uses PWM*/
#include "mbed.h"

//Declare a DigitalIn object
DigitalIn button(BUTTON1);

//Declare a PwmOut object
PwmOut pwm(D3);  //D3 pin to generate pwm signal

//function to set brigtness level
void led_brightness_set(int brightnesslevel)
{
    pwm = 0.1*brightnesslevel;
}

int main() 
{
    int presscount = 0;
    
    while(true) //run forever
    {
        if(button==false)
        {
            thread_sleep_for(100); //recheck if button is pressed after 100ms to discount invalid button presses
            if(button == false)
            {
                presscount++;
                led_brightness_set(presscount); //led brigtness scaled by number of button presses
                if (presscount >10)
                {
                    presscount = 0;
                }
           
            }   

        }

    }
}
