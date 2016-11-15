#include "QT1070.h"

// Map hardware
BusIn buttons(p12, p15, p13, p16, p14);

namespace I2CQT1070Device
{
    // Constructor
    QT1070::QT1070(char chip_ID, char firmware_version)
    {
        this->chip_ID = chip_ID;
        this->firmware_version = firmware_version;
    }
    
    // Returns Chip_ID
    char QT1070::getChipId()
    {
        printf("Chip ID: %d\r\n", chip_ID);
        return chip_ID;
    }
    
    // Returns Firmware_version
    char QT1070::getFirmware()
    {
        printf("Firmware: %d\r\n", firmware_version);
        return firmware_version;
    }
    
    // Returns all keystates
    char QT1070::getKeyStatus()
    {
        printf("Keystatus: %d\r\n", (char)buttons);
        return buttons;
    }
    
    // Resets mbed
    void QT1070::software_reset()
    {
        NVIC_SystemReset();
        printf("Device has been reset");
    }
};