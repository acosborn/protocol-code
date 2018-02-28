/******************************************************************************
 *  Author: Alexander Osborn
 * Date: 2/27/2018
 * File: comms.h
 * Description: This header contains macros for all of the direct commands
 *  as well as register names and bit names for the TRF7970A NFC chip.
 *****************************************************************************/
#ifndef COMMS_H
#define COMMS_H


/* Direct Commands:                                                          */

#define NFC_IDLE 0x00    //idle command
#define NFC_SOFT_INIT 0x01   //software initialization
#define NFC_RF_COLL_AVOID 0x02 //Perform RF collision avoidance (broken)
#define NFC_RESP_RF_COLL_AVOID 0x03 //Perform response RF collision avoidance (broken)
#define NFC_RESP_RF_COLL_AVOIDN0 0x04   //Perform response RF collision avoidance (n=0)
#define NFC_RESET_FIFO 0x0F //Reset FIFO register
#define NFC_TX_WO_CRC 0x10    //Transmission without CRC
#define NFC_TX_W_CRC 0x11 //Transmission with CRC
#define NFC_DELAY_TX_WO_CRC 0x12   //Delayed transmission without CRC
#define NFC_DELAY_TX_W_CRC 0x13    //Delayed transmission with CRC
#define NFC_EOF_TNTS 0x14    //End of frame and transmit next time slot
#define NFC_BLOCK_RX 0x16    //Block receiver
#define NFC_ENABLE_RX 0x17   //Enable receiver
#define NFC_TEST_INTERN_RF 0x18   //Test internal RF (RSSI at RX input with TX off)
#define NFC_TEST_EXTERN_RF 0x19   //Test external RF (RSSI at RX input with TX on)

/******************************************************************************
 * Registers:                                                                */

#define NFC_CSCR 0x00   //Chip Status Control Register
  #define NFC_stby 7    //Standby Mode 1
                    //Active Mode 0
  #define NFC_direct 6  //Direct Mode 1
                    //Auto Framing 0
  #define NFC_rf_on 5   //RF output active 1
                    //RF output not active 0
  #define NFC_rf_power 4//Half output power 1
                    //Full output power 0
  #define NFC_pm_on 3   //Selects aux RX input 1
                    //Selects main RX input 0
  #define NFC_rec_on 1  //Receiver activated for external field measurement 1
                    //Auto enable 0
  #define NFC_vrs5_3 0  //5V operation 1
                    //3V operation 0
/*****************************************************************************/
#define NFC_ISOCR 0x01  //ISO Control Register
  #define NFC_rc_crc_n 7//no RX CRC 1
                    //RX CRC 0
  #define NFC_dir_mode 6//Direct Mode 1 1
                    //Direct Mode 0 0
  #define NFC_rfid 5    //NFC or card emulation mode 1
                    //RFID mode 0
  #define NFC_iso_4 4   //initiator 1
                    //target 0
  #define NFC_iso_3 3   //active mode 1
                    //passive mode 0
  #define NFC_iso_2 2   //Card Emulation Mode 1
                    //NFC Normal Modes 0
  #define NFC_iso_1 1   //bit rate selection or card emulation selection
                    //3V operation 0
  #define NFC_iso_0 0   //5V operation 1
                    //3V operation 0
/*****************************************************************************/
#define NFC_TXOR 0x02   //ISO/IEC 14443 TX Options Register
  #define NFC_egt2 7    //TX EGT time select MSB

  #define NFC_egt1 6    //TX EGT time select

  #define NFC_egt0 5    //TX EGT time select LSB

  #define NFC_eofl_0 4

  #define NFC_sof_l1 3

  #define NFC_sof_l0 2

  #define NFC_l_egt 1   //EGT after each byte 1
                    //EGT after last byte is omitted 0
  #define NFC_SSD_SAK 0 //Layer 4 compliant 1
                    //Not layer 4 compliant 0
/*****************************************************************************/
#define NFC_HBRPOR 0x03   //ISO/IEC 14443 TX Options Register
  #define NFC_dif_tx_br 7 //TX bit rate different from RX bit rate 1

  #define NFC_tx_br1 6    //TX bit rate

  #define NFC_tx_br0 5    //TX bit rate

  #define NFC_parity2tx 4 //parity odd except last byte which is even for TX 0

  #define NFC_parity2rx 3 //parity odd except last byte which is even for RX 1
/*****************************************************************************/
#define NFC_TXTHBCR 0x04//TX Timer High Byte Control Register
  #define NFC_tm_st1 7  //Timer Start Condition

  #define NFC_tm_st0 6  //Timer Start Condition

  #define NFC_tm_lengthD 5  //Timer Length MSB

  #define NFC_tm_lengthC 4  //Timer Length

  #define NFC_tm_lengthB 3  //Timer Length

  #define NFC_tm_lengthA 2  //Timer Length

  #define NFC_tm_length9 1  //Timer Length

  #define NFC_tm_length8 0  //Timer Length LSB

