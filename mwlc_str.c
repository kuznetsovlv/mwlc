#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *concat(unsigned num, ...)
{
	if (num == 0)
		return NULL;

	char **strs = malloc(sizeof(char*) * num);
	if (!strs)
	{
		fprintf(stderr, "Can not allocate memory.");
		exit(-2);
	}

	unsigned length = 1;
	unsigned i;

	va_list args;
	va_start(args,num);
	for(i = 0; i < num; ++i)
	{
		*(strs + i) = va_arg(args, char*);
		length += strlen(*(strs + i));
	}

	char *result = malloc(sizeof(char) * length);
	if(!result)
	{
		fprintf(stderr, "Can not allocate memory.");
		free(strs);
		exit(-2);
	}

	strcpy(result, *strs);

	for(i = 1; i < num; ++i)
		strcat(result, *(strs + i));

	free(strs);
	return result;
}
