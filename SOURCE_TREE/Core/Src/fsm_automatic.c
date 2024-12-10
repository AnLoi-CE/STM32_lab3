/*
 * fsm_automatic.c
 *
 *  Created on: Nov 14, 2024
 *      Author: DELL
 */
#include "fsm_automatic.h"
#include "traffic_light.h"
#include "global.h"

int countdown_timer1 = 0;
int countdown_timer2 = 0;
int index_led = 0;
const int MAX_LED = 4;

void fsm_automatic_run(){
	switch(status){
		case INIT:
			status = AUTO_RED_GREEN;
			countdown_timer1 = red_time;
			countdown_timer2 = green_time;
			setTimer1(100);					//chuyen trang thai
			setTimer2(1);							//quet led
			clearTrafficLight();
			updateClockBuffer(countdown_timer1, countdown_timer2);
			break;

		case AUTO_RED_GREEN:
			ledRedGreen();
			if(timer2_flag == 1){
				setTimer2(25);
				update7SEG(index_led);
				index_led = (index_led + 1) % MAX_LED;
			}
			if (timer1_flag == 1) {
				countdown_timer1--;
				countdown_timer2--;
				updateClockBuffer(countdown_timer1, countdown_timer2);
				setTimer1(100);
				if(countdown_timer1 == 0){
					countdown_timer1 = red_time;
				}
				if(countdown_timer2 == 0){
					countdown_timer2 = yellow_time;
					status = AUTO_RED_YELLOW;
					clearTrafficLight();
					updateClockBuffer(countdown_timer1, countdown_timer2);
					setTimer1(100);
				}
			}

			if (isButtonPressed(1)) {
				status = MAN_RED_GREEN;
				clearTrafficLight();
			}
			 if (isButtonPressed(0)) {
				status = MODE_2;
				setTimer3(1);
				temp_time = 1;
				clearTrafficLight();
			 }
			break;
		case AUTO_RED_YELLOW:
			ledRedYellow();
			if(timer2_flag == 1){
				setTimer2(25);
				update7SEG(index_led);
				index_led = (index_led + 1) % MAX_LED;
			}
			if (timer1_flag == 1) {
				setTimer1(100);
				countdown_timer1--;
				countdown_timer2--;
				updateClockBuffer(countdown_timer1, countdown_timer2);
				if(countdown_timer1 == 0){
					countdown_timer1 = red_time;
				}
				if(countdown_timer2 == 0){
					countdown_timer2 = green_time;
					status = AUTO_GREEN_RED;
					clearTrafficLight();
					setTimer1(100);
					updateClockBuffer(countdown_timer2, countdown_timer1);
				}
			}

			if (isButtonPressed(1) == 1) {
				status = MAN_RED_GREEN;
//				setTimer1(countdown_timer1 * 1000);
				clearTrafficLight();
			}
			 if (isButtonPressed(0)) {
				status = MODE_2;
				setTimer3(1);
				temp_time = 1;
				clearTrafficLight();
			 }
			break;
		case AUTO_GREEN_RED:
			ledGreenRed();
			if(timer2_flag == 1){
				setTimer2(25);
				update7SEG(index_led);
				index_led = (index_led + 1) % MAX_LED;
			}
			if (timer1_flag == 1) {
				setTimer1(100);
				countdown_timer1--;
				countdown_timer2--;
				updateClockBuffer(countdown_timer2, countdown_timer1);
				if(countdown_timer1 == 0){
					countdown_timer1 = red_time;
				}
				if(countdown_timer2 == 0){
					countdown_timer2 = yellow_time;
					status = AUTO_YELLOW_RED;
					updateClockBuffer(countdown_timer2, countdown_timer1);
					clearTrafficLight();
					setTimer1(100);
				}
			}

			if (isButtonPressed(1) == 1) {
				status = MAN_RED_GREEN;
//				setTimer1(countdown_timer1 * 1000);
				clearTrafficLight();
			}
			 if (isButtonPressed(0)) {
				status = MODE_2;
				setTimer3(1);
				temp_time = 1;
				clearTrafficLight();
			 }
			break;
		case AUTO_YELLOW_RED:
			ledYellowRed();
			if(timer2_flag == 1){
				setTimer2(25);
				update7SEG(index_led);
				index_led = (index_led + 1) % MAX_LED;
			}
			if (timer1_flag == 1) {
				setTimer1(100);
				countdown_timer1--;
				countdown_timer2--;
				updateClockBuffer(countdown_timer2, countdown_timer1);
				if(countdown_timer2 <= 0 || countdown_timer1 <= 0){
					countdown_timer1 = red_time;
					countdown_timer2 = green_time;
					status = AUTO_RED_GREEN;
					clearTrafficLight();
					setTimer1(100);
				}
				if( countdown_timer1 == 0){
					countdown_timer1 = red_time;
				}
				if(countdown_timer2 == 0){
					countdown_timer2 = green_time;
					status = AUTO_RED_GREEN;
					clearTrafficLight();
					updateClockBuffer(countdown_timer1, countdown_timer2);
					setTimer1(100);
				}
			}


			if (isButtonPressed(1) == 1) {
				status = MAN_RED_GREEN;
//				setTimer1( countdown_timer1 * 1000);
				clearTrafficLight();
			}
			 if (isButtonPressed(0)) {
				status = MODE_2;
				setTimer3(1);
				temp_time = 1;
				clearTrafficLight();
			 }
			break;
		default:
			break;
	}
}

