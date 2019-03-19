#include <stdio.h>
#include "mwlc_path.h"

int main(int argc, char **argvs)
{
	if (argc < 2)
	{
		fprintf(stderr, "No argument found.\n");
		return 1;
	}

	int i;
	for(i = 1; i < argc; ++i) printf("%s\n", getAbsolutePath(*(argvs + i)));

	return 0;
}
