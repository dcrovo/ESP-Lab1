/*
 * Copyright 2016-2023 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file    ESP-LAB1.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL46Z4.h"
#include "fsl_debug_console.h"

#define SSA_GPIO BOARD_INITPINS_SSA_GPIO
#define SSB_GPIO BOARD_INITPINS_SSB_GPIO
#define SSC_GPIO BOARD_INITPINS_SSC_GPIO
#define SSD_GPIO BOARD_INITPINS_SSD_GPIO
#define SSE_GPIO BOARD_INITPINS_SSE_GPIO
#define SSF_GPIO BOARD_INITPINS_SSF_GPIO
#define SSG_GPIO BOARD_INITPINS_SSG_GPIO
#define SSP_GPIO BOARD_INITPINS_SSDP_GPIO

#define SSA_PIN BOARD_INITPINS_SSA_PIN
#define SSB_PIN BOARD_INITPINS_SSB_PIN
#define SSC_PIN BOARD_INITPINS_SSC_PIN
#define SSD_PIN BOARD_INITPINS_SSD_PIN
#define SSE_PIN BOARD_INITPINS_SSE_PIN
#define SSF_PIN BOARD_INITPINS_SSF_PIN
#define SSG_PIN BOARD_INITPINS_SSG_PIN
#define SSP_PIN BOARD_INITPINS_SSDP_PIN

#define SW_1_GPIO BOARD_INITPINS_SW_1_GPIO
#define SW_2_GPIO BOARD_INITPINS_SW_2_GPIO
#define SW_3_GPIO BOARD_INITPINS_SW_3_GPIO

#define SW_1_PIN BOARD_INITPINS_SW_1_PIN
#define SW_2_PIN BOARD_INITPINS_SW_2_PIN
#define SW_3_PIN BOARD_INITPINS_SW_3_PIN

#define OFF 0
#define ST1 1 // Just one bit ON
#define ST2 2 // Two bits ON
#define ST3 3 // Three bits ON

void ReadInput();
void OffAll();
void OnLeft();
void OnRight();
void OnCentral();
void InitPit();
void PitTriggerHandle();
/*
 * @brief   Application entry point.
 */
uint32_t ctrl_bits [3] = {0,0,0};
volatile bool pitFlag = true;
int counter = 0;
int state = OFF;


int main(void) {
    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

	InitPit();

	while(true) {
		PitTriggerHandle();
		ReadInput();
		if(pitFlag){
			switch(state){
			case OFF:
				OffAll();
				break;

			case ST1:
				if(counter == 0){
					if(ctrl_bits[0]){
						OnLeft();
					} else if(ctrl_bits[1]){
						OnCentral();
					}
					else if(ctrl_bits[2]){
						OnRight();

					}
				}else{
					OffAll();
				}
				counter >= 1 ? counter = 0: counter++;


				break;

			case ST2:
				if(counter == 0){

					if((ctrl_bits[0] & ctrl_bits[1]) | (ctrl_bits[0] & ctrl_bits[2])){
						OnLeft();
					} else if((ctrl_bits[1] & ctrl_bits[2])){
						OnCentral();
					}

				}
				else if(counter == 2){

					if((ctrl_bits[0] & ctrl_bits[1])){
						OnCentral();
					} else if((ctrl_bits[0] & ctrl_bits[2])){
						OnRight();
					}
					else if((ctrl_bits[1] & ctrl_bits[2])){
						OnRight();
					}

				}else{
					OffAll();
				}
				counter >= 3 ? counter = 0: counter++;

				break;
				case ST3:
					if(counter == 0){

						OnLeft();
					}
					else if(counter == 2){
						OnCentral();

					}
					else if(counter == 4){
						OnRight();
					}else{
						OffAll();
					}
					counter >= 5 ? counter = 0: counter++;

				break;
				default:
					PRINTF("Error");
				break;

			}
		}
		pitFlag=false;
	}


    return 0 ;
}

/* Functions definition*/

