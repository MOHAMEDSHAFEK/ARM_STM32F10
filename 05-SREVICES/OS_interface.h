/*
 * OS_interface.h
 *
 *  Created on: September 5, 2020
 *      Author: Mohamed shafek
 *     Version: V01
 */

#ifndef OS_interface_H_
#define OS_interface_H_


void SOS_voidCreateTask(u8 copy_u8IDPriority, u16 copy_u16priodicity,void(*Fptr)(void));
void SOS_voidStart(void);



#endif /*OS_interface_H_*/
