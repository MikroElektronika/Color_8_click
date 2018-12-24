#line 1 "D:/Clicks_git/C/Color_8_Click/SW/example/c/ARM/STM/Click_Color8_STM.c"
#line 1 "d:/clicks_git/c/color_8_click/sw/example/c/arm/stm/click_color8_types.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"





typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;
typedef signed long long int64_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;
typedef signed long long int_least64_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;
typedef unsigned long long uint_least64_t;



typedef signed long int int_fast8_t;
typedef signed long int int_fast16_t;
typedef signed long int int_fast32_t;
typedef signed long long int_fast64_t;


typedef unsigned long int uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long long uint_fast64_t;


typedef signed long int intptr_t;
typedef unsigned long int uintptr_t;


typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
#line 1 "d:/clicks_git/c/color_8_click/sw/example/c/arm/stm/click_color8_config.h"
#line 1 "d:/clicks_git/c/color_8_click/sw/example/c/arm/stm/click_color8_types.h"
#line 19 "d:/clicks_git/c/color_8_click/sw/example/c/arm/stm/click_color8_config.h"
const uint32_t _COLOR8_I2C_CFG[ 1 ] =
{
 100000
};
#line 1 "d:/clicks_git/c/color_8_click/sw/library/__color8_driver.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"
#line 58 "d:/clicks_git/c/color_8_click/sw/library/__color8_driver.h"
extern const uint8_t _COLOR8_REG_SYSTEM_CONTROL ;
extern const uint8_t _COLOR8_REG_MODE_CONTROL_1 ;
extern const uint8_t _COLOR8_REG_MODE_CONTROL_2 ;
extern const uint8_t _COLOR8_REG_RED_DATA ;
extern const uint8_t _COLOR8_REG_RED_DATA_LSB ;
extern const uint8_t _COLOR8_REG_RED_DATA_MSB ;
extern const uint8_t _COLOR8_REG_GREEN_DATA ;
extern const uint8_t _COLOR8_REG_GREEN_DATA_LSB ;
extern const uint8_t _COLOR8_REG_GREEN_DATA_MSB ;
extern const uint8_t _COLOR8_REG_BLUE_DATA ;
extern const uint8_t _COLOR8_REG_BLUE_DATA_LSB ;
extern const uint8_t _COLOR8_REG_BLUE_DATA_MSB ;
extern const uint8_t _COLOR8_REG_IR_DATA ;
extern const uint8_t _COLOR8_REG_IR_DATA_LSB ;
extern const uint8_t _COLOR8_REG_IR_DATA_MSB ;
extern const uint8_t _COLOR8_REG_GREEN_DATA_2 ;
extern const uint8_t _COLOR8_REG_GREEN_DATA_2_LSB ;
extern const uint8_t _COLOR8_REG_GREEN_DATA_2_MSB ;
extern const uint8_t _COLOR8_REG_INTERRUPT ;
extern const uint8_t _COLOR8_REG_PERSISTENCE ;
extern const uint8_t _COLOR8_REG_THRESHOLD_HIGH_LSB ;
extern const uint8_t _COLOR8_REG_THRESHOLD_HIGH_MSB ;
extern const uint8_t _COLOR8_REG_THRESHOLD_LOW_LSB ;
extern const uint8_t _COLOR8_REG_THRESHOLD_LOW_MSB ;
extern const uint8_t _COLOR8_REG_MANUFACTURER_ID ;


extern const uint8_t _COLOR8_SS_SW_RESET_IS_NOT_DONE ;
extern const uint8_t _COLOR8_SS_SW_RESET_IS_DONE ;
extern const uint8_t _COLOR8_SS_INT_PIN_IS_NOT_ACTIVE;
extern const uint8_t _COLOR8_SS_INT_PIN_IS_ACTIVE ;


extern const uint8_t _COLOR8_MC1_IR_DATA_GAIN_X1 ;
extern const uint8_t _COLOR8_MC1_IR_DATA_GAIN_X32 ;
extern const uint8_t _COLOR8_MC1_RGB_DATA_GAIN_X1 ;
extern const uint8_t _COLOR8_MC1_RGB_DATA_GAIN_X32 ;
extern const uint8_t _COLOR8_MC1_MEASURE_MODE_120ms ;
extern const uint8_t _COLOR8_MC1_MEASURE_MODE_240ms ;
extern const uint8_t _COLOR8_MC1_MEASURE_MODE_35ms ;


extern const uint8_t _COLOR8_MC2_MEASUREMENT_IS_ACTIVE ;
extern const uint8_t _COLOR8_MC2_MEASUREMENT_IS_INACTIVE ;


extern const uint8_t _COLOR8_INT_INTERRUPT_SIGNAL_IS_ACTIVE ;
extern const uint8_t _COLOR8_INT_RED_CHANNEL ;
extern const uint8_t _COLOR8_INT_GREEN_CHANNEL ;
extern const uint8_t _COLOR8_INT_BLUE_CHANNEL ;
extern const uint8_t _COLOR8_INT_PIN_DISABLE ;
extern const uint8_t _COLOR8_INT_PIN_ENABLE ;


extern const uint8_t _COLOR8_PERSISTENCE_INT_SETTINGS_0;
extern const uint8_t _COLOR8_PERSISTENCE_INT_SETTINGS_1;
extern const uint8_t _COLOR8_PERSISTENCE_INT_SETTINGS_2;
extern const uint8_t _COLOR8_PERSISTENCE_INT_SETTINGS_3;


extern const uint8_t _COLOR8_DEF_MANUFACTURER_ID ;
extern const uint8_t _COLOR8_DEF_PART_ID ;
extern const uint8_t _COLOR8_DEF_SLAVE_ADDRESS_0 ;
extern const uint8_t _COLOR8_DEF_SLAVE_ADDRESS_1 ;
#line 139 "d:/clicks_git/c/color_8_click/sw/library/__color8_driver.h"
void color8_i2cDriverInit( const uint8_t*  gpioObj,  const uint8_t*  i2cObj, uint8_t slave);
#line 146 "d:/clicks_git/c/color_8_click/sw/library/__color8_driver.h"
void color8_gpioDriverInit( const uint8_t*  gpioObj);
#line 156 "d:/clicks_git/c/color_8_click/sw/library/__color8_driver.h"
void color8_writeByte(uint8_t reg, uint8_t _data);

uint8_t color8_readByte(uint8_t reg);
#line 166 "d:/clicks_git/c/color_8_click/sw/library/__color8_driver.h"
uint16_t color8_readData(uint8_t regData);
#line 176 "d:/clicks_git/c/color_8_click/sw/library/__color8_driver.h"
float color8_getColorValue();
#line 193 "d:/clicks_git/c/color_8_click/sw/library/__color8_driver.h"
uint8_t color8_getColor(float color_value);
#line 31 "D:/Clicks_git/C/Color_8_Click/SW/example/c/ARM/STM/Click_Color8_STM.c"
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
 mikrobus_logInit( _LOG_USBUART_A, 115200 );
 mikrobus_logWrite(" --- System Init --- ", _LOG_LINE);
 Delay_ms( 100 );
}

void applicationInit()
{
 color8_i2cDriverInit( ( const uint8_t* )&_MIKROBUS1_GPIO, ( const uint8_t* )&_MIKROBUS1_I2C, _COLOR8_DEF_SLAVE_ADDRESS_1 );
 color8_writeByte(_COLOR8_REG_SYSTEM_CONTROL, _COLOR8_SS_SW_RESET_IS_DONE | _COLOR8_SS_INT_PIN_IS_ACTIVE );
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
