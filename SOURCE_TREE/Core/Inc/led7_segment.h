/*
 * led7_segment.h
 *
 *  Created on: Nov 28, 2024
 *      Author: DELL
 */

#ifndef INC_LED7_SEGMENT_H_
#define INC_LED7_SEGMENT_H_

#include "main.h"
#include "global.h"


void display7SEG(int num);
void update7SEG(int index);
void updateClockBuffer(int hour, int minute);

extern int led_buffer[4];
#endif /* INC_LED7_SEGMENT_H_ */
