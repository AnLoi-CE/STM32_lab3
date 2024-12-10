/*
 * global.h
 *
 *  Created on: Nov 14, 2024
 *      Author: DELL
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "main.h"

#define INIT				1
#define AUTO_RED_GREEN		2
#define AUTO_RED_YELLOW		3
#define AUTO_GREEN_RED		4
#define AUTO_YELLOW_RED		5

#define MAN_RED_GREEN 		6
#define MAN_RED_YELLOW		7
#define MAN_GREEN_RED		8
#define MAN_YELLOW_RED		9

#define MODE_2				10
#define MODE_3				11
#define MODE_4				12
//#define GPIO_PIN_SET SET
//#define GPIO_PIN_RESET RESET
extern int status;
extern int red_time ;
extern int green_time;
extern int yellow_time;
extern int temp_time;
extern int value;

#endif /* INC_GLOBAL_H_ */
