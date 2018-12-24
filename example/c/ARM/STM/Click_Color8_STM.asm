_systemInit:
;Click_Color8_STM.c,39 :: 		void systemInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Color8_STM.c,41 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
MOVS	R2, #1
MOVS	R1, #7
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_Color8_STM.c,42 :: 		mikrobus_i2cInit( _MIKROBUS1, &_COLOR8_I2C_CFG[0] );
MOVW	R0, #lo_addr(__COLOR8_I2C_CFG+0)
MOVT	R0, #hi_addr(__COLOR8_I2C_CFG+0)
MOV	R1, R0
MOVS	R0, #0
BL	_mikrobus_i2cInit+0
;Click_Color8_STM.c,43 :: 		mikrobus_logInit( _LOG_USBUART_A, 115200 );
MOV	R1, #115200
MOVS	R0, #32
BL	_mikrobus_logInit+0
;Click_Color8_STM.c,44 :: 		mikrobus_logWrite(" --- System Init --- ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr1_Click_Color8_STM+0)
MOVT	R0, #hi_addr(?lstr1_Click_Color8_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Color8_STM.c,45 :: 		Delay_ms( 100 );
MOVW	R7, #20351
MOVT	R7, #18
NOP
NOP
L_systemInit0:
SUBS	R7, R7, #1
BNE	L_systemInit0
NOP
NOP
NOP
;Click_Color8_STM.c,46 :: 		}
L_end_systemInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _systemInit
_applicationInit:
;Click_Color8_STM.c,48 :: 		void applicationInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Color8_STM.c,50 :: 		color8_i2cDriverInit( (T_COLOR8_P)&_MIKROBUS1_GPIO, (T_COLOR8_P)&_MIKROBUS1_I2C, _COLOR8_DEF_SLAVE_ADDRESS_1 );
MOVS	R2, __COLOR8_DEF_SLAVE_ADDRESS_1
MOVW	R1, #lo_addr(__MIKROBUS1_I2C+0)
MOVT	R1, #hi_addr(__MIKROBUS1_I2C+0)
MOVW	R0, #lo_addr(__MIKROBUS1_GPIO+0)
MOVT	R0, #hi_addr(__MIKROBUS1_GPIO+0)
BL	_color8_i2cDriverInit+0
;Click_Color8_STM.c,51 :: 		color8_writeByte(_COLOR8_REG_SYSTEM_CONTROL, _COLOR8_SS_SW_RESET_IS_DONE |  _COLOR8_SS_INT_PIN_IS_ACTIVE );
MOVS	R0, __COLOR8_SS_SW_RESET_IS_DONE
ORR	R0, R0, __COLOR8_SS_INT_PIN_IS_ACTIVE
UXTB	R1, R0
MOVS	R0, __COLOR8_REG_SYSTEM_CONTROL
BL	_color8_writeByte+0
;Click_Color8_STM.c,53 :: 		_COLOR8_MC1_RGB_DATA_GAIN_X1 |
MOVS	R0, __COLOR8_MC1_IR_DATA_GAIN_X1
ORR	R0, R0, __COLOR8_MC1_RGB_DATA_GAIN_X1
UXTB	R0, R0
;Click_Color8_STM.c,54 :: 		_COLOR8_MC1_MEASURE_MODE_35ms );
ORR	R0, R0, __COLOR8_MC1_MEASURE_MODE_35ms
UXTB	R1, R0
;Click_Color8_STM.c,52 :: 		color8_writeByte(_COLOR8_REG_MODE_CONTROL_1, _COLOR8_MC1_IR_DATA_GAIN_X1 |
MOVS	R0, __COLOR8_REG_MODE_CONTROL_1
;Click_Color8_STM.c,54 :: 		_COLOR8_MC1_MEASURE_MODE_35ms );
BL	_color8_writeByte+0
;Click_Color8_STM.c,56 :: 		color8_writeByte(_COLOR8_REG_MODE_CONTROL_2, _COLOR8_MC2_MEASUREMENT_IS_ACTIVE );
MOVS	R1, __COLOR8_MC2_MEASUREMENT_IS_ACTIVE
MOVS	R0, __COLOR8_REG_MODE_CONTROL_2
BL	_color8_writeByte+0
;Click_Color8_STM.c,57 :: 		mikrobus_logWrite(" --- Start measurement ---", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr2_Click_Color8_STM+0)
MOVT	R0, #hi_addr(?lstr2_Click_Color8_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Color8_STM.c,58 :: 		}
L_end_applicationInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationInit
_applicationTask:
;Click_Color8_STM.c,60 :: 		void applicationTask()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Color8_STM.c,62 :: 		RED_data = color8_readData(_COLOR8_REG_RED_DATA);
MOVS	R0, __COLOR8_REG_RED_DATA
BL	_color8_readData+0
MOVW	R1, #lo_addr(_RED_data+0)
MOVT	R1, #hi_addr(_RED_data+0)
STRH	R0, [R1, #0]
;Click_Color8_STM.c,63 :: 		IntToStr(RED_data, demoText);
SXTH	R0, R0
MOVW	R1, #lo_addr(_demoText+0)
MOVT	R1, #hi_addr(_demoText+0)
BL	_IntToStr+0
;Click_Color8_STM.c,64 :: 		mikrobus_logWrite(" RED data : ", _LOG_TEXT);
MOVW	R0, #lo_addr(?lstr3_Click_Color8_STM+0)
MOVT	R0, #hi_addr(?lstr3_Click_Color8_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_Color8_STM.c,65 :: 		mikrobus_logWrite(demoText, _LOG_LINE);
MOVS	R1, #2
MOVW	R0, #lo_addr(_demoText+0)
MOVT	R0, #hi_addr(_demoText+0)
BL	_mikrobus_logWrite+0
;Click_Color8_STM.c,67 :: 		GREEN_data = color8_readData(_COLOR8_REG_GREEN_DATA);
MOVS	R0, __COLOR8_REG_GREEN_DATA
BL	_color8_readData+0
MOVW	R1, #lo_addr(_GREEN_data+0)
MOVT	R1, #hi_addr(_GREEN_data+0)
STRH	R0, [R1, #0]
;Click_Color8_STM.c,68 :: 		IntToStr(GREEN_data, demoText);
SXTH	R0, R0
MOVW	R1, #lo_addr(_demoText+0)
MOVT	R1, #hi_addr(_demoText+0)
BL	_IntToStr+0
;Click_Color8_STM.c,69 :: 		mikrobus_logWrite(" GREEN data : ", _LOG_TEXT);
MOVW	R0, #lo_addr(?lstr4_Click_Color8_STM+0)
MOVT	R0, #hi_addr(?lstr4_Click_Color8_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_Color8_STM.c,70 :: 		mikrobus_logWrite(demoText, _LOG_LINE);
MOVS	R1, #2
MOVW	R0, #lo_addr(_demoText+0)
MOVT	R0, #hi_addr(_demoText+0)
BL	_mikrobus_logWrite+0
;Click_Color8_STM.c,72 :: 		BLUE_data = color8_readData(_COLOR8_REG_BLUE_DATA);
MOVS	R0, __COLOR8_REG_BLUE_DATA
BL	_color8_readData+0
MOVW	R1, #lo_addr(_BLUE_data+0)
MOVT	R1, #hi_addr(_BLUE_data+0)
STRH	R0, [R1, #0]
;Click_Color8_STM.c,73 :: 		IntToStr(BLUE_data, demoText);
SXTH	R0, R0
MOVW	R1, #lo_addr(_demoText+0)
MOVT	R1, #hi_addr(_demoText+0)
BL	_IntToStr+0
;Click_Color8_STM.c,74 :: 		mikrobus_logWrite(" BLUE data : ", _LOG_TEXT);
MOVW	R0, #lo_addr(?lstr5_Click_Color8_STM+0)
MOVT	R0, #hi_addr(?lstr5_Click_Color8_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_Color8_STM.c,75 :: 		mikrobus_logWrite(demoText, _LOG_LINE);
MOVS	R1, #2
MOVW	R0, #lo_addr(_demoText+0)
MOVT	R0, #hi_addr(_demoText+0)
BL	_mikrobus_logWrite+0
;Click_Color8_STM.c,77 :: 		IR_data = color8_readData(_COLOR8_REG_IR_DATA);
MOVS	R0, __COLOR8_REG_IR_DATA
BL	_color8_readData+0
MOVW	R1, #lo_addr(_IR_data+0)
MOVT	R1, #hi_addr(_IR_data+0)
STRH	R0, [R1, #0]
;Click_Color8_STM.c,78 :: 		IntToStr(IR_data, demoText);
SXTH	R0, R0
MOVW	R1, #lo_addr(_demoText+0)
MOVT	R1, #hi_addr(_demoText+0)
BL	_IntToStr+0
;Click_Color8_STM.c,79 :: 		mikrobus_logWrite(" IR data : ", _LOG_TEXT);
MOVW	R0, #lo_addr(?lstr6_Click_Color8_STM+0)
MOVT	R0, #hi_addr(?lstr6_Click_Color8_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_Color8_STM.c,80 :: 		mikrobus_logWrite(demoText, _LOG_LINE);
MOVS	R1, #2
MOVW	R0, #lo_addr(_demoText+0)
MOVT	R0, #hi_addr(_demoText+0)
BL	_mikrobus_logWrite+0
;Click_Color8_STM.c,82 :: 		colorValue = color8_getColorValue();
BL	_color8_getColorValue+0
MOVW	R1, #lo_addr(_colorValue+0)
MOVT	R1, #hi_addr(_colorValue+0)
STR	R0, [R1, #0]
;Click_Color8_STM.c,83 :: 		FloatToStr(colorValue, demoText);
MOVW	R1, #lo_addr(_demoText+0)
MOVT	R1, #hi_addr(_demoText+0)
BL	_FloatToStr+0
;Click_Color8_STM.c,84 :: 		mikrobus_logWrite(" HSL color value : ", _LOG_TEXT);
MOVW	R0, #lo_addr(?lstr7_Click_Color8_STM+0)
MOVT	R0, #hi_addr(?lstr7_Click_Color8_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_Color8_STM.c,85 :: 		mikrobus_logWrite(demoText, _LOG_LINE);
MOVS	R1, #2
MOVW	R0, #lo_addr(_demoText+0)
MOVT	R0, #hi_addr(_demoText+0)
BL	_mikrobus_logWrite+0
;Click_Color8_STM.c,87 :: 		isColor = color8_getColor(colorValue);
MOVW	R0, #lo_addr(_colorValue+0)
MOVT	R0, #hi_addr(_colorValue+0)
LDR	R0, [R0, #0]
BL	_color8_getColor+0
MOVW	R1, #lo_addr(_isColor+0)
MOVT	R1, #hi_addr(_isColor+0)
STRB	R0, [R1, #0]
;Click_Color8_STM.c,89 :: 		switch(isColor)
IT	AL
BAL	L_applicationTask2
;Click_Color8_STM.c,91 :: 		case 1:
L_applicationTask4:
;Click_Color8_STM.c,93 :: 		mikrobus_logWrite("--- Color: ORANGE ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr8_Click_Color8_STM+0)
MOVT	R0, #hi_addr(?lstr8_Click_Color8_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Color8_STM.c,94 :: 		break;
IT	AL
BAL	L_applicationTask3
;Click_Color8_STM.c,96 :: 		case 2:
L_applicationTask5:
;Click_Color8_STM.c,98 :: 		mikrobus_logWrite("--- Color: RED ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr9_Click_Color8_STM+0)
MOVT	R0, #hi_addr(?lstr9_Click_Color8_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Color8_STM.c,99 :: 		break;
IT	AL
BAL	L_applicationTask3
;Click_Color8_STM.c,101 :: 		case 3:
L_applicationTask6:
;Click_Color8_STM.c,103 :: 		mikrobus_logWrite("--- Color: PINK ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr10_Click_Color8_STM+0)
MOVT	R0, #hi_addr(?lstr10_Click_Color8_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Color8_STM.c,104 :: 		break;
IT	AL
BAL	L_applicationTask3
;Click_Color8_STM.c,106 :: 		case 4:
L_applicationTask7:
;Click_Color8_STM.c,108 :: 		mikrobus_logWrite("--- Color: PURPLE ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr11_Click_Color8_STM+0)
MOVT	R0, #hi_addr(?lstr11_Click_Color8_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Color8_STM.c,109 :: 		break;
IT	AL
BAL	L_applicationTask3
;Click_Color8_STM.c,111 :: 		case 5:
L_applicationTask8:
;Click_Color8_STM.c,113 :: 		mikrobus_logWrite("--- Color: BLUE ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr12_Click_Color8_STM+0)
MOVT	R0, #hi_addr(?lstr12_Click_Color8_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Color8_STM.c,114 :: 		break;
IT	AL
BAL	L_applicationTask3
;Click_Color8_STM.c,116 :: 		case 6:
L_applicationTask9:
;Click_Color8_STM.c,118 :: 		mikrobus_logWrite("--- Color: CYAN ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr13_Click_Color8_STM+0)
MOVT	R0, #hi_addr(?lstr13_Click_Color8_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Color8_STM.c,119 :: 		break;
IT	AL
BAL	L_applicationTask3
;Click_Color8_STM.c,121 :: 		case 7:
L_applicationTask10:
;Click_Color8_STM.c,123 :: 		mikrobus_logWrite("--- Color: GREEN ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr14_Click_Color8_STM+0)
MOVT	R0, #hi_addr(?lstr14_Click_Color8_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Color8_STM.c,124 :: 		break;
IT	AL
BAL	L_applicationTask3
;Click_Color8_STM.c,126 :: 		case 8:
L_applicationTask11:
;Click_Color8_STM.c,128 :: 		mikrobus_logWrite("--- Color: YELLOW ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr15_Click_Color8_STM+0)
MOVT	R0, #hi_addr(?lstr15_Click_Color8_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Color8_STM.c,129 :: 		break;
IT	AL
BAL	L_applicationTask3
;Click_Color8_STM.c,131 :: 		default:
L_applicationTask12:
;Click_Color8_STM.c,133 :: 		break;
IT	AL
BAL	L_applicationTask3
;Click_Color8_STM.c,135 :: 		}
L_applicationTask2:
MOVW	R0, #lo_addr(_isColor+0)
MOVT	R0, #hi_addr(_isColor+0)
LDRB	R0, [R0, #0]
CMP	R0, #1
IT	EQ
BEQ	L_applicationTask4
MOVW	R0, #lo_addr(_isColor+0)
MOVT	R0, #hi_addr(_isColor+0)
LDRB	R0, [R0, #0]
CMP	R0, #2
IT	EQ
BEQ	L_applicationTask5
MOVW	R0, #lo_addr(_isColor+0)
MOVT	R0, #hi_addr(_isColor+0)
LDRB	R0, [R0, #0]
CMP	R0, #3
IT	EQ
BEQ	L_applicationTask6
MOVW	R0, #lo_addr(_isColor+0)
MOVT	R0, #hi_addr(_isColor+0)
LDRB	R0, [R0, #0]
CMP	R0, #4
IT	EQ
BEQ	L_applicationTask7
MOVW	R0, #lo_addr(_isColor+0)
MOVT	R0, #hi_addr(_isColor+0)
LDRB	R0, [R0, #0]
CMP	R0, #5
IT	EQ
BEQ	L_applicationTask8
MOVW	R0, #lo_addr(_isColor+0)
MOVT	R0, #hi_addr(_isColor+0)
LDRB	R0, [R0, #0]
CMP	R0, #6
IT	EQ
BEQ	L_applicationTask9
MOVW	R0, #lo_addr(_isColor+0)
MOVT	R0, #hi_addr(_isColor+0)
LDRB	R0, [R0, #0]
CMP	R0, #7
IT	EQ
BEQ	L_applicationTask10
MOVW	R0, #lo_addr(_isColor+0)
MOVT	R0, #hi_addr(_isColor+0)
LDRB	R0, [R0, #0]
CMP	R0, #8
IT	EQ
BEQ	L_applicationTask11
IT	AL
BAL	L_applicationTask12
L_applicationTask3:
;Click_Color8_STM.c,136 :: 		Delay_100ms();
BL	_Delay_100ms+0
;Click_Color8_STM.c,138 :: 		mikrobus_logWrite("  ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr16_Click_Color8_STM+0)
MOVT	R0, #hi_addr(?lstr16_Click_Color8_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Color8_STM.c,139 :: 		Delay_ms( 1000 );
MOVW	R7, #6911
MOVT	R7, #183
NOP
NOP
L_applicationTask13:
SUBS	R7, R7, #1
BNE	L_applicationTask13
NOP
NOP
NOP
;Click_Color8_STM.c,140 :: 		}
L_end_applicationTask:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationTask
_main:
;Click_Color8_STM.c,142 :: 		void main()
;Click_Color8_STM.c,144 :: 		systemInit();
BL	_systemInit+0
;Click_Color8_STM.c,145 :: 		applicationInit();
BL	_applicationInit+0
;Click_Color8_STM.c,147 :: 		while (1)
L_main15:
;Click_Color8_STM.c,149 :: 		applicationTask();
BL	_applicationTask+0
;Click_Color8_STM.c,150 :: 		}
IT	AL
BAL	L_main15
;Click_Color8_STM.c,151 :: 		}
L_end_main:
L__main_end_loop:
B	L__main_end_loop
; end of _main
