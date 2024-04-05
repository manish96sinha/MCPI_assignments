/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#include "lis3dsh.h"
#include "led.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	int ret;
	LIS_Data val;
	SystemInit();
	LedInit(LED_GREEN);
	LedInit(LED_ORANGE);
	LedInit(LED_RED);
	LedInit(LED_BLUE);

	LIS_Init();
	DelayMs(1000);
	while(1) {
		ret = LIS_DRdy();
		if(ret)
		{
			val = LIS_GetData();
			if(val.x < -6000 &&  val.y < -300)
				LedBlink(LED_GREEN,100);
			if(val.x > 9000 &&  val.y < -300)
				LedBlink(LED_RED,100);
			if(val.x > 300 &&  val.y < -6000)
				LedBlink(LED_BLUE,100);
			if(val.x > 500 &&  val.y > 3000)
				LedBlink(LED_ORANGE,100);
		}
	}
	return 0;
}
