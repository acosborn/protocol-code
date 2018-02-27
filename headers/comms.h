/******************************************************************************
 *  Author: Alexander Osborn
 * Date: 2/27/2018
 * File: comms.h
 * Description: This header contains macros for all of the direct commands
 *  as well as register names and bit names for the TRF7970A NFC chip.
 ******************************************************************************
 * Direct Commands:                                                          */

#define NFCIDLE 0x00    //idle command
#define NFCSOFT_INIT 0x01   //software initialization
#define NFCRFCOLLAVOID 0x02 //Perform RF collision avoidance (broken)
#define NFCRESPRFCOLLAVOID 0x03 //Perform response RF collision avoidance (broken)
#define NFCRESPRFCOLLAVOIDN0 0x04   //Perform response RF collision avoidance (n=0)
#define RESET_FIFO 0x0F //Reset FIFO register
#define TXWOCRC 0x10    //Transmission without CRC
#define TXWCRC 0x11 //Transmission with CRC
#define DELAYTXWOCRC 0x12   //Delayed transmission without CRC
#define DELAYTXWCRC 0x13    //Delayed transmission with CRC
#define EOFTNTS 0x14    //End of frame and transmit next time slot
#define BLOCKRX 0x16    //Block receiver
#define ENABLERX 0x17   //Enable receiver
#define TESTINTERNRF 0x18   //Test internal RF (RSSI at RX input with TX off)
#define TESTEXTERNRF 0x19   //Test external RF (RSSI at RX input with TX on)

/******************************************************************************
 * Registers:                                                                */

#define NFCCSCR 0x00   //Chip Status Control Register
  #define NFCstby 7    //Standby Mode 1
                    //Active Mode 0
  #define NFCdirect 6  //Direct Mode 1
                    //Auto Framing 0
  #define NFCrf_on 5   //RF output active 1
                    //RF output not active 0
  #define NFCrf_power 4//Half output power 1
                    //Full output power 0
  #define NFCpm_on 3   //Selects aux RX input 1
                    //Selects main RX input 0
  #define NFCrec_on 1  //Receiver activated for external field measurement 1
                    //Auto enable 0
  #define NFCvrs5_3 0  //5V operation 1
                    //3V operation 0
/*****************************************************************************/
#define NFCISOCR 0x01  //ISO Control Register
  #define NFCrc_crc_n 7//no RX CRC 1
                    //RX CRC 0
  #define NFVdir_mode 6//Direct Mode 1 1
                    //Direct Mode 0 0
  #define NFCrfid 5    //NFC or card emulation mode 1
                    //RFID mode 0
  #define NFCiso_4 4   //initiator 1
                    //target 0
  #define NFCiso_3 3   //active mode 1
                    //passive mode 0
  #define NFCiso_2 2   //Card Emulation Mode 1
                    //NFC Normal Modes 0
  #define NFCiso_1 1   //bit rate selection or card emulation selection
                    //3V operation 0
  #define NFCiso_0 0   //5V operation 1
                    //3V operation 0
/*****************************************************************************/
#define NFCTXOR 0x02   //ISO/IEC 14443 TX Options Register
  #define NFCegt2 7    //TX EGT time select MSB

  #define NFCegt1 6    //TX EGT time select

  #define NFCegt0 5    //TX EGT time select LSB

  #define NFCeofl_0 4

  #define NFCsof_l1 3

  #define NFCsof_l0 2

  #define NFCl_egt 1   //EGT after each byte 1
                    //EGT after last byte is omitted 0
  #define NFCSSD_SAK 0 //Layer 4 compliant 1
                    //Not layer 4 compliant 0
/*****************************************************************************/
#define NFCHBRPOR 0x03   //ISO/IEC 14443 TX Options Register
  #define NFCdif_tx_br 7 //TX bit rate different from RX bit rate 1

  #define NFCtx_br1 6    //TX bit rate

  #define NFCtx_br0 5    //TX bit rate

  #define NFCparity2tx 4 //parity odd except last byte which is even for TX 0

  #define NFCparity2rx 3 //parity odd except last byte which is even for RX 1
/*****************************************************************************/
#define NFCTXTHBCR 0x04//TX Timer High Byte Control Register
  #define NFCtm_st1 7  //Timer Start Condition

  #define NFCtm_st0 6  //Timer Start Condition

  #define NFCtm_lengthD 5  //Timer Length MSB

  #define NFCtm_lengthC 4  //Timer Length

  #define NFCtm_lengthB 3  //Timer Length

  #define NFCtm_lengthA 2  //Timer Length

  #define NFCtm_length9 1  //Timer Length

  #define NFCtm_length8 0  //Timer Length LSB

