#ifndef __FCD_H
#define __FCD_H

#include "FCDlib.h"

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
	TCHAR *pszDesc;
	unsigned __int8 u8Val;

} COMBOITEMSTRUCT;

typedef struct
{
	unsigned __int8 u8CommandSet;
	unsigned __int8 u8CommandGet;
	int nIdxDefault;
	int nCurrentValue;
	const COMBOITEMSTRUCT *pacis;
} COMBOSTRUCT;

static const COMBOITEMSTRUCT _cisLNAGain[]=
{
	{_T("-5.0dB"),TLGE_N5_0DB},
	{_T("-2.5dB"),TLGE_N2_5DB},
	{_T("+0.0dB"),TLGE_P0_0DB},
	{_T("+2.5dB"),TLGE_P2_5DB},
	{_T("+5,0dB"),TLGE_P5_0DB},
	{_T("+7.5dB"),TLGE_P7_5DB},
	{_T("+10.0dB"),TLGE_P10_0DB},
	{_T("+12.5dB"),TLGE_P12_5DB},
	{_T("+15.0dB"),TLGE_P15_0DB},
	{_T("+17.5dB"),TLGE_P17_5DB},
	{_T("+20.0dB"),TLGE_P20_0DB},
	{_T("+25.0dB"),TLGE_P25_0DB},
	{_T("+30.0dB"),TLGE_P30_0DB},
	{NULL,0}
};

static const COMBOITEMSTRUCT _cisLNAEnhance[]=
{
	{_T("Off"),TLEE_OFF},
	{_T("0"),TLEE_0},
	{_T("1"),TLEE_1},
	{_T("2"),TLEE_2},
	{_T("3"),TLEE_3},
	{NULL,0}
};

static const COMBOITEMSTRUCT _cisBand[]=
{
	{_T("VHF II"),TBE_VHF2},
	{_T("VHF III"),TBE_VHF3},
	{_T("UHF"),TBE_UHF},
	{_T("L band"),TBE_LBAND},
	{NULL,0}
};

static const COMBOITEMSTRUCT _cisRFFilter0[]=
{
	{_T("268MHz LPF"),TRFE_LPF268MHZ},
	{_T("299MHz LPF"),TRFE_LPF268MHZ},
	{NULL,0}
};

static const COMBOITEMSTRUCT _cisRFFilter1[]=
{
	{_T("509MHz LPF"),TRFE_LPF509MHZ},
	{_T("656MHz LPF"),TRFE_LPF656MHZ},
	{NULL,0}
};

static const COMBOITEMSTRUCT _cisRFFilter2[]=
{
	{_T("360MHz BPF"),TRFE_BPF360MHZ},
	{_T("380MHz BPF"),TRFE_BPF380MHZ},
	{_T("405MHz BPF"),TRFE_BPF405MHZ},
	{_T("425MHz BPF"),TRFE_BPF425MHZ},
	{_T("450MHz BPF"),TRFE_BPF450MHZ},
	{_T("475MHz BPF"),TRFE_BPF475MHZ},
	{_T("505MHz BPF"),TRFE_BPF505MHZ},
	{_T("540MHz BPF"),TRFE_BPF540MHZ},
	{_T("575MHz BPF"),TRFE_BPF575MHZ},
	{_T("615MHz BPF"),TRFE_BPF615MHZ},
	{_T("670MHz BPF"),TRFE_BPF670MHZ},
	{_T("720MHz BPF"),TRFE_BPF720MHZ},
	{_T("760MHz BPF"),TRFE_BPF760MHZ},
	{_T("840MHz BPF"),TRFE_BPF840MHZ},
	{_T("890MHz BPF"),TRFE_BPF890MHZ},
	{_T("970MHz BPF"),TRFE_BPF970MHZ},
	{NULL,0}
};

