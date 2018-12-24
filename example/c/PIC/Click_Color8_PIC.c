/*
Example for Color8 Click

    Date          : sep 2018.
    Author        : Katarina Perendic

Test configuration PIC :
    
    MCU             : P18F87K22
    Dev. Board      : EasyPIC PRO v7
    PIC Compiler ver : v7.2.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Inicializes I2C module and sets INT pin as INTPUT
- Application Initialization - Initialization driver init and device configuration for start measurement
- Application Task - (code snippet) - Reads RED, GREEEN, BLUE and IR data. 
                                      Converts data to HSL value and return detect color.
                                      For a successful color test, place a click near the color of the monitor and detect the color on the screen.
*/

#include "Click_Color8_types.h"
#include "Click_Color8_config.h"

uint16_t RED_data;
uint16_t GREEN_data;
uint16_t BLUE_data;
uint16_t IR_data;
char demoText[ 50 ];
uint8_t isColor;
float colorValue;

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
    mikrobus_i2cInit( _MIKROBUS1, &_COLOR8_I2C_CFG[0] );
    mikrobus_logInit( _LOG_USBUART, 115200 );
    mikrobus_logWrite(" --- System Init --- ", _LOG_LINE);
    Delay_ms( 100 );
}

void applicationInit()
{
    color8_i2cDriverInit( (T_COLOR8_P)&_MIKROBUS1_GPIO, (T_COLOR8_P)&_MIKROBUS1_I2C, _COLOR8_DEF_SLAVE_ADDRESS_1 );
    color8_writeByte(_COLOR8_REG_SYSTEM_CONTROL, _COLOR8_SS_SW_RESET_IS_DONE |  _COLOR8_SS_INT_PIN_IS_ACTIVE );
    color8_writeByte(_COLOR8_REG_MODE_CONTROL_1, _COLOR8_MC1_IR_DATA_GAIN_X1 |
                                                 _COLOR8_MC1_RGB_DATA_GAIN_X1 |
                                                 _COLOR8_MC1_MEASURE_MODE_35ms );
     
    color8_writeByte(_COLOR8_REG_MODE_CONTROL_2, _COLOR8_MC2_MEASUREMENT_IS_ACTIVE );
    mikrobus_logWrite(" --- Start measurement ---", _LOG_LINE);
}

void applicationTask()
{
    RED_data = color8_readData(_COLOR8_REG_RED_DATA);
    IntToStr(RED_data, demoText);
    mikrobus_logWrite(" RED data : ", _LOG_TEXT);
    mikrobus_logWrite(demoText, _LOG_LINE);
    
    GREEN_data = color8_readData(_COLOR8_REG_GREEN_DATA);
    IntToStr(GREEN_data, demoText);
    mikrobus_logWrite(" GREEN data : ", _LOG_TEXT);
    mikrobus_logWrite(demoText, _LOG_LINE);
    
    BLUE_data = color8_readData(_COLOR8_REG_BLUE_DATA);
    IntToStr(BLUE_data, demoText);
    mikrobus_logWrite(" BLUE data : ", _LOG_TEXT);
    mikrobus_logWrite(demoText, _LOG_LINE);
    
    IR_data = color8_readData(_COLOR8_REG_IR_DATA);
    IntToStr(IR_data, demoText);
    mikrobus_logWrite(" IR data : ", _LOG_TEXT);
    mikrobus_logWrite(demoText, _LOG_LINE);
    
    colorValue = color8_getColorValue();
    FloatToStr(colorValue, demoText);
    mikrobus_logWrite(" HSL color value : ", _LOG_TEXT);
    mikrobus_logWrite(demoText, _LOG_LINE);
    
    isColor = color8_getColor(colorValue);
    
    switch(isColor)
    {
        case 1:
        {
            mikrobus_logWrite("--- Color: ORANGE ", _LOG_LINE);
            break;
        }
        case 2:
        {
            mikrobus_logWrite("--- Color: RED ", _LOG_LINE);
            break;
        }
        case 3:
        {
            mikrobus_logWrite("--- Color: PINK ", _LOG_LINE);
            break;
        }
        case 4:
        {
            mikrobus_logWrite("--- Color: PURPLE ", _LOG_LINE);
            break;
        }
        case 5:
        {
            mikrobus_logWrite("--- Color: BLUE ", _LOG_LINE);
            break;
        }
        case 6:
        {
            mikrobus_logWrite("--- Color: CYAN ", _LOG_LINE);
            break;
        }
        case 7:
        {
            mikrobus_logWrite("--- Color: GREEN ", _LOG_LINE);
            break;
        }
        case 8:
        {
            mikrobus_logWrite("--- Color: YELLOW ", _LOG_LINE);
            break;
        }
        default:
        {
            break;
        }
    }
    Delay_100ms();
    
    mikrobus_logWrite("  ", _LOG_LINE);
    Delay_ms( 1000 );
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}