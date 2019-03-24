#include <stdio.h>
#include "mwlc_path.h"
#include "mwlc_options.h"

int main(int argc, char **argvs)
{
	if (argc < 2)
	{
		fprintf(stderr, "No argument found.\n");
		return 1;
	}

	int code = 0;

	if(!processOptions(--argc, ++argvs))
	{
		for(;argc; --argc, ++argvs)
		{
			if (isValidPath(*argvs))
			{
				printf("%s\n", getAbsolutePath(*argvs));
			}
			else
			{
				fprintf(stderr, "Invalid path name %s\n", *argvs);
				++code;
			}
		}
	}

	return code;
}
