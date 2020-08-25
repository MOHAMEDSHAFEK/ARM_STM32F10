/*
 * EXTI_interface.h
 *
 *  Created on: August 24, 2020
 *      Author: Mohamed shafek
 *     Version: V01
 */
 /******************************************/

#ifndef EXTI_interface_H_
#define EXTI_interface_H_

#define HIGH    1
#define LOW     0


/*line and mode*/
void MEXTI_VoidInit( void );
void MEXTI_VoidEnable( u8 Copy_u8Line);
void MEXTI_VoidDisable( u8 Copy_u8Line);
void MEXTI_VoidSwTrigger( u8 Copy_u8Line);
#endif /* EXTI_interface_H_ */
