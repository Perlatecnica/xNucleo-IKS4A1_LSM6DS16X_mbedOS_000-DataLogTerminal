/*
MIT License

Copyright (c) [2024] 
Organization: Perlatecnica APS ETS
Author: Mauro D'Angelo
Example Example to use the LSM6DSV16X inertial measurement sensor

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "mbed.h"
#include "plt_iks4a1.h"

LSM6DSV16X lsm6dsv16x(I2C_SDA, I2C_SCL); 
Serial pc(USBTX, USBRX);
DigitalOut led(LED1);

int32_t accelerometer[3], anglerate[3];

void blinkLed(){
    led = 1;
    thread_sleep_for(25);
    led = 0;
    thread_sleep_for(975);
}

// main() runs in its own thread in the OS
int main()
{
    pc.baud(115200);

    pc.printf("Example to use the LSM6DSV16X inertial measurement sensor\r\n");

    lsm6dsv16x.begin();
    lsm6dsv16x.Enable_X();
    lsm6dsv16x.Enable_G();

    uint8_t id;
    lsm6dsv16x.ReadID(&id);
    pc.printf("Id = 0x%02X\n", id);

    pc.printf("Accel-X[mg]\tAccel-Y[mg]\tAccel-Z[mg]\t|AngRate-X[mdps]\t,AngRate-Y[mdps]\t,AngRate-Z[mdps] ");

    while (true) {
        lsm6dsv16x.Get_X_Axes(accelerometer);
        lsm6dsv16x.Get_G_Axes(anglerate);

        pc.printf("%d\t%d\t%d\t|%d\t%d\t%d",accelerometer[0],accelerometer[1],accelerometer[2], anglerate[0], anglerate[1], anglerate[2]);
        pc.printf("\r\n");

        blinkLed();
    }
}



