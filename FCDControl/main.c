#include <stdio.h>
#include <stdlib.h>

#include <argtable2.h>

#include "FCDlib.h"

int main(int argc,char ** argv)
{

 	/* Define the allowable command line options, collecting them in argtable[] */
    	struct arg_lit *help  = arg_lit0(NULL,"help",       "print this help and exit");
    	struct arg_lit *defaults  = arg_lit0("d","defaults",       "Write defaults to FCD");
	struct arg_int *frequency  = arg_int0("f","frequency",NULL,              "Set FCD frquency (50000-3000000)");
	struct arg_int *version  = arg_lit0("v","version",              "Get FCD version");
    	struct arg_end *end   = arg_end(20);
    	void* argtable[] = {help,version,frequency,defaults,end};
    	const char* progname = "FCDControl";
    	int exitcode=0;
    	int nerrors;

	/* verify the argtable[] entries were allocated sucessfully */
    	if (arg_nullcheck(argtable) != 0)
        {
        	/* NULL entries were detected, some allocations must have failed */
        	printf("%s: insufficient memory\n",progname);
        	//exit(-1);
        }

	/* Parse the command line as defined by argtable[] */
    	nerrors = arg_parse(argc,argv,argtable);

	/* special case: '--help' takes precedence over error reporting */
    	if (help->count > 0)
        {
        	printf("Usage: %s", progname);
        	arg_print_syntax(stdout,argtable,"\n");
		arg_print_glossary(stdout,argtable,"  %-25s %s\n");
		exit(0);
        }

 	/* If the parser returned any errors then display them and exit */
    	if (nerrors > 0)
        {
        	/* Display the error details contained in the arg_end struct.*/
        	arg_print_errors(stdout,end,progname);
        	printf("Try '%s --help' for more information.\n",progname);
        	exit(-1);
        }

	if(FCD_init()<0)
	{
		printf("Funcube pro dongle not found!\n");
		exit(-2);
	}

	if(version->count>0)
	{
		char * version = FCD_getversion();
		printf("%s\n",version);		
	}

	if(defaults->count == 1)
	{
		printf("Setting default settings on FCD\n");
		FCD_set_defaults();
	}

	if(frequency->count == 1)
	{
		printf("Setting FCD frequency to %d\n",frequency->ival[0]);
		FCD_set_frequency(frequency->ival[0]);
	}

	FCD_close();

	



}
