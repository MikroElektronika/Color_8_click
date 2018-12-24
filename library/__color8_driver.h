/*
    __color8_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __color8_driver.h
@brief    Color8 Driver
@mainpage Color8 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   COLOR8
@brief      Color8 Click Driver
@{

| Global Library Prefix | **COLOR8** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **sep 2018.**      |
| Developer             | **Katarina Perendic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _COLOR8_H_
#define _COLOR8_H_

/** 
 * @macro T_COLOR8_P
 * @brief Driver Abstract type 
 */
#define T_COLOR8_P    const uint8_t*

/** @defgroup COLOR8_COMPILE Compilation Config */              /** @{ */

//  #define   __COLOR8_DRV_SPI__                            /**<     @macro __COLOR8_DRV_SPI__  @brief SPI driver selector */
   #define   __COLOR8_DRV_I2C__                            /**<     @macro __COLOR8_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __COLOR8_DRV_UART__                           /**<     @macro __COLOR8_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup COLOR8_VAR Variables */                           /** @{ */

/* Register */
extern const uint8_t _COLOR8_REG_SYSTEM_CONTROL     ;
extern const uint8_t _COLOR8_REG_MODE_CONTROL_1     ;
extern const uint8_t _COLOR8_REG_MODE_CONTROL_2     ;
extern const uint8_t _COLOR8_REG_RED_DATA           ;
extern const uint8_t _COLOR8_REG_RED_DATA_LSB       ;
extern const uint8_t _COLOR8_REG_RED_DATA_MSB       ;
extern const uint8_t _COLOR8_REG_GREEN_DATA         ;
extern const uint8_t _COLOR8_REG_GREEN_DATA_LSB     ;
extern const uint8_t _COLOR8_REG_GREEN_DATA_MSB     ;
extern const uint8_t _COLOR8_REG_BLUE_DATA          ;
extern const uint8_t _COLOR8_REG_BLUE_DATA_LSB      ;
extern const uint8_t _COLOR8_REG_BLUE_DATA_MSB      ;
extern const uint8_t _COLOR8_REG_IR_DATA            ;
extern const uint8_t _COLOR8_REG_IR_DATA_LSB        ;
extern const uint8_t _COLOR8_REG_IR_DATA_MSB        ;
extern const uint8_t _COLOR8_REG_GREEN_DATA_2       ;
extern const uint8_t _COLOR8_REG_GREEN_DATA_2_LSB   ;
extern const uint8_t _COLOR8_REG_GREEN_DATA_2_MSB   ;
extern const uint8_t _COLOR8_REG_INTERRUPT          ;
extern const uint8_t _COLOR8_REG_PERSISTENCE        ;
extern const uint8_t _COLOR8_REG_THRESHOLD_HIGH_LSB ;
extern const uint8_t _COLOR8_REG_THRESHOLD_HIGH_MSB ;
extern const uint8_t _COLOR8_REG_THRESHOLD_LOW_LSB  ;
extern const uint8_t _COLOR8_REG_THRESHOLD_LOW_MSB  ;
extern const uint8_t _COLOR8_REG_MANUFACTURER_ID    ;

/* SYSTEM_CONTROL */
extern const uint8_t _COLOR8_SS_SW_RESET_IS_NOT_DONE ;
extern const uint8_t _COLOR8_SS_SW_RESET_IS_DONE     ;
extern const uint8_t _COLOR8_SS_INT_PIN_IS_NOT_ACTIVE;
extern const uint8_t _COLOR8_SS_INT_PIN_IS_ACTIVE    ;

/* MODE_CONTROL1 */
extern const uint8_t _COLOR8_MC1_IR_DATA_GAIN_X1     ;
extern const uint8_t _COLOR8_MC1_IR_DATA_GAIN_X32    ;
extern const uint8_t _COLOR8_MC1_RGB_DATA_GAIN_X1    ;
extern const uint8_t _COLOR8_MC1_RGB_DATA_GAIN_X32   ;
extern const uint8_t _COLOR8_MC1_MEASURE_MODE_120ms  ;
extern const uint8_t _COLOR8_MC1_MEASURE_MODE_240ms  ;
extern const uint8_t _COLOR8_MC1_MEASURE_MODE_35ms   ;

/* MODE_CONTROL1 */
extern const uint8_t _COLOR8_MC2_MEASUREMENT_IS_ACTIVE   ;
extern const uint8_t _COLOR8_MC2_MEASUREMENT_IS_INACTIVE ;

