/*
 * LED_MATRIX_interface.h
 *
 *  Created on: August 31, 2020
 *      Author: Mohamed shafek
 *     Version: V01
 */

#ifndef LED_MATRIX_interface_H_
#define LED_MATRIX_interface_H_


typedef struct {
	u8 port;
	u8 pin;
}LED_MATRIX_PIN;

void HLEDMARX_voidInit(LED_MATRIX_PIN *copy_rowpin,LED_MATRIX_PIN *copy_colpin );

void HLEDMARX_voidDisplay(u8 *copyDataArray);

#endif /*LED_MATRIX_interface_H_*/
