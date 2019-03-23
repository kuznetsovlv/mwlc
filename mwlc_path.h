#ifndef MWLC_PATH
#define MWLC_PATH

char *getCurrentPath(void);

char *getHome(void);

int isValidPath(const char*);

char *getAbsolutePath(char*);
#endif
