#define _GNU_SOURCE
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
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

char *normalizePath(char *path)
{
	return path;
}

char *getAbsolutePath(char *path)
{
	if (*path == '/')
		return normalizePath(path);

	if(*path == '~' && *(path + 1) == '/')
		return normalizePath(concat(getHome(), path + 1));

	return normalizePath(concat(concat(getCurrentPath(), "/"), path));
}
