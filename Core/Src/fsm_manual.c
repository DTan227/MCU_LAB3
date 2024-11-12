/*
 * fsm_manual.c
 *
 *  Created on:Oct 26, 2024
 *      Author:golde
 */

#include "fsm_manual.h"
void fsm_manual_run(){

	switch(mode)
		  {
		  case 1:  //autorun
			  fsm_automatic_run();
			  display_7SEG_automatic();
			  if(isButton1Pressed()==1){
				setTimer2(500);
				mode = 2;
				count=1;
				start();
				setTimer3(500);
				}
				 break;
		  case 2:  //red light

				if(timer2_flag == 1){
					setTimer2(500);
					HAL_GPIO_TogglePin(R1_GPIO_Port,R1_Pin);
					HAL_GPIO_TogglePin(R2_GPIO_Port,R2_Pin);
				}
				if(isButton2Pressed() == 1){
					count++;
					if (count > 99) { count = 0; }
				}
				if(isButton3Pressed() == 1){

					timer_red=count*1000;
					count =1;
				}
				  //fsm_manual_run();
				  display_7SEG_manual();
				 if(isButton1Pressed()==1){
					setTimer2(500);
					mode = 3;
					count=1;
					HAL_GPIO_WritePin(R1_GPIO_Port,R1_Pin,1);
					HAL_GPIO_WritePin(R2_GPIO_Port,R2_Pin,1);
				}
				  break;
		  case 3:  // yellow light
			 if(timer2_flag == 1){
					setTimer2(500);
					HAL_GPIO_TogglePin(Y1_GPIO_Port,Y1_Pin);
					HAL_GPIO_TogglePin(Y2_GPIO_Port,Y2_Pin);
				}
			 if(isButton2Pressed() == 1){
						count++;
						if (count > 99) { count = 0; }
					}
			 if(isButton3Pressed() == 1){
				timer_yellow=count*1000;
				count =1;
			}
			  //fsm_manual_run();
			  display_7SEG_manual();
		     if(isButton1Pressed() == 1){
				setTimer2(500);
				mode = 4;
				count=1;
				HAL_GPIO_WritePin(Y1_GPIO_Port,Y1_Pin,1);
				HAL_GPIO_WritePin(Y2_GPIO_Port,Y2_Pin,1);
				}
			  break;
		  case 4:  //green light
			  if(timer2_flag == 1){
				setTimer2(500);
				HAL_GPIO_TogglePin(G1_GPIO_Port,G1_Pin);
				HAL_GPIO_TogglePin(G2_GPIO_Port,G2_Pin);
			   }
			  if(isButton2Pressed() == 1){
				count++;
				if (count > 99) { count = 0; }
			   }
			  if(isButton3Pressed() == 1){
				timer_green=count*1000;
				count =1;
			   }
			  //fsm_manual_run();
			  display_7SEG_manual();
			  if(isButton1Pressed() == 1){
				mode=1;
				count=1;
				status1= INIT;
				status2= INIT;
				HAL_GPIO_WritePin(G1_GPIO_Port,G1_Pin,1);
				HAL_GPIO_WritePin(G2_GPIO_Port,G2_Pin,1);
			  }
			  break;
		  default:
			  mode = 1;
			  break;
		  }
}
