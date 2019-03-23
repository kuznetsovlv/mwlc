#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *concat(const char *str1, const char *str2)
{
	char *result;
	if(!(result  = malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 1))))
	{
		fprintf(stderr, "Can not allocate memory.");
	}
	strcpy(result, str1);

	return strcat(result, str2);
}