void InitPit()
{
	SIM->SCGC6 |= SIM_SCGC6_PIT_MASK; // Enable clock to PIT module
	PIT->MCR = 0x00;// Enable PIT module
	PIT->CHANNEL[0].LDVAL = 0xB71AFF; //
	PIT->CHANNEL[0].TCTRL |= PIT_TCTRL_TEN_MASK; // Enable timer

}
void PitTriggerHandle(){
	if(PIT->CHANNEL[0].TFLG & PIT_TFLG_TIF_MASK){
		PIT->CHANNEL[0].TFLG &= PIT_TFLG_TIF_MASK; // Clear the interrupt flag
		pitFlag=true;
	}
}
void ReadInput(){
	ctrl_bits[0] = GPIO_PinRead(SW_1_GPIO, SW_1_PIN);
	ctrl_bits[1] = GPIO_PinRead(SW_2_GPIO, SW_2_PIN);
	ctrl_bits[2] = GPIO_PinRead(SW_3_GPIO, SW_3_PIN);
	state = ((ctrl_bits[0]) & 1 ) + ((ctrl_bits[1]) & 1 ) +((ctrl_bits[2]) & 1 );
}



void OnLeft(){
	GPIO_WritePinOutput(SSA_GPIO,SSA_PIN,1);
	GPIO_WritePinOutput(SSB_GPIO,SSB_PIN,1);
	GPIO_WritePinOutput(SSC_GPIO,SSC_PIN,1);
	GPIO_WritePinOutput(SSD_GPIO,SSD_PIN,1);
	GPIO_WritePinOutput(SSE_GPIO,SSE_PIN,0);
	GPIO_WritePinOutput(SSF_GPIO,SSF_PIN,0);
	GPIO_WritePinOutput(SSG_GPIO,SSG_PIN,1);
	GPIO_WritePinOutput(SSP_GPIO,SSP_PIN,1);
}

void OnRight(){
	GPIO_WritePinOutput(SSA_GPIO,SSA_PIN,1);
	GPIO_WritePinOutput(SSB_GPIO,SSB_PIN,0);
    GPIO_WritePinOutput(SSC_GPIO,SSC_PIN,0);
	GPIO_WritePinOutput(SSD_GPIO,SSD_PIN,1);
	GPIO_WritePinOutput(SSE_GPIO,SSE_PIN,1);
	GPIO_WritePinOutput(SSF_GPIO,SSF_PIN,1);
	GPIO_WritePinOutput(SSG_GPIO,SSG_PIN,1);
	GPIO_WritePinOutput(SSP_GPIO,SSP_PIN,1);
}
void OnCentral(){
	GPIO_WritePinOutput(SSA_GPIO,SSA_PIN,0);
	GPIO_WritePinOutput(SSB_GPIO,SSB_PIN,1);
	GPIO_WritePinOutput(SSC_GPIO,SSC_PIN,1);
	GPIO_WritePinOutput(SSD_GPIO,SSD_PIN,0);
	GPIO_WritePinOutput(SSE_GPIO,SSE_PIN,1);
	GPIO_WritePinOutput(SSF_GPIO,SSF_PIN,1);
	GPIO_WritePinOutput(SSG_GPIO,SSG_PIN,0);
	GPIO_WritePinOutput(SSP_GPIO,SSP_PIN,1);
}

void OffAll(){
	GPIO_WritePinOutput(SSA_GPIO,SSA_PIN,1);
	GPIO_WritePinOutput(SSB_GPIO,SSB_PIN,1);
	GPIO_WritePinOutput(SSC_GPIO,SSC_PIN,1);
	GPIO_WritePinOutput(SSD_GPIO,SSD_PIN,1);
	GPIO_WritePinOutput(SSE_GPIO,SSE_PIN,1);
	GPIO_WritePinOutput(SSF_GPIO,SSF_PIN,1);
	GPIO_WritePinOutput(SSG_GPIO,SSG_PIN,1);
	GPIO_WritePinOutput(SSP_GPIO,SSP_PIN,1);
}

