// FCDlib.cpp : Defines the exported functions for the DLL application.
//

#include <stdio.h>
#include <stdlib.h>
#include "tchar.h"
#include "fcd.h"
#include "HID.h"

#define bool int

COMBOSTRUCT _acs[]=
{
	FCD_HID_CMD_SET_LNA_GAIN,    FCD_HID_CMD_GET_LNA_GAIN,    10,0,    _cisLNAGain,
	FCD_HID_CMD_SET_LNA_ENHANCE, FCD_HID_CMD_GET_LNA_ENHANCE,  0,0, _cisLNAEnhance,
	FCD_HID_CMD_SET_BAND,        FCD_HID_CMD_GET_BAND,         0,0,       _cisBand,
	FCD_HID_CMD_SET_RF_FILTER,   FCD_HID_CMD_GET_RF_FILTER,    0,0,   _cisRFFilter1,
	FCD_HID_CMD_SET_MIXER_GAIN,  FCD_HID_CMD_GET_MIXER_GAIN,   1,0,  _cisMixerGain,
	FCD_HID_CMD_SET_BIAS_CURRENT,FCD_HID_CMD_GET_BIAS_CURRENT, 3,0,_cisBiasCurrent,
	FCD_HID_CMD_SET_MIXER_FILTER,FCD_HID_CMD_GET_MIXER_FILTER, 0,0,_cisMixerFilter,
	FCD_HID_CMD_SET_IF_GAIN1,    FCD_HID_CMD_GET_IF_GAIN1,     1,0,    _cisIFGain1,
	FCD_HID_CMD_SET_IF_GAIN_MODE,FCD_HID_CMD_GET_IF_GAIN_MODE, 0,0, _cisIFGainMode,
	FCD_HID_CMD_SET_IF_RC_FILTER,FCD_HID_CMD_GET_IF_RC_FILTER, 0,0, _cisIFRCFilter,
	FCD_HID_CMD_SET_IF_GAIN2,    FCD_HID_CMD_GET_IF_GAIN2,     0,0,    _cisIFGain2,
	FCD_HID_CMD_SET_IF_GAIN3,    FCD_HID_CMD_GET_IF_GAIN3,     0,0,    _cisIFGain3,
	FCD_HID_CMD_SET_IF_GAIN4,    FCD_HID_CMD_GET_IF_GAIN4,     0,0,    _cisIFGain4,
	FCD_HID_CMD_SET_IF_FILTER,   FCD_HID_CMD_GET_IF_FILTER,    0,0,   _cisIFFilter,
	FCD_HID_CMD_SET_IF_GAIN5,    FCD_HID_CMD_GET_IF_GAIN5,     0,0,    _cisIFGain5,
	FCD_HID_CMD_SET_IF_GAIN6,    FCD_HID_CMD_GET_IF_GAIN6,     0,0,    _cisIFGain6,
	0,0,0,-1,NULL
};

bool resetFCD()
{
	return HIDWriteCommand(255,0,NULL);
}

int FCD_set_frequency(int freq)
{
	char freqbytes[3];
	freqbytes[0]=(unsigned char)freq;
	freqbytes[1]=(unsigned char)(freq>>8);
	freqbytes[2]=(unsigned char)(freq>>16);

	if(HIDWriteCommand(255,3,freqbytes))
	{
		printf("Success FCD frequency set\n");
		return 1;
	}
	else
	{
		printf("Error, FCD frequency NOT set\n");
		return 0;
	}

}

void FCD_set_defaults()
{
	COMBOSTRUCT *pcs=_acs;
	while (pcs->pacis!=NULL)
	{
		char u8;
		HIDWriteCommand(pcs->u8CommandGet,1,(char*)&pcs->nIdxDefault);
		printf("HID Write %d YX %d\n",pcs->u8CommandSet,pcs->nIdxDefault);
		HIDReadCommand(pcs->u8CommandGet,1,&u8);
		if(u8!=pcs->nIdxDefault)
		{
			printf("Default set failed\n");
		}
		pcs++;
	}
}

void readall()
{
	COMBOSTRUCT *pcs=_acs;
	while (pcs->pacis!=NULL)
	{
		char u8;
		HIDReadCommand(pcs->u8CommandGet,1,&u8);
		pcs->nCurrentValue=u8;
		pcs++;
	}
}

