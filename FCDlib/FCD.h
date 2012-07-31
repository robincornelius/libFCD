#ifndef __FCD_H
#define __FCD_H

#include "FCDlib.h"

#define bool int

#define FCD_HID_CMD_QUERY              1 // Returns string with "FCDAPP version"

#define FCD_HID_CMD_SET_FREQUENCY    100 // Send with 3 byte unsigned little endian frequency in kHz.
#define FCD_HID_CMD_SET_FREQUENCY_HZ 101 // Send with 4 byte unsigned little endian frequency in Hz, returns wit actual frequency set in Hz
#define FCD_HID_CMD_GET_FREQUENCY_HZ 102 // Returns 4 byte unsigned little endian frequency in Hz.

#define FCD_HID_CMD_GET_IF_RSSI      104 // Returns 1 byte unsigned IF RSSI, -35dBm ~=0, -10dBm ~=70.
#define FCD_HID_CMD_GET_PLL_LOCK     105 // Returns 1 bit, true if locked

#define FCD_HID_CMD_SET_DC_CORR      106 // Send with 2 byte unsigned I DC correction followed by 2 byte unsigned Q DC correction. 32768 is the default centre value.
#define FCD_HID_CMD_GET_DC_CORR      107 // Returns 2 byte unsigned I DC correction followed by 2 byte unsigned Q DC correction. 32768 is the default centre value.
#define FCD_HID_CMD_SET_IQ_CORR      108 // Send with 2 byte signed phase correction followed by 2 byte unsigned gain correction. 0 is the default centre value for phase correction, 32768 is the default centre value for gain.
#define FCD_HID_CMD_GET_IQ_CORR      109 // Returns 2 byte signed phase correction followed by 2 byte unsigned gain correction. 0 is the default centre value for phase correction, 32768 is the default centre value for gain.

#define FCD_HID_CMD_SET_LNA_GAIN     110 // Send a 1 byte value, see enums for reference
#define FCD_HID_CMD_SET_LNA_ENHANCE  111
#define FCD_HID_CMD_SET_BAND         112
#define FCD_HID_CMD_SET_RF_FILTER    113
#define FCD_HID_CMD_SET_MIXER_GAIN   114
#define FCD_HID_CMD_SET_BIAS_CURRENT 115
#define FCD_HID_CMD_SET_MIXER_FILTER 116
#define FCD_HID_CMD_SET_IF_GAIN1     117
#define FCD_HID_CMD_SET_IF_GAIN_MODE 118
#define FCD_HID_CMD_SET_IF_RC_FILTER 119
#define FCD_HID_CMD_SET_IF_GAIN2     120
#define FCD_HID_CMD_SET_IF_GAIN3     121
#define FCD_HID_CMD_SET_IF_FILTER    122
#define FCD_HID_CMD_SET_IF_GAIN4     123
#define FCD_HID_CMD_SET_IF_GAIN5     124
#define FCD_HID_CMD_SET_IF_GAIN6     125

#define FCD_HID_CMD_GET_LNA_GAIN     150 // Retrieve a 1 byte value, see enums for reference
#define FCD_HID_CMD_GET_LNA_ENHANCE  151
#define FCD_HID_CMD_GET_BAND         152
#define FCD_HID_CMD_GET_RF_FILTER    153
#define FCD_HID_CMD_GET_MIXER_GAIN   154
#define FCD_HID_CMD_GET_BIAS_CURRENT 155
#define FCD_HID_CMD_GET_MIXER_FILTER 156
#define FCD_HID_CMD_GET_IF_GAIN1     157
#define FCD_HID_CMD_GET_IF_GAIN_MODE 158
#define FCD_HID_CMD_GET_IF_RC_FILTER 159
#define FCD_HID_CMD_GET_IF_GAIN2     160
#define FCD_HID_CMD_GET_IF_GAIN3     161
#define FCD_HID_CMD_GET_IF_FILTER    162
#define FCD_HID_CMD_GET_IF_GAIN4     163
#define FCD_HID_CMD_GET_IF_GAIN5     164
#define FCD_HID_CMD_GET_IF_GAIN6     165

