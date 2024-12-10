/*
 * software_timer.h
 *
 *  Created on: Oct 3, 2024
 *      Author: DELL
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"
extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;
extern int timer0_flag;
extern int timer1_counter;
extern int timer2_counter;
extern int timer3_counter;
extern int timer0_counter;


void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void setTimer0(int duration);
void timerRun();

void clearTimer1();

#endif /* INC_SOFTWARE_TIMER_H_ */
