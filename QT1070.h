#pragma once

#include "mbed.h"

namespace I2CQT1070Device
{
    // Currently not in use
    enum DetectionStatus
    {
        TOUCH,
        OVERFLOW = 6,
        CALIBRATE
    };
    
    // Register values
    enum Registers
    {
        CHIP_ID,
        FIRMWARE,
        DETECTION_STAT,
        KEY_STAT,
        RESET = 0x57
    };

    class QT1070
    {
        private:
            char chip_ID, firmware_version;
            
        public:
            QT1070(char chipID = 0x2E, char firmwareVersion = 0x01);
            
        public:
            char getChipId();
            char getFirmware();
            char getKeyStatus();
            void software_reset();
    };
};