/*****************************************************************************/
#define NFC_TXTLBCR 0x05//TX Timer Low Byte Control Register
  #define NFC_tm_length7 7  //Timer Length MSB

  #define NFC_tm_length6 6  //Timer Length

  #define NFC_tm_length5 5  //Timer Length

  #define NFC_tm_length4 4  //Timer Length

  #define NFC_tm_length3 3  //Timer Length

  #define NFC_tm_length2 2  //Timer Length

  #define NFC_tm_length1 1  //Timer Length

  #define NFC_tm_length0 0  //Timer Length LSB
/*****************************************************************************/
#define NFC_TXPLCR 0x06//TX Pulse Length Control Register
  #define NFC_Pul_p2 7  //Pulse length MSB

  #define NFC_Pul_p1 6  //Pulse length

  #define NFC_Pul_p0 5  //Pulse length

  #define NFC_Pul_c4 4  //Pulse length

  #define NFC_Pul_c3 3  //Pulse length

  #define NFC_Pul_c2 2  //Pulse length

  #define NFC_Pul_c1 1  //Pulse length

  #define NFC_Pul_c0 0  //Pulse length LSB
/*****************************************************************************/
#define NFC_RXNRWTR 0x07//RX No Response Wait Time Register
  #define NFC_NoResp7 7 //No Response MSB

  #define NFC_NoResp6 6 //No Response

  #define NFC_NoResp5 5 //No Response

  #define NFC_NoResp4 4 //No Response

  #define NFC_NoResp3 3 //No Response

  #define NFC_NoResp2 2 //No Response

  #define NFC_NoResp1 1 //No Response

  #define NFC_NoResp0 0 //No Response LSB
/*****************************************************************************/
#define NFC_RXWTR 0x08//RX No Response Wait Time Register
  #define NFC_Rxw7 7  //RX wait time MSB

  #define NFC_Rxw6 6  //RX wait time

  #define NFC_Rxw5 5  //RX wait time

  #define NFC_Rxw4 4  //RX wait time

  #define NFC_Rxw3 3  //RX wait time

  #define NFC_Rxw2 2  //RX wait time

  #define NFC_Rxw1 1  //RX wait time

  #define NFC_Rxw0 0  //RX wait time LSB
/*****************************************************************************/
#define NFC_MSCR 0x09//RX No Response Wait Time Register
  #define NFC_MHz27 7//Enable 27.12MHz crystal (default) 1

  #define NFC_en_ook_p 6  //Enable ASK/OOK pin 12 for "on the fly" selection 1
                      //Default operation as defined by Pm[2:0]
  #define NFC_Clo1 5  //SYS_CLK output frequency MSB

  #define NFC_Clo0 4  //SYS_CLK output frequency LSB

  #define NFC_en_ana 3//Sets pin 12 (ASK/OOK) as an analog output 1
                  //Default 0
  #define NFC_Pm2 2   //Modulation depth MSB

  #define NFC_Pm1 1   //Modulation depth

  #define NFC_Pm0 0   //Modulation depth LSB
/*****************************************************************************/
#define NFC_RXSSR 0x0A//RX Special Setting Register
  #define NFC_C212 7  //Band-pass 110kHz to 570kHz

  #define NFC_C424 6  //Band-pass 200kHz to 900kHz

  #define NFC_M848 5  //Band-pass 450kHz to 1.5MHz

  #define NFC_hbt 4   //Band-pass 100kHz to 1.5MHz, Gain reduced for 18dB

  #define NFC_gd1 3   //Gain Reduction

  #define NFC_gd2 2   //Gain Reduction
/*****************************************************************************/
#define NFC_RIOCR 0x0B//Regulator and I/O Control Register
  #define NFC_auto_reg 7//Automatic setting 1
                    //Manual setting 0

  #define NFC_en_ext_pa 6//Support for external power amplifier

  #define NFC_io_low 5  //enable low peripheral communication voltage 1

  #define NFC_vrs2 2    //Voltage set MSB

  #define NFC_vrs1 1    //Voltage set

  #define NFC_vrs0 0    //Voltage set LSB
/*****************************************************************************/
#define NFC_IRQSR 0x0C  //IRQ Status Register
  #define NFC_Irq_tx 7  //IRQ set due to end of TX

  #define NFC_Irq_srx 6 //IRQ set due to RX start

  #define NFC_Irq_fifo 5//Signals the FIFO level

  #define NFC_Irq_err1 4//CRC error

  #define NFC_Irq_err2 3//Parity error

  #define NFC_Irq_err3 2//Byte framing or EOF error

  #define NFC_Irq_col 1 //Collision error

  #define NFC_Irq_noresp 0  //No response time interrupt
