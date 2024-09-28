/*
 * CS43L22_Defs.h
 *
 *  Created on: Sep 25, 2024
 *      Author: kunal
 */

#ifndef CS43L22_CS43L22_DEFS_H_
#define CS43L22_CS43L22_DEFS_H_

#include "main.h"

static const struct CS43L22_Configuration
{
	struct _Audio_Word_Length_{
		uint8_t _32_bit;
		uint8_t _24_bit;
		uint8_t _20_bit;
		uint8_t _16_bit;
	}_Audio_Word_Length_;

	struct _Headphone_Analog_Gain_
	{
		uint8_t Gain_0_3959;
		uint8_t Gain_0_4571;
		uint8_t Gain_0_5111;
		uint8_t Gain_0_6047;
		uint8_t Gain_0_7099;
		uint8_t Gain_0_8399;
		uint8_t Gain_1_0000;
		uint8_t Gain_1_1430;
	}_Headphone_Analog_Gain_;

	struct _Limiter_Cushion_Threshold_
	{
		uint8_t CUSH_0_dB;
		uint8_t CUSH_3_dB;
		uint8_t CUSH_6_dB;
		uint8_t CUSH_9_dB;
		uint8_t CUSH_12_dB;
		uint8_t CUSH_18_dB;
		uint8_t CUSH_24_dB;
		uint8_t CUSH_30_dB;
	}_Limiter_Cushion_Threshold_;

	struct _Limiter_Max_Threshold_
	{
		uint8_t LMAX_0_dB;
		uint8_t LMAX_3_dB;
		uint8_t LMAX_6_dB;
		uint8_t LMAX_9_dB;
		uint8_t LMAX_12_dB;
		uint8_t LMAX_18_dB;
		uint8_t LMAX_24_dB;
		uint8_t LMAX_30_dB;
	}_Limiter_Max_Threshold_;





}CS43L22_Configuration;

#endif /* CS43L22_CS43L22_DEFS_H_ */