static const COMBOITEMSTRUCT _cisRFFilter3[]=
{
	{_T("1300MHz BPF"),TRFE_BPF1300MHZ},
	{_T("1320MHz BPF"),TRFE_BPF1320MHZ},
	{_T("1360MHz BPF"),TRFE_BPF1360MHZ},
	{_T("1410MHz BPF"),TRFE_BPF1410MHZ},
	{_T("1445MHz BPF"),TRFE_BPF1445MHZ},
	{_T("1460MHz BPF"),TRFE_BPF1460MHZ},
	{_T("1490MHz BPF"),TRFE_BPF1490MHZ},
	{_T("1530MHz BPF"),TRFE_BPF1530MHZ},
	{_T("1560MHz BPF"),TRFE_BPF1560MHZ},
	{_T("1590MHz BPF"),TRFE_BPF1590MHZ},
	{_T("1640MHz BPF"),TRFE_BPF1640MHZ},
	{_T("1660MHz BPF"),TRFE_BPF1660MHZ},
	{_T("1680MHz BPF"),TRFE_BPF1680MHZ},
	{_T("1700MHz BPF"),TRFE_BPF1700MHZ},
	{_T("1720MHz BPF"),TRFE_BPF1720MHZ},
	{_T("1750MHz BPF"),TRFE_BPF1750MHZ},
	{NULL,0}
};

static const COMBOITEMSTRUCT _cisMixerGain[]=
{
	{_T("4dB"),TMGE_P4_0DB},
	{_T("12dB"),TMGE_P12_0DB},
	{NULL,0}
};

static const COMBOITEMSTRUCT _cisBiasCurrent[]=
{
	{_T("00 L band"),TBCE_LBAND},
	{_T("01"),TBCE_1},
	{_T("10"),TBCE_2},
	{_T("11 V/U band"),TBCE_VUBAND},
	{NULL,0}
};

static const COMBOITEMSTRUCT _cisMixerFilter[]=
{
	{_T("1.9MHz"),TMFE_1_9MHZ},
	{_T("2.3MHz"),TMFE_2_3MHZ},
	{_T("2.7MHz"),TMFE_2_7MHZ},
	{_T("3.0MHz"),TMFE_3_0MHZ},
	{_T("3.4MHz"),TMFE_3_4MHZ},
	{_T("3.8MHz"),TMFE_3_8MHZ},
	{_T("4.2MHz"),TMFE_4_2MHZ},
	{_T("4.6MHz"),TMFE_4_6MHZ},
	{_T("27MHz"),TMFE_27_0MHZ},
	{NULL,0}
};

static const COMBOITEMSTRUCT _cisIFGain1[]=
{
	{_T("-3dB"),TIG1E_N3_0DB},
	{_T("+6dB"),TIG1E_P6_0DB},
	{NULL,0}
};

static const COMBOITEMSTRUCT _cisIFGainMode[]=
{
	{_T("Linearity"),TIGME_LINEARITY},
	{_T("Sensitivity"),TIGME_SENSITIVITY},
	{NULL,0}
};

static const COMBOITEMSTRUCT _cisIFRCFilter[]=
{
	{_T("1.0MHz"),TIRFE_1_0MHZ},
	{_T("1.2MHz"),TIRFE_1_2MHZ},
	{_T("1.8MHz"),TIRFE_1_8MHZ},
	{_T("2.6MHz"),TIRFE_2_6MHZ},
	{_T("3.4MHz"),TIRFE_3_4MHZ},
	{_T("4.4MHz"),TIRFE_4_4MHZ},
	{_T("5.3MHz"),TIRFE_5_3MHZ},
	{_T("6.4MHz"),TIRFE_6_4MHZ},
	{_T("7.7MHz"),TIRFE_7_7MHZ},
	{_T("9.0MHz"),TIRFE_9_0MHZ},
	{_T("10.6MHz"),TIRFE_10_6MHZ},
	{_T("12.4MHz"),TIRFE_12_4MHZ},
	{_T("14.7MHz"),TIRFE_14_7MHZ},
	{_T("17.6MHz"),TIRFE_17_6MHZ},
	{_T("21.0MHz"),TIRFE_21_0MHZ},
	{_T("21.4MHz"),TIRFE_21_4MHZ},
	{NULL,0}
};

