
#include <stdio.h>
#include <tchar.h>

#include "hidapi.h"
#include "FCD.h"
#include "HID.h"

hid_device *handle;

int HIDopen()
{
	int res;
	#define MAX_STR 255
	wchar_t wstr[MAX_STR];

	// Open the device using the VID, PID,
	// and optionally the Serial number.
	handle = hid_open(0x4d8, 0xfb56, NULL);

	if(handle==0)
	{
		printf("Error bad handle, device not found\n");
		return -1;
	}

	// Read the Manufacturer String
	res = hid_get_manufacturer_string(handle, wstr, MAX_STR);
	printf("Manufacturer String: %ls\n", wstr);

	// Read the Product String
	res = hid_get_product_string(handle, wstr, MAX_STR);
	printf("Product String: %ls\n", wstr);

	// Read the Serial Number String
	res = hid_get_serial_number_string(handle, wstr, MAX_STR);
	printf("Serial Number String: %ls", wstr);
	printf("\n");

	return 0;

}

void HIDclose()
{
	hid_close(handle);
	handle=0;
}

void hidshake(unsigned char * au8BufOut,unsigned char * au8BufIn)
{
	int res;

	if(handle==0)
	{
		printf("Error invalid handle\n");
		return;
	}

	hid_write(handle, au8BufOut, 65);
	res = hid_read(handle, au8BufIn, 65);
	if (res < 0)
		printf("Unable to read HID packet()\n");
}

int HIDQuery(int maxlen,char * data)
{
	unsigned char au8BufOut[65]; // endpoint size + 1
	unsigned char au8BufIn[65]; // endpoint size + 1

	// Clean out any outstanding reads
	au8BufOut[0]=0; // First byte is report ID. Ignored by HID Class firmware as only config'd for one report
	au8BufOut[1]=FCD_HID_CMD_QUERY;
	//sleep(10);
	hidshake(au8BufOut,au8BufIn);
	memcpy(data,au8BufIn+2,maxlen);
	return au8BufIn[1]==1;
}

int HIDReadCommand(char u8Cmd, int len,char* data)
{
	unsigned char au8BufOut[65]; // endpoint size + 1
	unsigned char au8BufIn[65]; // endpoint size + 1
	au8BufOut[0]=0; // First byte is report ID. Ignored by HID Class firmware as only config'd for one report
	au8BufOut[1]=u8Cmd;
	hidshake(au8BufOut,au8BufIn);
	memcpy(data,au8BufIn+2,len);
	return au8BufIn[1]==1;
}

int HIDWriteCommand(char u8Cmd, int len,char* data)
{
	unsigned char au8BufOut[65]; // endpoint size + 1
	unsigned char au8BufIn[65]; // endpoint size + 1
	au8BufOut[0]=0; // First byte is report ID. Ignored by HID Class firmware as only config'd for one report
	au8BufOut[1]=u8Cmd;
	memcpy(au8BufIn+2,data,len);
	hidshake(au8BufOut,au8BufIn);
	
	return au8BufIn[1]==1;
}