int FCD_init()
{
	char szVersionRead[61];
	szVersionRead[60]=0;

	if(HIDopen()!=0)
		return -1;
	
	HIDQuery(60,szVersionRead);
	printf("Version: %s\n",szVersionRead);
	//TODO version check

	readall();

	return 0;
}

void FCD_close()
{
	HIDclose();
}

int FCD_set_RF_LNA(TUNERLNAGAINENUM setting)
{
	char data[1];
	data[0]=setting;
	return HIDWriteCommand(FCD_HID_CMD_SET_LNA_GAIN,1,data);
}

int FCD_set_LNA_Enhance(TUNERLNAENHANCEENUM setting)
{
	char data[1];
	data[0]=setting;
	return HIDWriteCommand(FCD_HID_CMD_SET_LNA_ENHANCE,1,data);
}

int FCD_set_Band(TUNERBANDENUM setting)
{
	char data[1];
	data[0]=setting;
	return HIDWriteCommand(FCD_HID_CMD_SET_BAND,1,data);
}

int FCD_set_RFFilter(TUNERRFFILTERENUM setting)
{
	char data[1];
	data[0]=setting;
	return HIDWriteCommand(FCD_HID_CMD_SET_RF_FILTER,1,data);
}

int FCD_set_MixerGain(TUNERMIXERGAINENUM setting)
{
	char data[1];
	data[0]=setting;
	return HIDWriteCommand(FCD_HID_CMD_SET_MIXER_GAIN,1,data);
}

int FCD_set_BiasCurrent(TUNERBIASCURRENTENUM setting)
{
	char data[1];
	data[0]=setting;
	return HIDWriteCommand(FCD_HID_CMD_SET_BIAS_CURRENT,1,data);
}

int FCD_set_MixerFilter(TUNERMIXERFILTERENUM setting)
{
	char data[1];
	data[0]=setting;
	return HIDWriteCommand(FCD_HID_CMD_SET_MIXER_FILTER,1,data);
}

int FCD_set_IFGain1(TUNERIFGAIN1ENUM setting)
{
	char data[1];
	data[0]=setting;
	return HIDWriteCommand(FCD_HID_CMD_SET_IF_GAIN1,1,data);
}

int FCD_set_IFGainMode(TUNERIFGAINMODEENUM setting)
{
	char data[1];
	data[0]=setting;
	return HIDWriteCommand(FCD_HID_CMD_SET_IF_GAIN_MODE,1,data);
}

int FCD_set_IFRCFilter(TUNERIFRCFILTERENUM setting)
{
	char data[1];
	data[0]=setting;
	return HIDWriteCommand(FCD_HID_CMD_GET_IF_RC_FILTER,1,data);
}

int FCD_set_IFGain2(TUNERIFGAIN2ENUM setting)
{
	char data[1];
	data[0]=setting;
	return HIDWriteCommand(FCD_HID_CMD_GET_IF_GAIN2,1,data);
}

int FCD_set_IFGain3(TUNERIFGAIN3ENUM setting)
{
	char data[1];
	data[0]=setting;
	return HIDWriteCommand(FCD_HID_CMD_GET_IF_GAIN3,1,data);
}
int FCD_set_IFGain4(TUNERIFGAIN4ENUM setting)
{
	char data[1];
	data[0]=setting;
	return HIDWriteCommand(FCD_HID_CMD_GET_IF_GAIN4,1,data);
}

int FCD_set_IFFilter(TUNERIFFILTERENUM setting)
{
	char data[1];
	data[0]=setting;
	return HIDWriteCommand(FCD_HID_CMD_GET_IF_FILTER,1,data);
}


int FCD_set_IFGain5(TUNERIFGAIN5ENUM setting)
{
	char data[1];
	data[0]=setting;
	return HIDWriteCommand(FCD_HID_CMD_GET_IF_GAIN5,1,data);
}

int FCD_set_IFGain6(TUNERIFGAIN6ENUM setting)
{
	char data[1];
	data[0]=setting;
	return HIDWriteCommand(FCD_HID_CMD_GET_IF_GAIN6,1,data);
}













