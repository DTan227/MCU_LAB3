/*
 * display.c
 *
 *  Created on: Oct 26, 2024
 *      Author: golde
 */
#include"display.h"
int enabled_7SEG = EN0;

void display7SEG1(int num)
{
	if(num < 0 || num > 9) return;
	if(num == 1 || num == 4) HAL_GPIO_WritePin(T0_GPIO_Port, T0_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(T0_GPIO_Port, T0_Pin, GPIO_PIN_RESET);
	if(num == 5 || num == 6) HAL_GPIO_WritePin(T1_GPIO_Port, T1_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(T1_GPIO_Port, T1_Pin, GPIO_PIN_RESET);
	if(num == 2) HAL_GPIO_WritePin(T2_GPIO_Port, T2_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(T2_GPIO_Port, T2_Pin, GPIO_PIN_RESET);
	if(num == 1 || num == 4 || num == 7) HAL_GPIO_WritePin(T3_GPIO_Port, T3_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(T3_GPIO_Port, T3_Pin, GPIO_PIN_RESET);
	if(num % 2 == 1 || num == 4) HAL_GPIO_WritePin(T4_GPIO_Port, T4_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(T4_GPIO_Port, T4_Pin, GPIO_PIN_RESET);
	if(num == 1 || num == 2 || num == 3 || num == 7) HAL_GPIO_WritePin(T5_GPIO_Port, T5_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(T5_GPIO_Port, T5_Pin, GPIO_PIN_RESET);
	if(num == 0 || num == 1 || num == 7) HAL_GPIO_WritePin(T6_GPIO_Port, T6_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(T6_GPIO_Port, T6_Pin, GPIO_PIN_RESET);
}

void display7SEG2(int num)
{
	if(num < 0 || num > 9) return;
	if(num == 1 || num == 4) HAL_GPIO_WritePin(P0_GPIO_Port, P0_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(P0_GPIO_Port, P0_Pin, GPIO_PIN_RESET);
	if(num == 5 || num == 6) HAL_GPIO_WritePin(P1_GPIO_Port, P1_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(P1_GPIO_Port, P1_Pin, GPIO_PIN_RESET);
	if(num == 2) HAL_GPIO_WritePin(P2_GPIO_Port, P2_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(P2_GPIO_Port, P2_Pin, GPIO_PIN_RESET);
	if(num == 1 || num == 4 || num == 7) HAL_GPIO_WritePin(P3_GPIO_Port, P3_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(P3_GPIO_Port, P3_Pin, GPIO_PIN_RESET);
	if(num % 2 == 1 || num == 4) HAL_GPIO_WritePin(P4_GPIO_Port, P4_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(P4_GPIO_Port, P4_Pin, GPIO_PIN_RESET);
	if(num == 1 || num == 2 || num == 3 || num == 7) HAL_GPIO_WritePin(P5_GPIO_Port, P5_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(P5_GPIO_Port, P5_Pin, GPIO_PIN_RESET);
	if(num == 0 || num == 1 || num == 7) HAL_GPIO_WritePin(P6_GPIO_Port, P6_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(P6_GPIO_Port, P6_Pin, GPIO_PIN_RESET);
}

void display_7SEG_automatic()
{
	switch(enabled_7SEG)
	{
	case EN0:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		display7SEG1(countdown1 / 10);
		display7SEG2(countdown1 % 10);
		if(timer3_flag == 1)
		{
			setTimer3(500);
			enabled_7SEG = EN1;

		}
		break;
	case EN1:

		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
		display7SEG1(countdown2 / 10);
		display7SEG2(countdown2 % 10);
		if(timer3_flag == 1)
		{
			setTimer3(500);
			enabled_7SEG = EN0;
		}
		break;
	default:
		break;
	}
}
void display_7SEG_manual()
{
	switch(enabled_7SEG)
	{
	case EN0:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		display7SEG1(0);
		display7SEG2(mode);
		if(timer3_flag == 1)
		{
			setTimer3(500);
			enabled_7SEG = EN1;
		}
		break;
	case EN1:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
		display7SEG1(count / 10);
		display7SEG2(count % 10);
		if(timer3_flag == 1)
		{
			setTimer3(250);
			enabled_7SEG = EN0;
		}
		break;

	}
}


