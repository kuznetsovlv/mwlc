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

void setIncorrectPath(void)
{
	fprintf(stderr, "Invalid path.\n");
	exit(1);
}

char *normalizePath(char *path)
{
	char *f, *b;

	for(f = path; *f != 0; ++f)
	{
		if(*f == '/' && *(f + 1) == '~' && isEnd(*(f + 2)))
		{
			setIncorrectPath();
		}
	}

	for(b = f = path; *f != 0; ++f, ++b)
	{
		*b = *f;
		while(*f == '/' && *(f + 1) == '.' && isEnd(*(f + 2))) ++f;
	}
	*b = 0;

	for(b = f = path; *f != 0; ++f, ++b)
	{
		*b = *f;
		if (*f == '/' && *(f + 1) == '.' && *(f + 2) == '.' && isEnd(*(f + 3)))
		{
			f += 2;
			while(*b == '/')
			{
				if(--b <= path) setIncorrectPath();
			}

			while(*b != '/') --b;
		}
	}
	*b = 0;

	for(b = f = path; *f != 0; ++f, ++b)
	{
		*b = *f;
		while(*f == '/' && *(f + 1) == '/') ++f;
	}
	*b = 0;

	return path;
}

char *getAbsolutePath(char *path)
{
	if(*path == '~' && isEnd(*(path + 1)))
	{
		path = concat(getHome(), path + 1);
	}
	else if(*path != '/')
	{
		path = concat(concat(getCurrentPath(), "/"), path);
	}
	return normalizePath(path);
}
