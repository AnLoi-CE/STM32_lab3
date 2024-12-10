/*
 * fsm_manual.c
 *
 *  Created on: Nov 14, 2024
 *      Author: DELL
 */
#include "fsm_manual.h"
#include "traffic_light.h"
#include "global.h"
int status;
//int countdown_timer1 = 0;
//int countdown_timer2 = 0;
//int index_led = 0;
//const int MAX_LED = 4;

void fsm_manual_run() {
    switch (status) {
        case MAN_RED_GREEN:
            ledRedGreen();

            if (isButtonPressed(0) == 1) {
                status = MODE_2;
                clearTrafficLight();
            }
            if (isButtonPressed(1) == 1) {
                status = MAN_RED_YELLOW;
                clearTrafficLight();
            }
            if (isButtonPressed(2) == 1) {
                status = AUTO_RED_GREEN;
                clearTrafficLight();
            }

            break;

        case MAN_RED_YELLOW:
            ledRedYellow();

            if (isButtonPressed(0) == 1) {
                status = MODE_2;
                clearTrafficLight();
            }
            if (isButtonPressed(1) == 1) {
                status = MAN_GREEN_RED;
                clearTrafficLight();
            }
            if (isButtonPressed(2) == 1) {
                status = AUTO_RED_YELLOW;
                clearTrafficLight();
            }
            break;

        case MAN_GREEN_RED:
            ledGreenRed();

            if (isButtonPressed(0) == 1) {
                status = MODE_2;
                clearTrafficLight();
            }
            if (isButtonPressed(1) == 1) {
                status = MAN_YELLOW_RED;
                clearTrafficLight();
            }
            if (isButtonPressed(2) == 1) {
                status = AUTO_GREEN_RED;
                clearTrafficLight();
            }
            break;

        case MAN_YELLOW_RED:
            ledYellowRed();

            if (isButtonPressed(0) == 1) {
                status = MODE_2;
                clearTrafficLight();
            }
            if (isButtonPressed(1) == 1) {
                status = MAN_RED_GREEN;
                clearTrafficLight();
            }
            if (isButtonPressed(2) == 1) {
                status = AUTO_YELLOW_RED;
                clearTrafficLight();
            }
            break;

        default:
            break;
    }
}

