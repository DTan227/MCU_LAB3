/*
 * global.c
 *
 *  Created on: Oct 26, 2024
 *      Author: golde
 *
 */
#include"global.h"
int count=0;
int mode=1;
int countdown1 = 0;
int countdown2 = 0;
int status1 = INIT;
int status2 = INIT;
int timer_red = 5000;
int timer_yellow = 2000;
int timer_green = 3000;
void start()
{
	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_SET);
}
