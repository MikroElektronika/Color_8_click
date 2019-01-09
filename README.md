![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Color8 Click

- **CIC Prefix**  : COLOR8
- **Author**      : Katarina Perendic
- **Verison**     : 1.0.0
- **Date**        : sep 2018.

---

### Software Support

We provide a library for the Color8 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2583/color-8-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library initializes and defines the I2C bus driver and drivers that offer a choice for writing data in register and reads data from register.
The library includes function for configuration chip for measurement, 
function for reads one color and functions for light color value is received by calculating RGB value and conversions in HSL value.
The user also has the function ```color8_getColor()``` which checks the color of the light.


Key functions :

- ``` float color8_getColorValue() ``` - Functions for read color value in HSL
- ``` uint8_t color8_getColor(float color_value) ``` - Functions for detect colors

**Examples Description**

The application is composed of three sections :

- System Initialization - Inicializes I2C module and sets INT pin as INTPUT
- Application Initialization - Initialization driver init and device configuration for start measurement
- Application Task - (code snippet) - Reads RED, GREEEN, BLUE and IR data. 
                                      Converts data to HSL value and return detect color.
                                      For a successful color test, place a click near the color of the monitor and detect the color on the screen.

```.c
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
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2583/color-8-click) page.

Other mikroE Libraries used in the example:

- I2C

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
