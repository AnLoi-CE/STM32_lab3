/*
 * traffic_light.h
 *
 *  Created on: Nov 28, 2024
 *      Author: DELL
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_

#include "main.h"
#include "global.h"

void ledRedYellow();
void ledRedGreen();
void ledGreenRed();
void ledYellowRed();
void clearTrafficLight();

void toggleRedLED();
void toggleYellowLED();
void toggleGreenLED();

#endif /* INC_TRAFFIC_LIGHT_H_ */
