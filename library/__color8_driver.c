/*
    __color8_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__color8_driver.h"
#include "__color8_hal.c"

/* ------------------------------------------------------------------- MACROS */

/* Register */
const uint8_t _COLOR8_REG_SYSTEM_CONTROL     = 0x40;
const uint8_t _COLOR8_REG_MODE_CONTROL_1     = 0x41;
const uint8_t _COLOR8_REG_MODE_CONTROL_2     = 0x42;
const uint8_t _COLOR8_REG_RED_DATA           = 0x50;
const uint8_t _COLOR8_REG_RED_DATA_LSB       = 0x50;
const uint8_t _COLOR8_REG_RED_DATA_MSB       = 0x51;
const uint8_t _COLOR8_REG_GREEN_DATA         = 0x52;
const uint8_t _COLOR8_REG_GREEN_DATA_LSB     = 0x52;
const uint8_t _COLOR8_REG_GREEN_DATA_MSB     = 0x53;
const uint8_t _COLOR8_REG_BLUE_DATA          = 0x54;
const uint8_t _COLOR8_REG_BLUE_DATA_LSB      = 0x54;
const uint8_t _COLOR8_REG_BLUE_DATA_MSB      = 0x55;
const uint8_t _COLOR8_REG_IR_DATA            = 0x58;
const uint8_t _COLOR8_REG_IR_DATA_LSB        = 0x58;
const uint8_t _COLOR8_REG_IR_DATA_MSB        = 0x59;
const uint8_t _COLOR8_REG_GREEN_DATA_2       = 0x5A;
const uint8_t _COLOR8_REG_GREEN_DATA_2_LSB   = 0x5A;
const uint8_t _COLOR8_REG_GREEN_DATA_2_MSB   = 0x5B;
const uint8_t _COLOR8_REG_INTERRUPT          = 0x60;
const uint8_t _COLOR8_REG_PERSISTENCE        = 0x61;
const uint8_t _COLOR8_REG_THRESHOLD_HIGH_LSB = 0x62;
const uint8_t _COLOR8_REG_THRESHOLD_HIGH_MSB = 0x63;
const uint8_t _COLOR8_REG_THRESHOLD_LOW_LSB  = 0x64;
const uint8_t _COLOR8_REG_THRESHOLD_LOW_MSB  = 0x65;
const uint8_t _COLOR8_REG_MANUFACTURER_ID    = 0x92;

/* SYSTEM_CONTROL */
const uint8_t _COLOR8_SS_SW_RESET_IS_NOT_DONE  = 0x00;
const uint8_t _COLOR8_SS_SW_RESET_IS_DONE      = 0x80;
const uint8_t _COLOR8_SS_INT_PIN_IS_NOT_ACTIVE = 0x00;
const uint8_t _COLOR8_SS_INT_PIN_IS_ACTIVE     = 0x40;

/* MODE_CONTROL1 */
const uint8_t _COLOR8_MC1_IR_DATA_GAIN_X1     = 0x20;
const uint8_t _COLOR8_MC1_IR_DATA_GAIN_X32    = 0x60;
const uint8_t _COLOR8_MC1_RGB_DATA_GAIN_X1    = 0x08;
const uint8_t _COLOR8_MC1_RGB_DATA_GAIN_X32   = 0x18;
const uint8_t _COLOR8_MC1_MEASURE_MODE_120ms  = 0x02;
const uint8_t _COLOR8_MC1_MEASURE_MODE_240ms  = 0x03;
const uint8_t _COLOR8_MC1_MEASURE_MODE_35ms   = 0x05;

/* MODE_CONTROL1 */
const uint8_t _COLOR8_MC2_MEASUREMENT_IS_ACTIVE   = 0x10;
const uint8_t _COLOR8_MC2_MEASUREMENT_IS_INACTIVE = 0x00;

/* INTERRUPT */
const uint8_t _COLOR8_INT_INTERRUPT_SIGNAL_IS_ACTIVE = 0x80;
const uint8_t _COLOR8_INT_RED_CHANNEL                = 0x00;
const uint8_t _COLOR8_INT_GREEN_CHANNEL              = 0x02;
const uint8_t _COLOR8_INT_BLUE_CHANNEL               = 0x04;
const uint8_t _COLOR8_INT_PIN_DISABLE                = 0x00;
const uint8_t _COLOR8_INT_PIN_ENABLE                 = 0x01;

/* PERSISTENCE */
const uint8_t _COLOR8_PERSISTENCE_INT_SETTINGS_0 = 0x00;
const uint8_t _COLOR8_PERSISTENCE_INT_SETTINGS_1 = 0x01;
const uint8_t _COLOR8_PERSISTENCE_INT_SETTINGS_2 = 0x02;
const uint8_t _COLOR8_PERSISTENCE_INT_SETTINGS_3 = 0x03;

/* DEFAULT */
const uint8_t _COLOR8_DEF_MANUFACTURER_ID = 0xE0;
const uint8_t _COLOR8_DEF_PART_ID         = 0x0D;
const uint8_t _COLOR8_DEF_SLAVE_ADDRESS_0 = 0x38;
const uint8_t _COLOR8_DEF_SLAVE_ADDRESS_1 = 0x39;

/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __COLOR8_DRV_I2C__
static uint8_t _slaveAddress;
#endif