/*****************************************************************************/
#define NFCTXTLBCR 0x05//TX Timer Low Byte Control Register
  #define NFCtm_length7 7  //Timer Length MSB

  #define NFCtm_length6 6  //Timer Length

  #define NFCtm_length5 5  //Timer Length

  #define NFCtm_length4 4  //Timer Length

  #define NFCtm_length3 3  //Timer Length

  #define NFCtm_length2 2  //Timer Length

  #define NFCtm_length1 1  //Timer Length

  #define NFCtm_length0 0  //Timer Length LSB
/*****************************************************************************/
#define NFCTXPLCR 0x06//TX Pulse Length Control Register
  #define NFCPul_p2 7  //Pulse length MSB

  #define NFCPul_p1 6  //Pulse length

  #define NFCPul_p0 5  //Pulse length

  #define NFCPul_c4 4  //Pulse length

  #define NFCPul_c3 3  //Pulse length

  #define NFCPul_c2 2  //Pulse length

  #define NFCPul_c1 1  //Pulse length

  #define NFCPul_c0 0  //Pulse length LSB
/*****************************************************************************/
#define NFCRXNRWTR 0x07//RX No Response Wait Time Register
  #define NFCNoResp7 7 //No Response MSB

  #define NFCNoResp6 6 //No Response


  #define NFCNoResp5 5 //No Response
  #define NFCNoResp4 4 //No Response

  #define NFCNoResp3 3 //No Response

  #define NFCNoResp2 2 //No Response

  #define NFCNoResp1 1 //No Response

  #define NFCNoResp0 0 //No Response LSB
/*****************************************************************************/
#define NFCRXWTR 0x08//RX No Response Wait Time Register
  #define NFCRxw7 7  //RX wait time MSB

  #define NFCRxw6 6  //RX wait time

  #define NFCRxw5 5  //RX wait time

  #define NFCRxw4 4  //RX wait time

  #define NFCRxw3 3  //RX wait time

  #define NFCRxw2 2  //RX wait time

  #define NFCRxw1 1  //RX wait time

  #define NFCRxw0 0  //RX wait time LSB
/*****************************************************************************/
#define NFCMSCR 0x09//RX No Response Wait Time Register
  #define NFCMHz27 7//Enable 27.12MHz crystal (default) 1

  #define NFCen_ook_p 6  //Enable ASK/OOK pin 12 for "on the fly" selection 1
                      //Default operation as defined by Pm[2:0]
  #define NFCClo1 5  //SYS_CLK output frequency MSB

  #define NFCClo0 4  //SYS_CLK output frequency LSB

  #define NFCen_ana 3//Sets pin 12 (ASK/OOK) as an analog output 1
                  //Default 0
  #define NFCPm2 2   //Modulation depth MSB

  #define NFCPm1 1   //Modulation depth

  #define NFCPm0 0   //Modulation depth LSB
/*****************************************************************************/
#define NFCRXSSR 0x0A//RX Special Setting Register
  #define NFCC212 7  //Band-pass 110kHz to 570kHz

  #define NFCC424 6  //Band-pass 200kHz to 900kHz

  #define NFCM848 5  //Band-pass 450kHz to 1.5MHz

  #define NFChbt 4   //Band-pass 100kHz to 1.5MHz, Gain reduced for 18dB

  #define NFCgd1 3   //Gain Reduction

  #define NFCgd2 2   //Gain Reduction
/*****************************************************************************/
#define NFCRIOCR 0x0B//Regulator and I/O Control Register
  #define NFCauto_reg 7//Automatic setting 1
                    //Manual setting 0

  #define NFCen_ext_pa 6//Support for external power amplifier

  #define NFCio_low 5  //enable low peripheral communication voltage 1

  #define NFCvrs2 2    //Voltage set MSB

  #define NFCvrs1 1    //Voltage set

  #define NFCvrs0 0    //Voltage set LSB
/*****************************************************************************/
#define NFCIRQSR 0x0C  //IRQ Status Register
  #define NFCIrq_tx 7  //IRQ set due to end of TX

  #define NFCIrq_srx 6 //IRQ set due to RX start

  #define NFCIrq_fifo 5//Signals the FIFO level

  #define NFCIrq_err1 4//CRC error

  #define NFCIrq_err2 3//Parity error

  #define NFCIrq_err3 2//Byte framing or EOF error

  #define NFCIrq_col 1 //Collision error

  #define NFCIrq_noresp 0  //No response time interrupt
