/*
 * LED_MATRIX_config.h
 *
 *  Created on: August 31, 2020
 *      Author: Mohamed shafek
 *     Version: V01
 */

#ifndef LED_MATRIX_config_H_
#define LED_MATRIX_config_H_


#define NO_ROWS		8
#define NO_COLS		8

#define CTRL_TYPE  COL_CTRL

/*Please write pin pair Port,Pin*/
#define LEDMRX_ROW0		GPIOA, 0
#define LEDMRX_ROW1     GPIOA, 1
#define LEDMRX_ROW2     GPIOA, 2
#define LEDMRX_ROW3     GPIOA, 3
#define LEDMRX_ROW4     GPIOA, 4
#define LEDMRX_ROW5     GPIOA, 5
#define LEDMRX_ROW6     GPIOA, 6
#define LEDMRX_ROW7     GPIOA, 7

/*Please write pin pair Port,Pin*/
#define LEDMRX_COL0		GPIOB, 0
#define LEDMRX_COL1     GPIOB, 1
#define LEDMRX_COL2     GPIOB, 5
#define LEDMRX_COL3     GPIOB, 6
#define LEDMRX_COL4     GPIOB, 7
#define LEDMRX_COL5     GPIOB, 8
#define LEDMRX_COL6     GPIOB, 9
#define LEDMRX_COL7     GPIOB, 10


#endif /*LED_MATRIX_config_H_*/
