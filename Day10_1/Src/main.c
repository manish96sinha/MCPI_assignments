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
#include "uart.h"
#include "rtc.h"


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	char str1[26], str2[20];
	RTC_Date d, dt = { .Date = 28, .Month = 02, .Year = 24, .WeekDay = 3 };
	RTC_Time t, tm = { .Hours = 23, .Minutes = 59, .Seconds = 50 };

	SystemInit();
	UartInit(BAUD_9600);
	RTC_Init(&dt, &tm);
	while(1)
	{
		RTC_GetTime(&t);
		RTC_GetDate(&d);
		sprintf(str1, "DT=%02d-%02d-%02d W=%d", d.Date, d.Month, d.Year, d.WeekDay);
		sprintf(str2, "TM=%02d:%02d:%02d\r", t.Hours, t.Minutes, t.Seconds);
		UartPuts(str1);
		UartPuts(str2);
		DelayMs(1000);
	}
	return 0;
}