#define FCD_HID_CMD_I2C_SEND_BYTE    200
#define FCD_HID_CMD_I2C_RECEIVE_BYTE 201

#define FCD_RESET                    255 // Reset to bootloader


typedef struct 
{
	char *pszDesc;
	unsigned char u8Val;

} COMBOITEMSTRUCT;

typedef struct
{
	unsigned char u8CommandSet;
	unsigned char u8CommandGet;
	int nIdxDefault;
	int nCurrentValue;
	const COMBOITEMSTRUCT *pacis;
} COMBOSTRUCT;

static const COMBOITEMSTRUCT _cisLNAGain[]=
{
	{"-5.0dB",TLGE_N5_0DB},
	{"-2.5dB",TLGE_N2_5DB},
	{"+0.0dB",TLGE_P0_0DB},
	{"+2.5dB",TLGE_P2_5DB},
	{"+5,0dB",TLGE_P5_0DB},
	{"+7.5dB",TLGE_P7_5DB},
	{"+10.0dB",TLGE_P10_0DB},
	{"+12.5dB",TLGE_P12_5DB},
	{"+15.0dB",TLGE_P15_0DB},
	{"+17.5dB",TLGE_P17_5DB},
	{"+20.0dB",TLGE_P20_0DB},
	{"+25.0dB",TLGE_P25_0DB},
	{"+30.0dB",TLGE_P30_0DB},
	{NULL,0}
};

static const COMBOITEMSTRUCT _cisLNAEnhance[]=
{
	{"Off",TLEE_OFF},
	{"0",TLEE_0},
	{"1",TLEE_1},
	{"2",TLEE_2},
	{"3",TLEE_3},
	{NULL,0}
};

static const COMBOITEMSTRUCT _cisBand[]=
{
	{"VHF II",TBE_VHF2},
	{"VHF III",TBE_VHF3},
	{"UHF",TBE_UHF},
	{"L band",TBE_LBAND},
	{NULL,0}
};

static const COMBOITEMSTRUCT _cisRFFilter0[]=
{
	{"268MHz LPF",TRFE_LPF268MHZ},
	{"299MHz LPF",TRFE_LPF268MHZ},
	{NULL,0}
};

static const COMBOITEMSTRUCT _cisRFFilter1[]=
{
	{"509MHz LPF",TRFE_LPF509MHZ},
	{"656MHz LPF",TRFE_LPF656MHZ},
	{NULL,0}
};

static const COMBOITEMSTRUCT _cisRFFilter2[]=
{
	{"360MHz BPF",TRFE_BPF360MHZ},
	{"380MHz BPF",TRFE_BPF380MHZ},
	{"405MHz BPF",TRFE_BPF405MHZ},
	{"425MHz BPF",TRFE_BPF425MHZ},
	{"450MHz BPF",TRFE_BPF450MHZ},
	{"475MHz BPF",TRFE_BPF475MHZ},
	{"505MHz BPF",TRFE_BPF505MHZ},
	{"540MHz BPF",TRFE_BPF540MHZ},
	{"575MHz BPF",TRFE_BPF575MHZ},
	{"615MHz BPF",TRFE_BPF615MHZ},
	{"670MHz BPF",TRFE_BPF670MHZ},
	{"720MHz BPF",TRFE_BPF720MHZ},
	{"760MHz BPF",TRFE_BPF760MHZ},
	{"840MHz BPF",TRFE_BPF840MHZ},
	{"890MHz BPF",TRFE_BPF890MHZ},
	{"970MHz BPF",TRFE_BPF970MHZ},
	{NULL,0}
};