/* INTERRUPT */
extern const uint8_t _COLOR8_INT_INTERRUPT_SIGNAL_IS_ACTIVE ;
extern const uint8_t _COLOR8_INT_RED_CHANNEL                ;
extern const uint8_t _COLOR8_INT_GREEN_CHANNEL              ;
extern const uint8_t _COLOR8_INT_BLUE_CHANNEL               ;
extern const uint8_t _COLOR8_INT_PIN_DISABLE                ;
extern const uint8_t _COLOR8_INT_PIN_ENABLE                 ;

/* PERSISTENCE */
extern const uint8_t _COLOR8_PERSISTENCE_INT_SETTINGS_0;
extern const uint8_t _COLOR8_PERSISTENCE_INT_SETTINGS_1;
extern const uint8_t _COLOR8_PERSISTENCE_INT_SETTINGS_2;
extern const uint8_t _COLOR8_PERSISTENCE_INT_SETTINGS_3;

/* DEFAULT */
extern const uint8_t _COLOR8_DEF_MANUFACTURER_ID ;
extern const uint8_t _COLOR8_DEF_PART_ID         ;
extern const uint8_t _COLOR8_DEF_SLAVE_ADDRESS_0 ;
extern const uint8_t _COLOR8_DEF_SLAVE_ADDRESS_1 ;

                                                                       /** @} */
/** @defgroup COLOR8_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup COLOR8_INIT Driver Initialization */              /** @{ */

#ifdef   __COLOR8_DRV_SPI__
void color8_spiDriverInit(T_COLOR8_P gpioObj, T_COLOR8_P spiObj);
#endif
#ifdef   __COLOR8_DRV_I2C__
void color8_i2cDriverInit(T_COLOR8_P gpioObj, T_COLOR8_P i2cObj, uint8_t slave);
#endif
#ifdef   __COLOR8_DRV_UART__
void color8_uartDriverInit(T_COLOR8_P gpioObj, T_COLOR8_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void color8_gpioDriverInit(T_COLOR8_P gpioObj);
                                                                       /** @} */
/** @defgroup COLOR8_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Functions for write one byte in register
 *
 * @param[in] reg    Register in which the data will be written
 * @param[in] _data  Data which be written in the register
 */
void color8_writeByte(uint8_t reg, uint8_t _data);

/**
 * @brief Functions for read one byte data from register
 *
 * @param[in] reg    Register which be read
 * @retval one byte data which is read from the register
 */
uint8_t color8_readByte(uint8_t reg);

/**
 * @brief Functions for read data from register
 *
 * @param[in] regData    Register in which the data will be written
 * @retval two byte data which is read from the register
 */
uint16_t color8_readData(uint8_t regData);

/**
 * @brief Functions for read color value
 *
 * @retval Color value in HSL
 *
 * This functions reas 3 color filters and Clear Filters and converts the resulting color from RGB to HSL
   The color range is between 0.00 and 1.0000.
 */
float color8_getColorValue();

/**
 * @brief Functions for detect colors
 *
 * @param[in] color_value  color value in HSL
 * @retval Color flag
 *
 * Detect color
      PINK color   - from 0.920  to 0.974
      PURPLE color - from 0.6201 to 0.919
      BLUE color   - from 0.521  to 0.620
      CYAN color   - from 0.430  to 0.520
      GREEN color  - from 0.300  to 0.429
      YELLOW color - from 0.019  to 0.200
      RED color    - from 0.0005 to 0.018
 */
uint8_t color8_getColor(float color_value);


                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Color8_STM.c
    @example Click_Color8_TIVA.c
    @example Click_Color8_CEC.c
    @example Click_Color8_KINETIS.c
    @example Click_Color8_MSP.c
    @example Click_Color8_PIC.c
    @example Click_Color8_PIC32.c
    @example Click_Color8_DSPIC.c
    @example Click_Color8_AVR.c
    @example Click_Color8_FT90x.c
    @example Click_Color8_STM.mbas
    @example Click_Color8_TIVA.mbas
    @example Click_Color8_CEC.mbas
    @example Click_Color8_KINETIS.mbas
    @example Click_Color8_MSP.mbas
    @example Click_Color8_PIC.mbas
    @example Click_Color8_PIC32.mbas
    @example Click_Color8_DSPIC.mbas
    @example Click_Color8_AVR.mbas
    @example Click_Color8_FT90x.mbas
    @example Click_Color8_STM.mpas
    @example Click_Color8_TIVA.mpas
    @example Click_Color8_CEC.mpas
    @example Click_Color8_KINETIS.mpas
    @example Click_Color8_MSP.mpas
    @example Click_Color8_PIC.mpas
    @example Click_Color8_PIC32.mpas
    @example Click_Color8_DSPIC.mpas
    @example Click_Color8_AVR.mpas
    @example Click_Color8_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __color8_driver.h

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