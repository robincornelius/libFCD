#ifndef __HID_H
#define __HID_H

int HIDopen();
void HIDclose();
//void hidshake(unsigned char * au8BufOut,unsigned char * au8BufIn);
int HIDQuery(int maxlen,char * data);
int HIDReadCommand(char u8Cmd, int len,char* data);
int HIDWriteCommand(char u8Cmd, int len,char* data);

#endif