static const COMBOITEMSTRUCT _cisRFFilter3[]=
{
	{"1300MHz BPF",TRFE_BPF1300MHZ},
	{"1320MHz BPF",TRFE_BPF1320MHZ},
	{"1360MHz BPF",TRFE_BPF1360MHZ},
	{"1410MHz BPF",TRFE_BPF1410MHZ},
	{"1445MHz BPF",TRFE_BPF1445MHZ},
	{"1460MHz BPF",TRFE_BPF1460MHZ},
	{"1490MHz BPF",TRFE_BPF1490MHZ},
	{"1530MHz BPF",TRFE_BPF1530MHZ},
	{"1560MHz BPF",TRFE_BPF1560MHZ},
	{"1590MHz BPF",TRFE_BPF1590MHZ},
	{"1640MHz BPF",TRFE_BPF1640MHZ},
	{"1660MHz BPF",TRFE_BPF1660MHZ},
	{"1680MHz BPF",TRFE_BPF1680MHZ},
	{"1700MHz BPF",TRFE_BPF1700MHZ},
	{"1720MHz BPF",TRFE_BPF1720MHZ},
	{"1750MHz BPF",TRFE_BPF1750MHZ},
	{NULL,0}
};

static const COMBOITEMSTRUCT _cisMixerGain[]=
{
	{"4dB",TMGE_P4_0DB},
	{"12dB",TMGE_P12_0DB},
	{NULL,0}
};

static const COMBOITEMSTRUCT _cisBiasCurrent[]=
{
	{"00 L band",TBCE_LBAND},
	{"01",TBCE_1},
	{"10",TBCE_2},
	{"11 V/U band",TBCE_VUBAND},
	{NULL,0}
};

static const COMBOITEMSTRUCT _cisMixerFilter[]=
{
	{"1.9MHz",TMFE_1_9MHZ},
	{"2.3MHz",TMFE_2_3MHZ},
	{"2.7MHz",TMFE_2_7MHZ},
	{"3.0MHz",TMFE_3_0MHZ},
	{"3.4MHz",TMFE_3_4MHZ},
	{"3.8MHz",TMFE_3_8MHZ},
	{"4.2MHz",TMFE_4_2MHZ},
	{"4.6MHz",TMFE_4_6MHZ},
	{"27MHz",TMFE_27_0MHZ},
	{NULL,0}
};

static const COMBOITEMSTRUCT _cisIFGain1[]=
{
	{"-3dB",TIG1E_N3_0DB},
	{"+6dB",TIG1E_P6_0DB},
	{NULL,0}
};

static const COMBOITEMSTRUCT _cisIFGainMode[]=
{
	{"Linearity",TIGME_LINEARITY},
	{"Sensitivity",TIGME_SENSITIVITY},
	{NULL,0}
};

static const COMBOITEMSTRUCT _cisIFRCFilter[]=
{
	{"1.0MHz",TIRFE_1_0MHZ},
	{"1.2MHz",TIRFE_1_2MHZ},
	{"1.8MHz",TIRFE_1_8MHZ},
	{"2.6MHz",TIRFE_2_6MHZ},
	{"3.4MHz",TIRFE_3_4MHZ},
	{"4.4MHz",TIRFE_4_4MHZ},
	{"5.3MHz",TIRFE_5_3MHZ},
	{"6.4MHz",TIRFE_6_4MHZ},
	{"7.7MHz",TIRFE_7_7MHZ},
	{"9.0MHz",TIRFE_9_0MHZ},
	{"10.6MHz",TIRFE_10_6MHZ},
	{"12.4MHz",TIRFE_12_4MHZ},
	{"14.7MHz",TIRFE_14_7MHZ},
	{"17.6MHz",TIRFE_17_6MHZ},
	{"21.0MHz",TIRFE_21_0MHZ},
	{"21.4MHz",TIRFE_21_4MHZ},
	{NULL,0}
};

static const COMBOITEMSTRUCT _cisIFGain2[]=
{
	{"0dB",TIG2E_P0_0DB},
	{"+3dB",TIG2E_P3_0DB},
	{"+6dB",TIG2E_P6_0DB},
	{"+9dB",TIG2E_P9_0DB},
	{NULL,0}
};

static const COMBOITEMSTRUCT _cisIFGain3[]=
{
	{"0dB",TIG3E_P0_0DB},
	{"+3dB",TIG3E_P3_0DB},
	{"+6dB",TIG3E_P6_0DB},
	{"+9dB",TIG3E_P9_0DB},
	{NULL,0}
};

