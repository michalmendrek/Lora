#include <Lora_LowLevel.h>

void LoRa_main_initialize(void) {}

void LoRa_transmit_start(void) {}
void LoRa_transmit_data(void) {}
void LoRa_byl_timeout(void) {}
void LoRa_TX_start(void) {}
void LoRa_TX_done(void) {}
void LoRa_finish(void) {}
void LoRa_timeout_Start(void) {}
void LoRa_timeout_Stop(void) {}
void LoRa_receive_start(void) {}
void LoRa_RX_start(void) {}
void LoRa_RX_fail(void) {}
void LoRa_RX_success(void) {}
bool LoRa_Interpret(void) {}
void LoRa_RX_done(void) {}
void LoRa_procs_RX_timeout(void) {}
void LoRa_procs_RX_stop(void) {}
void i_LoRa_Timeout(void) {}
void i_LoRa_Timeout_short(void) {}
void LoRa_procs_Mainloop(void) {}

void LoRa_set_freq_param(uint8_t freq, uint8_t SF_BW,
                         struct LoRa_transfer_cfg_ *data_to_send) {}
void LoRa_set_freq(freq_code freq_c) {}
void LoRa_set_power(uint8_t power) {}
void LoRa_prepare_bufor_to_send(uint8_t *buffer, uint8_t bufferLen,
                                struct LoRa_transfer_cfg_ *data_to_send) {}