/*****************************************************************************/
#define NFCIMR 0x0D    //Interupt Mask Register
  #define NFCCol9 7    //Bit position of collision MSB

  #define NFCCol8 6    //Bit position of collision

  #define NFCEn_irq_fifo 5 //Interrupt enable for FIFO

  #define NFCEn_irq_err1 4 //Interrupt enable for CRC

  #define NFCEn_irq_err2 3 //Interrupt enable for Parity

  #define NFCEn_irq_err3 2 //Interrupt enable for framing error or EOF

  #define NFCEn_irq_col 1  //Interrupt enable for collision error

  #define NFCEn_irq_noresp 0 //Enables no-response interrupt
/*****************************************************************************/
#define NFCCPR 0x0E    //Collision Position Register
  #define NFCCol7 7    //Bit position of collision MSB

  #define NFCCol6 6    //Bit position of collision

  #define NFCCol5 5    //Bit position of collision

  #define NFCCol4 4    //Bit position of collision

  #define NFCCol3 3    //Bit position of collision

  #define NFCCol2 2    //Bit position of collision

  #define NFCCol1 1    //Bit position of collision

  #define NFCCol0 0    //Bit position of collision LSB
/*****************************************************************************/
#define NFCRSSILOSR 0x0F //RSSI Levels and Oscillator Status Register
  #define NFCosc_ok 6  //Crystal oscillator stable indicator

  #define NFCrssi_x2 5 //MSB RSSI value of auxiliary RX (RX_IN2)

  #define NFCrssi_x1 4 //Auxiliary channel RSSI

  #define NFCrssi_x0 3 //MSB RSSI value of auxiliary RX (RX_IN1)

  #define NFCrssi_2 2  //MSB RSSI value of main RX (RX_IN1)

  #define NFCrssi_1 1  //Main channel RSSI

  #define NFCrssi_0 0  //LSB RSSI value of main RX (RX_IN1)
/*****************************************************************************/
#define NFCSFR0 0x10    //Special Functions Register 0
  #define NFCpar43 5   //Disables parity checking for ISO/IEC 14443 A

  #define NFCnext_slot_37us 4  //Sets the time grid for next slot command in ISO/IEC 15693

  #define NFCSp_dir_mode 3 //Bit stream transmit for MIFARE at 106kbps

  #define NFCbit_4_RX 2    //Enable 4-bit replay

  #define NFCanticoll_14 1 //Disable anticollision frames for ISO/IEC 14443 A

  #define NFCcol_7_6 0 //Selects the number of subcarrier pulses that trigger collision error
/*****************************************************************************/
#define NFCSFR1 0x11    //Special Functions Register 1
  #define NFCirg_srx 0 //Copy of the RX start signal (bit 6) of the IRQ Status register (0x0C)
/*****************************************************************************/
#define NFCAFIFOIRQL 0x14  //Adjustable FIFO IRQ Levels Register
  #define NFCWlh_1 3   //FIFO high IRQ level (during RX)

  #define NFCWlh_0 2   //FIFO high IRQ level (during RX)

  #define NFCWll_1 1   //FIFO low IRQ level (during TX)

  #define NFCWll_0 0   //FIFO low IRQ level (during TX)
/*****************************************************************************/
#define NFCLFLR 0x16//NFC Low Field Level Register
  #define NFCClex_dis 7//Disable clock extractor

  #define NFCHash6 6   //N/A

  #define NFCHash5 5   //N/A

  #define NFCHash4 4   //N/A

  #define NFCHash3 3   //N/A

  #define NFCRfdet_I2 2//RF field level for RF collision avoidance

  #define NFCRfdet_I1 1//RF field level for RF collision avoidance

  #define NFCRfdet_I0 0//RF field level for RF collision avoidance
