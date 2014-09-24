
#ifndef __TESTSUITE_H__
#define __TESTSUITE_H__

/* get char from input */
int GETCHAR(void);

#define PRINTERROR()    printerror(__LINE__)
#define PRINTOK()       printok(__LINE__)

#define OPENTEST() opentest(OUTFILE)
#define CLOSETEST() closetest(THISFILE)

void opentest(char *name);
void closetest(char *name);

void printerror(int line);
void printok(int line);

/* fixme: use target/host specific version of following files */

#include "targetconf.h"
#include "refconfig.h"

#if defined(__LINUX__) || defined(LINUX)
#define REFCC
#endif

/*
    fixme: these should be in a library or sth
*/

#ifdef REFCC
#define LOG_ERROR(x)

#else

#ifdef TARGET_RUN6502
extern void __fastcall__  run6502_logerror(unsigned char);
#define LOG_ERROR(x) run6502_logerror(x)
#endif

#ifdef TARGET_SIM65
#define LOG_ERROR(x)
#endif

#ifdef TARGET_C64
#include "c64/dirtest.c" /* needed by output.c */
#define LOG_ERROR(x)
#endif

#endif

/* generic utility functions */
#include "output.c"
#include "getchar.c"

#endif /* __TESTSUITE_H__ */
