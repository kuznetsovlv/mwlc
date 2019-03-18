#include <stdio.h>
#include "mwlc_path.h"
#include "mwlc_str.h"

int main(int argc, char **argv)
{
	while(argc--)
	{
		printf("%s\n", *(argv++));
	}

	printf("%s\n", getCurrentPath());

	printf("%s\n", getHome());

	printf("%s\n", concat(getCurrentPath(), getHome()));
	return 0;
}
