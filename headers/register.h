/* Author: Alexander Osborn
 * Date: 2/18/2018
 * Filename: register.cpp
 *******************************************************************************
 *
 ******************************************************************************/
#ifndef REGISTER_H
#define REGISTER_H
#include <stdint.h>

/*******************************************************************************
* By default there are 4 registers:
* 0x00: Device Instruction Register
* 0x01: Reads Completed Register
* 0x02: Reads Requested Register
* 0x03: Data Chunk Address Register
******************************************************************************/
#define IMPdir 0x00
#define IMPrcr 0x01
#define IMPrrr 0x02
#define IMPdcar 0x03

#define numRegisters 4

extern uint32_t Registers[numRegisters]; //array of registers
extern int currRegister;  //current register index

void initRegisters(); //initialize registers to starting values
void clearData(); //Clear non-volatile FRAM memory
void executeDirectCommand(uint8_t command); //execute a direct command
void executeRegisterCommand(uint8_t command, uint8_t numBytesToRead); //execute a register command

#endif  //REGISTER_H
