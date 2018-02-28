/* Author: Alexander Osborn
 * Date: 2/26/2018
 * Filename: register.h
 ******************************************************************************
 * This File contains header code pertinent to the implant registers, their
 * modification, direct commands, and other implant<->external protocol.
 *  IMP stands for Implant
 *****************************************************************************/
#ifndef REGISTER_H
#define REGISTER_H
#include <stdint.h>

#define directCmdModeBit 0x80
#define readModeBit 0x40
#define bitwiseModeBit 0x20
#define addrCmdBits 0x1F

/******************************************************************************
 * Registers
 * By default there are 4 registers:
 *
 * 0x00: Device Instruction Register
 * 0x01: Reads Completed Register
 * 0x02: Reads Requested Register
 * 0x03: Data Chunk Address Register
                                                                             */
#define IMPdir 0x00
#define IMPrcr 0x01
#define IMPrrr 0x02
#define IMPdcar 0x03

#define numRegisters 4

extern uint32_t Registers[numRegisters]; //array of registers

/******************************************************************************
 * Direct Commands
 * By default there are * direct commands:
 *
 * 0x00: Idle
 * 0x01: Begin Reads
 * 0x02: Transmit Chunk
 * 0x03: Clear Data                                                          */

#define IMPIDLE 0x00
#define IMPBEGINREADS 0x01
#define IMPTXCHUNK 0x02
#define IMPCLEARDATA 0x03

/******************************************************************************
 * Function Declarations                                                     */

void initRegisters(); //initialize registers to starting values
void clearData(); //Clear non-volatile FRAM memory
void processInstruction(uint8_t command, uint8_t numBytes); //process command
void executeDirectCommand(uint8_t command); //execute a direct command
void executeRegisterCommand(uint8_t command); //execute a register command


#endif  //REGISTER_H
