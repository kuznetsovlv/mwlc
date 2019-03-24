#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "version.h"

void version(void)
{
	printf("2absp version %s\n", MWLC_2ABSP_VERSION);
}

void help(void)
{
	printf("usage: 2absp [--version] [--help] [<pathes>]\n\n");

	printf("Use set of pathes or one of options:\n\n");

	printf("\t-h\t(--help)\t-\tshow help\n\n");

	printf("\t-v\t(--version)\t-\tshow version\n");
}

void unknownOption(const char *option)
{
	printf("Unknown option %s:\n", option);
	help();
}

int processOptions(int count, char **options)
{
	int i;
	for(i = 0; i < count; ++i, ++options)
	{
		if(**options != '-') continue;

		if(!strcmp(*options, "-h") || !strcmp(*options, "--help"))
		{
			help();
			return 1;
		}
		if(!strcmp(*options, "-v") || !strcmp(*options, "--version"))
		{
			version();
			return 1;
		}

		unknownOption(*options);
		exit(-3);
	}
	return 0;
}
