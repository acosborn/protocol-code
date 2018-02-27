/* Author: Alexander Osborn
 * Date: 2/18/2018
 * Filename: register.cpp
 *******************************************************************************
 * This file holds the code that runs the implantable device as a slave-like
 * device.  It holds the registers as well as the functions for modifying them.
 * Can maybe be rewritten as a C++ class?
 ******************************************************************************/
#include "register.h"
#include "spi.h"

uint32_t Registers[numRegisters];
int currRegister;


void initRegisters()
{
  Registers[IMPdir] = 0x0000;
  Registers[IMPrcr] = 0x0000;
  Registers[IMPrrr] = 0x0000;
  Registers[IMPdcar] = 0x0000;
}

//Clears the FRAM(tentatively)
void clearData()
{

}

//Execute a direct command
void executeDirectCommand(uint8_t command)
{
  //This switch contains all of the direct commands that the implantable device
  //can receive
  switch(command)
  {
  case 0: //idle command
      break;

  default:
      break;
  }
}

//Execute a register command
void executeRegisterCommand(uint8_t command, uint8_t numBytesToRead)
{
  int i;  //itteration variable

  currRegister = command & addrCmdBits; //set the current register index to the
                                        //received address

  //check if read or write command
  if(command & readModeBit)
  {
    spiSendDirectCommand(0x0F);  //clear FIFO data Registers

    //tell SPI slave how many bytes to expect
    //Register 0x1d and 0x1e

    //send register command to write to slave data Registers
    spiSendRegisterCommand(!readModeBit, !contAddrModeBit, 0x0F, &Registers[currRegister], 1);

    //Begin Transmission


  }

  else  //write mode
  {
    //check if multiple bytes need to be written
    if(command & contAddrModeBit)
    {
      //set the current register and following registers to the read spi value
      for(i = 0; i < numBytesToRead; i++)
      {
        Registers[currRegister+i] = spiReadByte();
      }
    }
    else  //receive
    {
      Registers[currRegister] = spiReadByte();
    }
  }
}