/*****************************************************************************/
#define NFC_IMR 0x0D    //Interupt Mask Register
  #define NFC_Col9 7    //Bit position of collision MSB

  #define NFC_Col8 6    //Bit position of collision

  #define NFC_En_irq_fifo 5 //Interrupt enable for FIFO

  #define NFC_En_irq_err1 4 //Interrupt enable for CRC

  #define NFC_En_irq_err2 3 //Interrupt enable for Parity

  #define NFC_En_irq_err3 2 //Interrupt enable for framing error or EOF

  #define NFC_En_irq_col 1  //Interrupt enable for collision error

  #define NFC_En_irq_noresp 0 //Enables no-response interrupt
/*****************************************************************************/
#define NFC_CPR 0x0E    //Collision Position Register
  #define NFC_Col7 7    //Bit position of collision MSB

  #define NFC_Col6 6    //Bit position of collision

  #define NFC_Col5 5    //Bit position of collision

  #define NFC_Col4 4    //Bit position of collision

  #define NFC_Col3 3    //Bit position of collision

  #define NFC_Col2 2    //Bit position of collision

  #define NFC_Col1 1    //Bit position of collision

  #define NFC_Col0 0    //Bit position of collision LSB
/*****************************************************************************/
#define NFC_RSSILOSR 0x0F //RSSI Levels and Oscillator Status Register
  #define NFC_osc_ok 6  //Crystal oscillator stable indicator

  #define NFC_rssi_x2 5 //MSB RSSI value of auxiliary RX (RX_IN2)

  #define NFC_rssi_x1 4 //Auxiliary channel RSSI

  #define NFC_rssi_x0 3 //MSB RSSI value of auxiliary RX (RX_IN1)

  #define NFC_rssi_2 2  //MSB RSSI value of main RX (RX_IN1)

  #define NFC_rssi_1 1  //Main channel RSSI

  #define NFC_rssi_0 0  //LSB RSSI value of main RX (RX_IN1)
/*****************************************************************************/
#define NFC_SFR0 0x10    //Special Functions Register 0
  #define NFC_par43 5   //Disables parity checking for ISO/IEC 14443 A

  #define NFC_next_slot_37us 4  //Sets the time grid for next slot command in ISO/IEC 15693

  #define NFC_Sp_dir_mode 3 //Bit stream transmit for MIFARE at 106kbps

  #define NFC_bit_4_RX 2    //Enable 4-bit replay

  #define NFC_anticoll_14 1 //Disable anticollision frames for ISO/IEC 14443 A

  #define NFC_col_7_6 0 //Selects the number of subcarrier pulses that trigger collision error
/*****************************************************************************/
#define NFC_SFR1 0x11    //Special Functions Register 1
  #define NFC_irg_srx 0 //Copy of the RX start signal (bit 6) of the IRQ Status register (0x0C)
/*****************************************************************************/
#define NFC_AFIFOIRQL 0x14  //Adjustable FIFO IRQ Levels Register
  #define NFC_Wlh_1 3   //FIFO high IRQ level (during RX)

  #define NFC_Wlh_0 2   //FIFO high IRQ level (during RX)

  #define NFC_Wll_1 1   //FIFO low IRQ level (during TX)

  #define NFC_Wll_0 0   //FIFO low IRQ level (during TX)
/*****************************************************************************/
#define NFC_LFLR 0x16//NFC Low Field Level Register
  #define NFC_Clex_dis 7//Disable clock extractor

  #define NFC_Hash6 6   //N/A

  #define NFC_Hash5 5   //N/A

  #define NFC_Hash4 4   //N/A

  #define NFC_Hash3 3   //N/A

  #define NFC_Rfdet_I2 2//RF field level for RF collision avoidance

  #define NFC_Rfdet_I1 1//RF field level for RF collision avoidance

  #define NFC_Rfdet_I0 0//RF field level for RF collision avoidance