/* Color FLAG */
static uint8_t _ORANGE_COLOR_FLAG = 1;
static uint8_t _RED_COLOR_FLAG    = 2;
static uint8_t _PINK_COLOR_FLAG   = 3;
static uint8_t _PURPLE_COLOR_FLAG = 4;
static uint8_t _BLUE_COLOR_FLAG   = 5;
static uint8_t _CYAN_COLOR_FLAG   = 6;
static uint8_t _GREEN_COLOR_FLAG  = 7;
static uint8_t _YELLOW_COLOR_FLAG = 8;
static uint8_t _NON_COLOR_FLAG    = 0;

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */

static float _maxColor( float color_A, float color_B );
static float _minColor( float color_A, float color_B );
static float _RGB_To_HSL(float red, float green, float blue) ;

/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */

static float _maxColor( float color_A, float color_B )
{
    if(color_A > color_B)
    {
        return color_A;
    }
    else
    {
        return color_B;
    }
}

static float _minColor( float color_A, float color_B )
{
    if(color_A < color_B)
    {
        return color_A;
    }
    else
    {
        return color_B;
    }
}

static float _RGB_To_HSL(float red, float green, float blue)
{
    float fmax;
    float fmin;
    float Hue_Value;
    float Saturation_Value;
    float Luminance_Value;

    fmax = _maxColor(_maxColor(red, green), blue);
    fmin = _minColor(_minColor(red, green), blue);

    Luminance_Value = fmax;

    if (fmax > 0)
    {
        Saturation_Value = (fmax - fmin) / fmax;
    }
    else
    {
        Saturation_Value = 0;
    }

    if (Saturation_Value == 0)
    {
        Hue_Value = 0;
    }
    else
    {
        if (fmax == red)
        {
             Hue_Value = (green - blue) / (fmax - fmin);
        }
        else if (fmax == green)
        {
             Hue_Value = 2 + (blue - red) / (fmax - fmin);
        }
        else
        {
             Hue_Value = 4 + (red - green) / (fmax - fmin);
        }
        Hue_Value = Hue_Value / 6;

        if (Hue_Value < 0)
        {
             Hue_Value = Hue_Value + 1;
        }
    }
    return Hue_Value;
}

/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __COLOR8_DRV_SPI__

void color8_spiDriverInit(T_COLOR8_P gpioObj, T_COLOR8_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __COLOR8_DRV_I2C__

void color8_i2cDriverInit(T_COLOR8_P gpioObj, T_COLOR8_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __COLOR8_DRV_UART__

void color8_uartDriverInit(T_COLOR8_P gpioObj, T_COLOR8_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif

/* ----------------------------------------------------------- IMPLEMENTATION */

void color8_writeByte(uint8_t reg, uint8_t _data)
{
    uint8_t writeReg[ 2 ];

    writeReg[ 0 ] = reg;
    writeReg[ 1 ] = _data;
    
    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, writeReg, 2, END_MODE_STOP);
}

uint8_t color8_readByte(uint8_t reg)
{
    uint8_t writeReg[ 1 ];
    uint8_t readReg[ 1 ];
    
    writeReg[ 0 ] = reg;
    
    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, writeReg, 1, END_MODE_RESTART);
    hal_i2cRead(_slaveAddress, readReg, 1, END_MODE_STOP);

    return readReg[ 0 ];
}

uint8_t color8_getInterrupt()
{
    return hal_gpio_intGet();
}

uint16_t color8_readData(uint8_t regData)
{
    uint16_t readData;
    
    readData = color8_readByte(regData + 1);
    readData <<= 8;
    readData |= color8_readByte(regData);

    return readData;
}

float color8_getColorValue()
{
    float Red_Ratio;
    float Green_Ratio;
    float Blue_Ratio;

    float ColorData;
    float sumColor;
    uint8_t counter;

    for (counter = 0; counter < 16; counter++)
    {
        Red_Ratio = color8_readData(_COLOR8_REG_RED_DATA);
        Green_Ratio = color8_readData(_COLOR8_REG_GREEN_DATA);
        Blue_Ratio = color8_readData(_COLOR8_REG_BLUE_DATA);

        ColorData = _RGB_To_HSL(Red_Ratio, Green_Ratio, Blue_Ratio);
        sumColor = sumColor + ColorData;
    }
    sumColor = sumColor / 16.0;

    return sumColor;
}

uint8_t color8_getColor(float color_value)
{
     if ((color_value >= 0.920) && (color_value <= 0.9749))
     {
         return _PINK_COLOR_FLAG;
     }
     else if ((color_value >= 0.6201) && (color_value <= 0.919))
     {
         return _PURPLE_COLOR_FLAG;
     }
     else if ((color_value >= 0.521) && (color_value <= 0.6200))
     {
         return _BLUE_COLOR_FLAG;
     }
     else if ((color_value >= 0.430) && (color_value < 0.520))
     {
         return _CYAN_COLOR_FLAG;
     }
     else if ((color_value >= 0.300) && (color_value <= 0.429))
     {
         return _GREEN_COLOR_FLAG;
     }
     else if ((color_value >= 0.205) && (color_value <= 0.299))
     {
         return _YELLOW_COLOR_FLAG;
     }
     else if((color_value >= 0.019) && (color_value <= 0.200))
     {
         return _ORANGE_COLOR_FLAG;
     }
     else if ((color_value >= 0.0005) && (color_value <= 0.018))
     {
         return _RED_COLOR_FLAG;
     }
     return _NON_COLOR_FLAG;
}

/* -------------------------------------------------------------------------- */
/*
  __color8_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */