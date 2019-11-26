#ifndef LoraLowLevel_H
#define LoraLowLevel_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

struct pomiar_single_ {
  uint16_t sens_nr;
  uint16_t temper;
};

typedef enum {
  CMND_nn = 0,
  L_Pdown,
  L_HS_rcv_F0_start,
  L_HS_F0_rcvd,
  L_HS_F0_OK_ACK,
  L_HS_F0_format_fail,
  L_HS_F1_ACK_start,
  L_HS_F1_ACK_timeout,
  L_HS_F1_ACK_sent,
  L_F1_data_rcv_start,
  L_F1_data_rcv_timeout,
  L_F1_data_rcvd,
  L_F1_data_ACK_start,
  L_F1_data_ACK_timeout,
  L_F1_data_ACK_sent,
  L_data_rcvd,
} LoRa_enums_rcv_;

typedef enum {
  CMND_nn = 0,
  L_Pdown,
  L_HS_F0_tmt_start,
  L_HS_F0_retmt_delay,
  L_HS_F1_rcv_start,
  L_HS_F1_rcvd,
  L_HS_F1_format_fail,
  L_HS_F1_fail_delay,
  L_HS_F1_OK_ACK,
  L_F1_data_tmt_start,
  L_F1_ACK_rcv_start,
  L_F1_ACK_rcvd,
  L_F1_ACK_OK,
  L_F1_ACK_format_fail,
  L_data_sent,
} LoRa_enums_snd_;

struct LoRa_rcv_cfg_ {
  uint8_t adres;
  freq_code freq_code;
  uint8_t len;
  uint8_t timeout_cntr;  //  Delay timeout timer
  LoRa_enums_rcv_ LoRa_state;
  uint8_t SNR_to_send;
  bool data_ready;
};

struct LoRa_transfer_cfg_ {
  uint8_t adres;
  freq_code freq_code;
  uint8_t len;
  uint8_t bufor[300];
  LoRa_enums_snd_ LoRa_state;
  uint8_t rcvd_SNR;
  uint8_t try_cntr;
  bool data_ready;
  bool low_bat;
};

struct LoRa_rcv_struct_ {
  uint8_t lnght;
  uint8_t bufor[255];
  uint16_t voltage;
  bool data_ready;
};

struct LoRa_transfer_struct_ {
  uint8_t lnght;
  uint8_t bufor[255];
  bool data_ready;
};

void LoRa_main_initialize(void);  //  Lora initialization
void LoRa_transmit_start(void);
void LoRa_TX_start(void);  //  Initiation of send
void LoRa_TX_done(void);   //  Indicator of send done

void LoRa_set_freq_param(
    uint8_t freq, uint8_t SF_BW,
    struct LoRa_transfer_cfg_
        *data_to_send);  // Should be invoked before LoRa_prepare_bufor_to_send
void LoRa_prepare_bufor_to_send(uint8_t *buffer, uint8_t bufferLen,
                                struct LoRa_transfer_cfg_ *data_to_send);

#endif
