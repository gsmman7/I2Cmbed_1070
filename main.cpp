#include "mbed.h"
#include "i2c_QT1070.h"

DigitalOut myled(LED1);

using namespace I2CQT1070Device;

int main()
{
    I2CQT1070 i2c_qt(p9, p10);
    
    int cycleCounter = 0;
    
    while(1)
    {        
        i2c_qt.check_for_instruction();
        
        if(cycleCounter++ >= 500000)
        {
            myled = !myled;
            cycleCounter = 0;
        }
    }
}