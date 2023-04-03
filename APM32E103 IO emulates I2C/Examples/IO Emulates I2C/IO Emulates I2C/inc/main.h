/*!
 * @file        main.h
 *
 * @brief       Main program body
 *
 * @version     V1.0.0
 *
 * @date        2021-07-26
 *
 */
 
#ifndef __MAIN_H
#define __MAIN_H

#include "Board.h"
#include "apm32e10x.h"

void delay_init(void);
void delay_us(uint32_t nus);
void delay_ms(uint16_t nms);
void delay_sec(uint16_t sec);

#endif

