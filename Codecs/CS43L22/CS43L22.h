/*
 * CS43L22.h
 *
 *  Created on: Sep 25, 2024
 *      Author: kunal
 */

#ifndef CS43L22_CS43L22_H_
#define CS43L22_CS43L22_H_

#include "main.h"
#include "CS43L22_Defs.h"
#include "GPIO/GPIO.h"
#include "DMA/DMA.h"
#include "I2C/I2C.h"

#define CS43L22_Address 0x4A


typedef struct CS43L22_Config
{
	I2C_Config hardware_i2c;

	uint8_t treble_corner_frequency;
	uint8_t bass_corner_frequency;
	uint8_t treble_gain;
	uint8_t bass_gain;
	uint8_t master_volume;
	uint8_t headphone_volume_control;
	uint8_t speaker_volume_control;



}CS43L22_Config;


uint8_t CS43L22_Init(CS43L22_Config *config);
uint8_t CS43L22_Read_ID(CS43L22_Config *config);

uint8_t CS43L22_Set_Treble_Corner_Frequency(CS43L22_Config *config);
uint8_t CS43L22_Get_Treble_Corner_Frequency(CS43L22_Config *config);

uint8_t CS43L22_Set_Bass_Corner_Frequency(CS43L22_Config *config);
uint8_t CS43L22_Get_Bass_Corner_Frequency(CS43L22_Config *config);

uint8_t CS43L22_Tone_Control(CS43L22_Config *config);
uint8_t CS43L22_Tone_Control_Enable(CS43L22_Config *config);

uint8_t CS43L22_Master_Volume_Control(CS43L22_Config *config);
uint8_t CS43L22_Headphone_Volume_Control(CS43L22_Config *config);
uint8_t CS43L22_Speaker_Volume_Control(CS43L22_Config *config);

uint8_t CS43L22_Activate(CS43L22_Config *config);
uint8_t CS43L22_Deactivate(CS43L22_Config *config);


#endif /* CS43L22_CS43L22_H_ */
