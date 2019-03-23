#include <stdio.h>
#include "mwlc_path.h"

int main(int argc, char **argvs)
{
	if (argc < 2)
	{
		fprintf(stderr, "No argument found.\n");
		return 1;
	}

	int code = 0;

	int i;
	for(i = 1; i < argc; ++i)
	{
		if (isValidPath(*(argvs + i)))
		{
			printf("%s\n", getAbsolutePath(*(argvs + i)));
		}
		else
		{
			fprintf(stderr, "Invalid path name %s\n", *(argvs +i));
			++code;
		}
	}

	return code;
}
