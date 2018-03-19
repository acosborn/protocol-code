/* Author: Alexander Osborn
 * Date: 2/26/2018
 * Filename: register.cpp
 *******************************************************************************
 * This File contains all code pertinent to the implant registers, their
 * modification, direct commands, and other implant<->external protocol.
 * IMP stands for Implant
 ******************************************************************************/
#include <stdint.h>
#include "register.h"
#include "spi.h"
#include "comms.h"

uint32_t Registers[numRegisters];   //Array of Registers

/******************************************************************************
 * initRegisters() initializes the registers to their default initial values
 *****************************************************************************/
void initRegisters()
{
  Registers[IMPdir] = 0x0000;   //Device Instruction Register
  Registers[IMPrcr] = 0x0000;   //Reads Completed Register
  Registers[IMPrrr] = 0x0000;   //Reads Requested Register
  Registers[IMPdcar] = 0x0000;  //Data Chunk Address Register
}


/******************************************************************************
 * clearData() erases all of the sensor data stored in FRAM.  It also resets
 * the IMPrcr and IMPrrr registers
 *****************************************************************************/
void clearData()
{

}


/******************************************************************************
 * processInstruction() takes in the first received command byte and processes
 * it to determine what action to take.  After executing the command and
 * processing all bytes, the FIFO on the TRF7970A is cleared for next command
 *****************************************************************************/
void processInstruction(uint8_t command, uint8_t numBytes)
{
  //check if command is a direct command bit
  if( (command & directCmdModeBit) )
  {
    executeDirectCommand( (command & addrCmdBits) );
  }
  else
  {
    executeRegisterCommand(command, numBytes);
  }

  //Send direct command NFC_RESET_FIFO (0x0F) to clear FIFO
}


/******************************************************************************
 * executeDirectCommand() executes the direct command that was received, or
 * ignores it if it is an invalid command
 *****************************************************************************/
void executeDirectCommand(uint8_t command)
{
  //This switch contains all of the direct commands that the implantable device
  //can receive
  switch(command)
  {
  case IMPIDLE:    //Idle command
      break;

  case IMPBEGINREADS:   //start reads until stopped or IMPrcr==IMPrrr
      //figure out how to start reads. Possibly set flag to read and check in
      //while loop in main.c
      break;

  case IMPTXCHUNK:  //Transmit chunk of data located at IMPdcar address of FRAM
      //retrieve chunk of data and transmit it to external device
      break;

  case IMPCLEARDATA:    //Clears the FRAM data
      clearData();
      break;

  }
}


//Execute a register command
void executeRegisterCommand(uint8_t command, uint8_t numBytesToRead)
{
  int i;  //iteration variable
  uint32_t  = 0x0000;
  uint32_t data = 0x0000;

  uint8_t currRegister = command & addrCmdBits; //set the current register index to the
                                        //received address

  //check if read or write command
  if(command & readModeBit)
  {
    //send currRegisters contents back to external device
  }

  else  //write mode
  {
    //check if register should be bitwise written and if there is 4 mask bytes
    //and at least 1 data byte
    if( (command & bitwiseModeBit) && (numBytesToRead > 4) )
    {
        //read in the 4 mask bytes, LSB first
        for(i = 0; i < 4; i++)
        {
            //mask |= spiReadDataByte();
        }

        //read in data bytes and change the bits where mask = 1
        for(i = 0; i < numBytes - 4; i++)
        {
            //data = spiReadByte();
            Registers[currRegister] |= ( mask & (data<<(i*8)) );    //set the proper 1 bits
            Registers[currRegister] &= ~( mask & ~(data<<(i*8)) );  //set the proper 0 bits
        }
    }
    else  //receive entire register
    {
        //read data register

        for(i = 0; i < numBytes; i++)
        {
            //data |= (spiReadDataByte() << i*8)
        }
        Registers[currRegister] = data;
    }
  }
}