static const COMBOITEMSTRUCT _cisIFGain4[]=
{
	{"0dB",TIG4E_P0_0DB},
	{"+1dB",TIG4E_P1_0DB},
	{"+2dB",TIG4E_P2_0DB},
	{NULL,0}
};

static const COMBOITEMSTRUCT _cisIFFilter[]=
{
	{"2.15MHz",TIFE_2_15MHZ},
	{"2.20MHz",TIFE_2_20MHZ},
	{"2.24MHz",TIFE_2_24MHZ},
	{"2.28MHz",TIFE_2_28MHZ},
	{"2.30MHz",TIFE_2_30MHZ},
	{"2.40MHz",TIFE_2_40MHZ},
	{"2.45MHz",TIFE_2_45MHZ},
	{"2.50MHz",TIFE_2_50MHZ},
	{"2.55MHz",TIFE_2_55MHZ},
	{"2.60MHz",TIFE_2_60MHZ},
	{"2.70MHz",TIFE_2_70MHZ},
	{"2.75MHz",TIFE_2_75MHZ},
	{"2.80MHz",TIFE_2_80MHZ},
	{"2.90MHz",TIFE_2_90MHZ},
	{"2.95MHz",TIFE_2_95MHZ},
	{"3.00MHz",TIFE_3_00MHZ},
	{"3.10MHz",TIFE_3_10MHZ},
	{"3.20MHz",TIFE_3_20MHZ},
	{"3.30MHz",TIFE_3_30MHZ},
	{"3.40MHz",TIFE_3_40MHZ},
	{"3.60MHz",TIFE_3_60MHZ},
	{"3.70MHz",TIFE_3_70MHZ},
	{"3.80MHz",TIFE_3_80MHZ},
	{"3.90MHz",TIFE_3_90MHZ},
	{"4.10MHz",TIFE_4_10MHZ},
	{"4.30MHz",TIFE_4_30MHZ},
	{"4.40MHz",TIFE_4_40MHZ},
	{"4.60MHz",TIFE_4_60MHZ},
	{"4.80MHz",TIFE_4_80MHZ},
	{"5.00MHz",TIFE_5_00MHZ},
	{"5.30MHz",TIFE_5_30MHZ},
	{"5.50MHz",TIFE_5_50MHZ},
	{NULL,0}
};

static const COMBOITEMSTRUCT _cisIFGain5[]=
{
	{"+3dB",TIG5E_P3_0DB},
	{"+6dB",TIG5E_P6_0DB},
	{"+9dB",TIG5E_P9_0DB},
	{"+12dB",TIG5E_P12_0DB},
	{"+15dB",TIG5E_P15_0DB},
	{NULL,0}
};

static const COMBOITEMSTRUCT _cisIFGain6[]=
{
	{"+3dB",TIG6E_P3_0DB},
	{"+6dB",TIG6E_P6_0DB},
	{"+9dB",TIG6E_P9_0DB},
	{"+12dB",TIG6E_P12_0DB},
	{"+15dB",TIG6E_P15_0DB},
	{NULL,0}
};

#define FCD_HID_CMD_SET_LNA_GAIN     110 // Send a 1 byte value, see enums for reference
#define FCD_HID_CMD_SET_LNA_ENHANCE  111
#define FCD_HID_CMD_SET_BAND         112
#define FCD_HID_CMD_SET_RF_FILTER    113
#define FCD_HID_CMD_SET_MIXER_GAIN   114
#define FCD_HID_CMD_SET_BIAS_CURRENT 115
#define FCD_HID_CMD_SET_MIXER_FILTER 116
#define FCD_HID_CMD_SET_IF_GAIN1     117
#define FCD_HID_CMD_SET_IF_GAIN_MODE 118
#define FCD_HID_CMD_SET_IF_RC_FILTER 119
#define FCD_HID_CMD_SET_IF_GAIN2     120
#define FCD_HID_CMD_SET_IF_GAIN3     121
#define FCD_HID_CMD_SET_IF_FILTER    122
#define FCD_HID_CMD_SET_IF_GAIN4     123
#define FCD_HID_CMD_SET_IF_GAIN5     124
#define FCD_HID_CMD_SET_IF_GAIN6     125

#endif