/*****************************************************************************/
#define NFC_ID1NR 0x17//NFCID1 Number Register
  /*This register is used to hold the ID of the TRF7970A for use during card
    emulation and NFC peer-to-peer target operations.*/

  /*The procedure for writing the ID into register 0x17 is the following:
      1. Write bits 5, 6, and 7 in register 0x18 to enable SDD anticollision
      (bit 5), and set bit 6 and 7 to select the ID length of 4, 7, or 10 bytes.
      2. Write the ID into register 0x17. This should be done using write
      continuous mode with 4, 7, or 10 bytes(according to what was set in
      register 0x18 bits 6 and 7).
/*****************************************************************************/
#define NFC_TDLR 0x18//NFC Target Detection Level Register
  #define NFC_Id_s1 7   //NFCID1 size used in 106-kbps passive target SSD

  #define NFC_Id_s0 6   //NFCID1 size used in 106-kbps passive target SSD

  #define NFC_Sdd_en 5  //Enable automatic SSD using internal state machine and ID
                    //stored in NFCID1 Number Register (0x17)
  #define NFC_Hi_rf 3   //Extended range for RF measurements

  #define NFC_Rfdet_h2 2//RF field level required for system wakeup

  #define NFC_Rfdet_h1 1//RF field level required for system wakeup

  #define NFC_Rfdet_h0 0//RF field level required for system wakeup
  /*****************************************************************************/
#define NFC_LFLR 0x19//NFC Target Protocol Register
  #define NFC_Rf_h 7    //RF level is above the wake-up level setting

  #define NFC_Rf_l 6    //RF level is above the RF collision avoidance level stting

  #define NFC_FeliCa 4  //FeliCa protocol 1
                    //ISO/IEC 14443 A protocol 0
  #define NFC_Pas_106 3 //Passive target at 106kbps or transponder emulation

  #define NFC_Pas_14443B 2  //ISO/IEC 14443 B transponder emulation

  #define NFC_NFCBR1 1  //Bit rate of first received command

  #define NFC_NFCBR0 0  //Bit rate of first received command
/*****************************************************************************/
#define NFC_TR0 0x1A    //Test Register 0
  #define NFC_OOK_Subc_In 7 //Subcarrier input

  #define NFC_MOD_Subc_Out 6//Subcarrier output

  #define NFC_MOD_Direct 5  //Direct TX modulation and RX reset

  #define NFC_o_sel 4   //First stage output selection

  #define NFC_low2 3    //Second stage gain –6 dB

  #define NFC_low1 2    //First stage gain –6 dB

  #define NFC_zun 1     //Input followers test

  #define NFC_Test_AGC 0//AGC test, AGC level is seen on rssi_210 bits
/*****************************************************************************/
#define NFC_TR1 0x1B    //Test Register 1
  #define NFC_test_rf_level3 7  //RF level test

  #define NFC_test_rf_level2 6  //RF level test

  #define NFC_test_rf_level1 5  //RF level test

  #define NFC_test_rf_level0 4  //RF level test

  #define NFC_test_io1 3//I/O test

  #define NFC_test_io0 2//I/O test

  #define NFC_test_dec 1//Decoder test mode

  #define NFC_clock_su 0//Coder clock 13.56 MHz
/*****************************************************************************/
#define NFC_FIFOSR 0x1C //FIFO Status Register
  #define NFC_Foverflow 7 //FIFO overflow error

  #define NFC_Fb6 6     //FIFO bytes fb[6]

  #define NFC_Fb5 5     //FIFO bytes fb[5]

  #define NFC_Fb4 4     //FIFO bytes fb[4]

  #define NFC_Fb3 3     //FIFO bytes fb[3]

  #define NFC_Fb2 2     //FIFO bytes fb[2]

  #define NFC_Fb1 1     //FIFO bytes fb[1]

  #define NFC_Fb0 0     //FIFO bytes fb[0]
/*****************************************************************************/
#define NFC_TXLB1R 0x1D //TX Length Byte 1 Register
  #define NFC_Txl11 7   //Number of complete byte bn[11]

  #define NFC_Txl10 6   //Number of complete byte bn[10]

  #define NFC_Txl9 5    //Number of complete byte bn[9]

  #define NFC_Txl8 4    //Number of complete byte bn[8]

  #define NFC_Txl7 3    //Number of complete byte bn[7]

  #define NFC_Txl6 2    //Number of complete byte bn[6]

  #define NFC_Txl5 1    //Number of complete byte bn[5]

  #define NFC_Txl4 0    //Number of complete byte bn[4]
/*****************************************************************************/
#define NFC_TXLB2R 0x1E //TX Length Byte 2 Register
  #define NFC_Txl3 7    //Number of complete byte bn[3]

  #define NFC_Txl2 6    //Number of complete byte bn[2]

  #define NFC_Txl1 5    //Number of complete byte bn[1]

  #define NFC_Txl0 4    //Number of complete byte bn[0]

  #define NFC_Bb2 3     //Broken byte number of bitsbb[2]

  #define NFC_Bb1 2     //Broken byte number of bitsbb[1]

  #define NFC_Bb0 1     //Broken byte number of bitsbb[0]

  #define NFC_Bbf 0     //Broken byte flat
/*****************************************************************************/
#define NFC_FIFO 0x1F   //FIFO Register 127 bytes
#endif  //COMMS_H
