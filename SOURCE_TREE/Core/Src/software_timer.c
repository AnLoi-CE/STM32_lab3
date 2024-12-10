/*
 * software_timer.c
 *
 *  Created on: Oct 3, 2024
 *      Author: DELL
 */

#include "software_timer.h"
//#define TICK 10

int timer1_counter = 0;
int timer1_flag = 0;

int timer2_counter = 0;
int timer2_flag = 0;

int timer3_counter = 0;
int timer3_flag = 0;

int timer0_counter = 0;
int timer0_flag = 0;

void setTimer0(int duration) {
	timer0_counter = duration;
	timer0_flag = 0;
}

void setTimer1(int duration) {
	timer1_counter = duration;
	timer1_flag = 0;
}

void clearTimer1(){
	timer1_counter = 0;
	timer1_flag = 0;
}

void setTimer2(int duration){
	timer2_counter = duration;
	timer2_flag = 0;
}

void setTimer3(int duration) {
	timer3_counter = duration;
	timer3_flag = 0;
}
void timerRun(){
	if(timer1_counter > 0){
		timer1_counter--;
		if(timer1_counter <= 0){
		timer1_flag = 1;
		}
	}
	else{
		timer1_flag = 1;
	}
	if(timer2_counter >0){
			timer2_counter--;
			if(timer2_counter <= 0){
				timer2_flag = 1;
			}
		}
	else{
			timer2_flag = 1;
		}
	if (timer3_counter > 0) {
			timer3_counter--;
	        if (timer3_counter <= 0) {
	        	timer3_flag = 1;
	        }
	}
	else{
			timer3_flag = 1;
		}
	if (timer0_counter > 0) {
		timer0_counter--;
		if (timer0_counter == 0)
			timer0_flag = 1;
		}
	else{
			timer0_flag = 1;
		}
}

//void display7SEG(int num)
//{
//    HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, GPIO_PIN_SET);
//    HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_SET);
//    HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_SET);
//    HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, GPIO_PIN_SET);
//    HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, GPIO_PIN_SET);
//    HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, GPIO_PIN_SET);
//    HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, GPIO_PIN_SET);
//
//    switch(num) {
//        case 0:
//            HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, GPIO_PIN_RESET);
//            break;
//        case 1:
//            HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_RESET);
//            break;
//        case 2:
//            HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, GPIO_PIN_RESET);
//            break;
//        case 3:
//            HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, GPIO_PIN_RESET);
//            break;
//        case 4:
//            HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, GPIO_PIN_RESET);
//            break;
//        case 5:
//            HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, GPIO_PIN_RESET);
//            break;
//        case 6:
//            HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, GPIO_PIN_RESET);
//            break;
//        case 7:
//            HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_RESET);
//            break;
//        case 8:
//            HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, GPIO_PIN_RESET);
//            break;
//        case 9:
//            HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, GPIO_PIN_RESET);
//            break;
//    }
//}
//int led_buffer[4] = {1 , 5 , 0 , 8};
//void updateClockBuffer(int hour, int minute) {
//    led_buffer[0] = hour / 10;
//    led_buffer[1] = hour % 10;
//    led_buffer[2] = minute / 10;
//    led_buffer[3] = minute % 10;
//}
//
//void update7SEG(int index) {
//		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
//switch (index) {
//	case 0:
//	// Display the first 7 SEG with led_buffer [0]
//        HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
//        HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
//        HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
//        HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
//        display7SEG(led_buffer[0]);
//        break ;
//	case 1:
//	// Display the second 7 SEG with led_buffer [1]
//        HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
//        HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
//        HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
//        HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
//        display7SEG(led_buffer[1]);
//        break ;
//	case 2:
//	// Display the third 7 SEG with led_buffer [2]
//        HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
//        HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
//        HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
//        HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
//        display7SEG(led_buffer[2]);
//        break ;
//	case 3:
//	// Display the forth 7 SEG with led_buffer [3]
//        HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
//        HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
//        HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
//        HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
//        display7SEG(led_buffer[3]);
//        break ;
//	default :
//		break ;
//	}
//}
