/*
 * MACROS.h
 *
 *  Created on: Mar 28, 2017
 *      Author: Mina G. Sadek
 */

#ifndef MACROS_H_
#define MACROS_H_

#define SET_BIT(PORT,BIT) PORT |= (1<<BIT)
#define CLR_BIT(PORT,BIT) PORT &= ~(1<<BIT)
#define TGL_BIT(PORT,BIT) PORT ^= (1<<BIT)
#define READ_BIT(PORT,BIT) ((PORT & (1<<BIT))>>BIT)
#define SET_PORT(PORT) PORT = 0xFF
#define CLR_PORT(PORT) PORT = 0x00
#define TGL_PORT(PORT) PORT = ~PORT
#define SET_NBLE(PORT,LEAST_HIGH) (LEAST_HIGH? (PORT |= 0xF0) : (PORT |= 0x0f))
#define CLR_NBLE(PORT,LEAST_HIGH) (LEAST_HIGH? (PORT &= ~0xF0) : (PORT &= ~0x0f))

#endif /* MACROS_H_ */
