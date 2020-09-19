/*
 * OS_private.h
 *
 *  Created on: September 5, 2020
 *      Author: Mohamed shafek
 *     Version: V01
 */

#ifndef OS_private_H_
#define OS_private_H_



tyoedef struct{
	u16 priodicity     ;
	void (*Fptr) (void);

}Task;

#endif /*OS_private_H_*/