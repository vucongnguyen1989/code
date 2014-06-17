/* chuogn trinh doc tin hieu mpu-6050
 * File:   chuong trinh chinh.c
 * Author: ANHDAO
 * trinh bien dich c32
 *
 * Created on June 16, 2014, 4:44 PM
 */

#define SYSCLK 80000000L // Give the System's clock frequency (80MHz for PIC32MX440F512H)
			 // This is general practice in order to get the best performance

#include <p32xxxx.h>	// Include PIC32 specifics header file.
#include <plib.h>	// Include the PIC32 Peripheral Library.
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "MPU6050.h"
#include "i2c.h"
#include "common.h"

#pragma config FPLLODIV = DIV_1, FPLLMUL = MUL_20, FPLLIDIV = DIV_2, FWDTEN = OFF, FCKSM = CSECME, FPBDIV = DIV_1
#pragma config OSCIOFNC = ON, POSCMOD = XT, FSOSCEN = ON, FNOSC = PRIPLL
#pragma config CP = OFF, BWP = OFF, PWP = OFF
/*
 * 
 */


void DelayMs(unsigned int msec)
{
    unsigned int tWait, tStart;
    tWait= (40000*msec);
    tStart=ReadCoreTimer();
    while((ReadCoreTimer()-tStart)<tWait);
}


int main(void)
{
        Setup_I2C();
	//SYSTEMConfigPerformance(SYSCLK);
	// Peripheral function that configures for best performance given the system's
	// clock frequency--this is for general practice.

	// This part is analogous to the void setup(){}; in Arduino.
	//TRISDCLR = 0x0100; 	// Set pin RD8 as an output, could be written as TRISD = 0xFEFF;
				// but takes more clock cycles to perform.
	//TRISESET = 0x0080;	// Set pin RE7 (PROG button) as an input, could be written as TRISE = 0x0080;
				// but takes more clock cycles to perform.

	// This part is analogous to the void loop(){}; in Arduino.
        //SDA = SCL = 0;
        //SCL_IN = SDA_IN = 0;
	Setup_MPU6050();
	Calibrate_Gyros();
        MPU6050_Test_I2C();
	while(1) 		// Loop forever...
	{

		// Reads the state of pin RE7, and latches RD8 accordingly.
		// Note that RE7 is normally set HIGH (3.3V) through an internal pull-up
		//	resistor and will actually be set LOW when the PROG button is pressed.
		// LATDbits.LATD8 = PORTEbits.RE7;
		//Get_Accel_Angles();

            //i2c_start();
           // i2c_tx(0x68);
            //i2c_start();    //ok
            //i2c_stop();
            //DelayMs(1000);
            //MPU6050_Test_I2C();
            Get_Accel_Values();
            Get_Accel_Angles();

            GetTemp();
	}

	return 0; // Included because main returns an int which is being expected.
} // Make sure the program ends in a new line

