/*
 * TFT_interface.h
 *
 *  Created on: September 21, 2020
 *      Author: Mohamed shafek
 *     Version: V01
 * add decleration of tow function
 *   Add on: September 26, 2020
 *		Version: V02
 */

#ifndef TFT_interface_H_
#define TFT_interface_H_


void HTFT_voidInitialize(void);
void HTFT_voidDisplayImage(const u16* copy_u16Image);
void HTFT_voidFillColor(u16 copy_u16Color);
void HTFT_voidDrawRect(u8 x1,u8 x2, u8 y1, u8 y2, u16 copy_u16Color);

#endif /*TFT_interface_H_*/
