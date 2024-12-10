/*
 * fsm_setting.c
 *
 *  Created on: Dec 4, 2024
 *      Author: DELL
 */

#include "fsm_setting.h"

int mode2 = 2;
int mode3 = 3;
int mode4 = 4;
int num = 0;
const int MAX = 4;

void fsm_setting() {
	switch(status) {
		case MODE_2:
			updateClockBuffer(2, temp_time);
			if(timer2_flag == 1){
				setTimer2(25);
				update7SEG(num);
				num++;
				if(num>3){
					num = 0;
				}
			}
			if(timer3_flag == 1){
					toggleRedLED();
					setTimer3(50);
				}

	            if (isButtonPressed(0) == 1) {
	                status = MODE_3;
	                temp_time = 1;
	                clearTrafficLight();
	            }
	            if (isButtonPressed(1) == 1) {
	               temp_time++;
	                if (temp_time > 99) {
	                	temp_time = 1;
	                }
	            }
	            if (isButtonPressed(2) == 1) {
	                red_time = temp_time;
	                green_time = (3 * red_time /5);
	                yellow_time = red_time - green_time;
	                status = INIT;
	                clearTrafficLight();
	            }

	            break;

	        case MODE_3:
	        	updateClockBuffer(mode3, temp_time);
	        	if(timer3_flag == 1){
	        		toggleYellowLED();
	        		setTimer3(50);
	        	}
				if(timer2_flag == 1){
					setTimer2(25);
					update7SEG(num);
					num = (num + 1) % MAX;
				}
	            if (isButtonPressed(0) == 1) {
	                status = MODE_4;
	                temp_time = 1;
	                clearTrafficLight();
	            }
	            if (isButtonPressed(1) == 1) {
	                temp_time++;
	                if (temp_time > 99){
	                	temp_time = 1;
	                }

	            }
	            if (isButtonPressed(2) == 1) {
	                yellow_time = temp_time;
	                green_time = (3 * yellow_time /2);
	                red_time = green_time + yellow_time;
	                status = AUTO_RED_GREEN;
	                clearTrafficLight();
	            }

	            break;

	        case MODE_4:
	        	updateClockBuffer(mode4, temp_time);
	        	if(timer3_flag == 1){
	            toggleGreenLED();
	            setTimer3(50);
	        	}
				if(timer2_flag == 1){
					setTimer2(25);
					update7SEG(num);
					num = (num + 1) % MAX;
				}
	            if (isButtonPressed(0) == 1) {
	                status = MODE_2;
	                temp_time = 1;
	            }
	            if (isButtonPressed(1) == 1) {
	                temp_time++;
	                if (temp_time > 99) {
	                	temp_time = 1;
	                }
	            }
	            if (isButtonPressed(2) == 1) {
	                green_time = temp_time;
	                yellow_time = (2 * green_time /3);
	                red_time = green_time + yellow_time;
	                status = AUTO_RED_GREEN;
	                clearTrafficLight();
	            }
	            break;

	        default:
	            break;
	    }
	}
