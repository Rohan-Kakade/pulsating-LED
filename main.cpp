/*Program to make gradually increase an LED's brightness
Uses PWM
#include "mbed.h"

int main() 
{
    //Declare a PwmOut object
    PwmOut pwm(D3);  //D3 pin to generate pwm signal

    while(true) //run forever
    {
        //loop to gradually increase the brightness
        for (int i=0;i<20;++i) //20 brightness levels
        {
         pwm =i*0.05; //duty cycle changes by 5% each iteration
         thread_sleep_for(50); //50 ms delay between duty cyele change
        }
        // while(true) { sleep(); }
    }

}
