#include "i2c_QT1070.h"

namespace I2CQT1070Device
{
    // Constructor
    I2CQT1070::I2CQT1070(PinName sda, PinName scl, int address) : I2CSlave(sda, scl)
    {
        this->address(address);
        this->slave_address = address;
    }
    
    // Process instructions received from master:
    // write -> set the register to be accessed
    // read -> return the value from set register
    void I2CQT1070::check_for_instruction()
    {
        int addressed = receive();
        
        switch (addressed)
        {
            case I2CSlave::ReadAddressed:
                printf("Read addressed\r\n");
                send_data_to_master();
                break;
            case I2CSlave::WriteAddressed:
                printf("Write addressed\r\n");
                set_register();
                break;
        }
    }
    
    // Return the value from selected register
    void I2CQT1070::send_data_to_master()
    {
        char value = 0;
        
        switch(_register)
        {
            case CHIP_ID:                       // returns chip id
                value = qt1070.getChipId();
                break;
            case FIRMWARE:                      // returns firmware version
                value = qt1070.getFirmware();
                break;
            case KEY_STAT:                      // returns buttonstates
                value = qt1070.getKeyStatus();
                break;
        }
        
        send_data(value);
    }
    
    // set the register and stop the transaction
    void I2CQT1070::set_register()
    {
        char next_address = this->read();
        
        // if address equal to reset register
        if ( next_address == RESET)
        {
            // reset the device
            qt1070.software_reset();
        }
        else
        {
            // set the register to be accessed
            _register = next_address;
            printf("Register set!");
        }
        
        this->stop();
    }
    
    // send the data
    void I2CQT1070::send_data(int data)
    {
        char buffer[1];
        buffer[0] = data;
        
        if(!write(buffer, 1))
            printf("Data send to master succesfully\r\n");
        else
            printf("Data did not send succesfully\r\n");
    }
};