/*****************************************************************************/
#define NFCID1NR 0x17//NFCID1 Number Register
  /*This register is used to hold the ID of the TRF7970A for use during card
    emulation and NFC peer-to-peer target operations.*/

  /*The procedure for writing the ID into register 0x17 is the following:
      1. Write bits 5, 6, and 7 in register 0x18 to enable SDD anticollision
      (bit 5), and set bit 6 and 7 to select the ID length of 4, 7, or 10 bytes.
      2. Write the ID into register 0x17. This should be done using write
      continuous mode with 4, 7, or 10 bytes(according to what was set in
      register 0x18 bits 6 and 7).
/*****************************************************************************/
#define NFCTDLR 0x18//NFC Target Detection Level Register
  #define NFCId_s1 7   //NFCID1 size used in 106-kbps passive target SSD

  #define NFCId_s0 6   //NFCID1 size used in 106-kbps passive target SSD

  #define NFCSdd_en 5  //Enable automatic SSD using internal state machine and ID
                    //stored in NFCID1 Number Register (0x17)
  #define NFCHi_rf 3   //Extended range for RF measurements

  #define NFCRfdet_h2 2//RF field level required for system wakeup

  #define NFCRfdet_h1 1//RF field level required for system wakeup

  #define NFCRfdet_h0 0//RF field level required for system wakeup
  /*****************************************************************************/
#define NFCLFLR 0x19//NFC Target Protocol Register
  #define NFCRf_h 7    //RF level is above the wake-up level setting

  #define NFCRf_l 6    //RF level is above the RF collision avoidance level stting

  #define NFCFeliCa 4  //FeliCa protocol 1
                    //ISO/IEC 14443 A protocol 0
  #define NFCPas_106 3 //Passive target at 106kbps or transponder emulation

  #define NFCPas_14443B 2  //ISO/IEC 14443 B transponder emulation

  #define NFCNFCBR1 1  //Bit rate of first received command

  #define NFCNFCBR0 0  //Bit rate of first received command
/*****************************************************************************/
#define NFCTR0 0x1A    //Test Register 0
  #define NFCOOK_Subc_In 7 //Subcarrier input

  #define NFCMOD_Subc_Out 6//Subcarrier output

  #define NFCMOD_Direct 5  //Direct TX modulation and RX reset

  #define NFCo_sel 4   //First stage output selection

  #define NFClow2 3    //Second stage gain –6 dB

  #define NFClow1 2    //First stage gain –6 dB

  #define NFCzun 1     //Input followers test

  #define NFCTest_AGC 0//AGC test, AGC level is seen on rssi_210 bits
/*****************************************************************************/
#define NFCTR1 0x1B    //Test Register 1
  #define NFCtest_rf_level3 7  //RF level test

  #define NFCtest_rf_level2 6  //RF level test

  #define NFCtest_rf_level1 5  //RF level test

  #define NFCtest_rf_level0 4  //RF level test

  #define NFCtest_io1 3//I/O test

  #define NFCtest_io0 2//I/O test

  #define NFCtest_dec 1//Decoder test mode

  #define NFCclock_su 0//Coder clock 13.56 MHz
/*****************************************************************************/
#define NFCFIFOSR 0x1C //FIFO Status Register
  #define NFCFoverflow 7 //FIFO overflow error

  #define NFCFb6 6     //FIFO bytes fb[6]

  #define NFCFb5 5     //FIFO bytes fb[5]

  #define NFCFb4 4     //FIFO bytes fb[4]

  #define NFCFb3 3     //FIFO bytes fb[3]

  #define NFCFb2 2     //FIFO bytes fb[2]

  #define NFCFb1 1     //FIFO bytes fb[1]

  #define NFCFb0 0     //FIFO bytes fb[0]
/*****************************************************************************/
#define NFCTXLB1R 0x1D //TX Length Byte 1 Register
  #define NFCTxl11 7   //Number of complete byte bn[11]

  #define NFCTxl10 6   //Number of complete byte bn[10]

  #define NFCTxl9 5    //Number of complete byte bn[9]

  #define NFCTxl8 4    //Number of complete byte bn[8]

  #define NFCTxl7 3    //Number of complete byte bn[7]

  #define NFCTxl6 2    //Number of complete byte bn[6]

  #define NFCTxl5 1    //Number of complete byte bn[5]

  #define NFCTxl4 0    //Number of complete byte bn[4]
/*****************************************************************************/
#define NFCTXLB2R 0x1E //TX Length Byte 2 Register
  #define NFCTxl3 7    //Number of complete byte bn[3]

  #define NFCTxl2 6    //Number of complete byte bn[2]

  #define NFCTxl1 5    //Number of complete byte bn[1]

  #define NFCTxl0 4    //Number of complete byte bn[0]

  #define NFCBb2 3     //Broken byte number of bitsbb[2]

  #define NFCBb1 2     //Broken byte number of bitsbb[1]

  #define NFCBb0 1     //Broken byte number of bitsbb[0]

  #define NFCBbf 0     //Broken byte flat
/*****************************************************************************/
