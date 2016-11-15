#pragma once

#include "mbed.h"
#include "QT1070.h"

namespace I2CQT1070Device
{    
    class I2CQT1070 : public I2CSlave
    {
        private:
            int slave_address, _register;
        
        private:
            QT1070 qt1070;
        
        public:
            I2CQT1070(PinName sda, PinName scl, int address = 0x36);
        
        public:
            void check_for_instruction();
        
        private:
            void send_data_to_master();
            void set_register();
            void send_data(int data);
    };
};