static const COMBOITEMSTRUCT _cisIFGain2[]=
{
	{_T("0dB"),TIG2E_P0_0DB},
	{_T("+3dB"),TIG2E_P3_0DB},
	{_T("+6dB"),TIG2E_P6_0DB},
	{_T("+9dB"),TIG2E_P9_0DB},
	{NULL,0}
};

static const COMBOITEMSTRUCT _cisIFGain3[]=
{
	{_T("0dB"),TIG3E_P0_0DB},
	{_T("+3dB"),TIG3E_P3_0DB},
	{_T("+6dB"),TIG3E_P6_0DB},
	{_T("+9dB"),TIG3E_P9_0DB},
	{NULL,0}
};

static const COMBOITEMSTRUCT _cisIFGain4[]=
{
	{_T("0dB"),TIG4E_P0_0DB},
	{_T("+1dB"),TIG4E_P1_0DB},
	{_T("+2dB"),TIG4E_P2_0DB},
	{NULL,0}
};

static const COMBOITEMSTRUCT _cisIFFilter[]=
{
	{_T("2.15MHz"),TIFE_2_15MHZ},
	{_T("2.20MHz"),TIFE_2_20MHZ},
	{_T("2.24MHz"),TIFE_2_24MHZ},
	{_T("2.28MHz"),TIFE_2_28MHZ},
	{_T("2.30MHz"),TIFE_2_30MHZ},
	{_T("2.40MHz"),TIFE_2_40MHZ},
	{_T("2.45MHz"),TIFE_2_45MHZ},
	{_T("2.50MHz"),TIFE_2_50MHZ},
	{_T("2.55MHz"),TIFE_2_55MHZ},
	{_T("2.60MHz"),TIFE_2_60MHZ},
	{_T("2.70MHz"),TIFE_2_70MHZ},
	{_T("2.75MHz"),TIFE_2_75MHZ},
	{_T("2.80MHz"),TIFE_2_80MHZ},
	{_T("2.90MHz"),TIFE_2_90MHZ},
	{_T("2.95MHz"),TIFE_2_95MHZ},
	{_T("3.00MHz"),TIFE_3_00MHZ},
	{_T("3.10MHz"),TIFE_3_10MHZ},
	{_T("3.20MHz"),TIFE_3_20MHZ},
	{_T("3.30MHz"),TIFE_3_30MHZ},
	{_T("3.40MHz"),TIFE_3_40MHZ},
	{_T("3.60MHz"),TIFE_3_60MHZ},
	{_T("3.70MHz"),TIFE_3_70MHZ},
	{_T("3.80MHz"),TIFE_3_80MHZ},
	{_T("3.90MHz"),TIFE_3_90MHZ},
	{_T("4.10MHz"),TIFE_4_10MHZ},
	{_T("4.30MHz"),TIFE_4_30MHZ},
	{_T("4.40MHz"),TIFE_4_40MHZ},
	{_T("4.60MHz"),TIFE_4_60MHZ},
	{_T("4.80MHz"),TIFE_4_80MHZ},
	{_T("5.00MHz"),TIFE_5_00MHZ},
	{_T("5.30MHz"),TIFE_5_30MHZ},
	{_T("5.50MHz"),TIFE_5_50MHZ},
	{NULL,0}
};

static const COMBOITEMSTRUCT _cisIFGain5[]=
{
	{_T("+3dB"),TIG5E_P3_0DB},
	{_T("+6dB"),TIG5E_P6_0DB},
	{_T("+9dB"),TIG5E_P9_0DB},
	{_T("+12dB"),TIG5E_P12_0DB},
	{_T("+15dB"),TIG5E_P15_0DB},
	{NULL,0}
};

static const COMBOITEMSTRUCT _cisIFGain6[]=
{
	{_T("+3dB"),TIG6E_P3_0DB},
	{_T("+6dB"),TIG6E_P6_0DB},
	{_T("+9dB"),TIG6E_P9_0DB},
	{_T("+12dB"),TIG6E_P12_0DB},
	{_T("+15dB"),TIG6E_P15_0DB},
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