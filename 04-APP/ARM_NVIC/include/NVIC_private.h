/*
 * NVIC_private.h
 *
 *  Created on: August 19, 2020
 *      Author: Mohamed shafek
 *     Version: V01
 */
/************************************************************************/
#ifndef NVIC_private_H_
#define NVIC_private_H_

	/*System control bolck groub and subgroub priority */
#define MNVIC_GROUP_4_SUB_0 		    0x05FA0300   // 4 BIT FOR GROUP IPR -> GROUP
#define MNVIC_GROUP_3_SUB_1	 		0x05FA0400	// 3 BIT FOR GROUP IPR -> GROUP 1 bit supgroup
#define MNVIC_GROUP_2_SUB_2 			0x05FA0500	// 2 BIT FOR GROUP IPR -> GROUP 2  bits supgroup
#define MNVIC_GROUP_1_SUB_3			 0x05FA0600	// 1 BIT FOR GROUP IPR -> GROUP 3 bits supgroup
#define MNVIC_GROUP_0_SUB_4			 0x05FA0700	// 0 BIT FOR GROUP IPR -> GROUP 4 bits supgroup



#define NVIC_ISER0       *((u32*)0xE000E100) /* Enable External interrupts from 0  to 31 */
#define NVIC_ISER1       *((u32*)0xE000E104) /* Enable External interrupts from 32 to 63 */

#define NVIC_ICER0       *((u32*)0xE000E180)
#define NVIC_ICER1       *((u32*)0xE000E184)

#define NVIC_ISPR0       *((u32*)0xE000E200)
#define NVIC_ISPR1       *((u32*)0xE000E204)

#define NVIC_ICPR0       *((u32*)0xE000E280)
#define NVIC_ICPR1       *((u32*)0xE000E284)

#define NVIC_IABR0       *((volatile u32*)0xE000E300)
#define NVIC_IABR1       *((volatile u32*)0xE000E304)
	
#define NVIC_IPR			((volatile u8*)(0xE000E100+0x300))



#endif /* NVIC_private_H_ */
