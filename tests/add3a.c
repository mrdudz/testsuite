
/*
  !!DESCRIPTION!! Addition tests - mostly int's
  !!ORIGIN!!      SDCC regression tests
  !!LICENCE!!     GPL, read COPYING.GPL
*/

#include <stdio.h>
#include <limits.h>

#define OUTFILE  "add3a.out"
#define THISFILE "add3a"

/* always include this _after_ the above macros have been defined */
#include "testsuite.h"

/*
  this test assumes:
  sizeof(long) == 4
*/

#ifdef REFERENCE

/*
   make sure the reference output uses types with
   proper size
*/

#include <stdint.h>

int32_t long0 = 0;

#else

long long0 = 0;

#endif

int main(void)
{
    OPENTEST();

    long0 = 0x7f000000;
    /* wrap around zero */
    fprintf(outfile,"long0: %ld\n", long0);
    long0 = long0 + 0x2000000;
    //  fprintf(outfile,"long0: %ld\n", long0);
    if(long0 != -0x7f000000) {
        fprintf(outfile,"failed!\n");
    }
    fprintf(outfile,"long0: %ld\n\n", long0);

    long0 = 0x7f000000;
    /* wrap around zero */
    fprintf(outfile,"long0: %ld\n", long0);
    long0 = long0 + 0x2000000;
    fprintf(outfile,"long0: %ld\n", long0);
    if(long0 != -0x7f000000) {
        fprintf(outfile,"failed!\n");
    }
    fprintf(outfile,"long0: %ld\n", long0);

    CLOSETEST();

    return (0);
}
