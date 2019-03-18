#define  _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	while(argc--)
	{
		printf("%s\n", *(argv++));
	}

	printf("%s\n", get_current_dir_name());
	return 0;
}
