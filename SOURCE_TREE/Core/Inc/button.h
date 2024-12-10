/*
 * button.h
 *
 *  Created on: Nov 14, 2024
 *      Author: DELL
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET
#define N0_OF_BUTTONS 3

extern int button_flag[N0_OF_BUTTONS];
int isButtonPressed(int index);
int isButtonLongPressed(int index);
//extern int KeyReg0[N0_OF_BUTTONS];
//extern int KeyReg1[N0_OF_BUTTONS];
//extern int KeyReg2[N0_OF_BUTTONS];
//extern int KeyReg3[N0_OF_BUTTONS];

void getKeyInput();
void subKeyProcess();

#endif /* INC_BUTTON_H_ */
