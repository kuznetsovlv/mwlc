#include <stdio.h>
#include "mwlc_path.h"

int main(int argc, char **argvs)
{
	if (argc < 2)
	{
		printf("No path set.\n");
		return 1;
	}

	int i;
	for(i = 1; i < argc; ++i) printf("%s\n", getAbsolutePath(*(argvs + i)));

	return 0;
}
