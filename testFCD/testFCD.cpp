// testFCD.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include "../FCDlib/FCDlib.h"
int _tmain(int argc, _TCHAR* argv[])
{
	FCD_init();
	FCD_close();
	FCD_set_defaults();
	FCD_set_frequency(100000);
	Sleep(20000);
	return 0;
}

