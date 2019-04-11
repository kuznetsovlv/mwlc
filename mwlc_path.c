#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <string.h>
#include "mwlc_str.h"

char *getCurrentPath()
{
	return get_current_dir_name();
}

char *getHome()
{
	char *home = getenv("HOME");
	return home ? home : getpwuid(getuid())->pw_dir;
}

int isEnd(char c) {
	return c == '/' || !c;
}

int isValidPath(const char *path)
{
	int length = strlen(path);
	int i;

	for (i = 0; i < length; ++i)
	{
		switch (*(path + i))
		{
			case '/': continue;
			case '~': if(!isEnd(*(path + (++i)))) break;
			case '-': return 0;
		}
		while(!isEnd(*(path + (++i))));
	}
	return 1;
}

int normalizePath(char *path)
{
	char *f, *b;

	// "./" keys
	for(b = f = path; *f; ++f, ++b)
	{
		*b = *f;
		while(*f == '/' && *(f + 1) == '.' && isEnd(*(f + 2))) ++f;
	}
	*b = 0;

	// "../" key
	for(b = f = path; *f; ++f, ++b)
	{
		*b = *f;
		if (*f == '/' && *(f + 1) == '.' && *(f + 2) == '.' && isEnd(*(f + 3)))
		{
			f += 2;
			while(*b == '/')
			{
				if(--b <= path) return 0; // Out of root dirrectory
			}

			while(*b != '/') --b;
		}
	}
	*b = 0;

	// Remove dublicated "/"
	for(b = f = path; *f; ++f, ++b)
	{
		*b = *f;
		while(*f == '/' && *(f + 1) == '/') ++f;
	}
	*b = 0;

	return 1;
}

char *getAbsolutePath(const char *path)
{
	char *result;

	if(*path == '~' && isEnd(*(path + 1)))
	{
		result = concat(2, getHome(), path + 1);
	}
	else if(*path != '/')
	{
		result = concat(3, getCurrentPath(), "/", path);
	}

	if (!normalizePath(result))
	{
		fprintf(stderr, "The resulting path of %s is out of root dirrectory.\n", path);
		exit(-1);
	}
	return result;
}
