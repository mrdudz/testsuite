
/*
  !!DESCRIPTION!! Shift bytes left and right by a constant.
  !!ORIGIN!!      SDCC regression tests
  !!LICENCE!!     GPL, read COPYING.GPL
*/

#include <stdio.h>
#include <limits.h>

#include "testsuite.h"
#include "util/output.c"
#define OUTFILE  "rotate5.out"
#define THISFILE "rotate5"

unsigned char success=0;
unsigned char failures=0;
unsigned char dummy=0;

#ifdef SUPPORT_BIT_TYPES
bit bit0 = 0;
#endif
#ifdef SIZEOF_INT_16BIT
#if defined(__LINUX__) || defined(LINUX)
signed short aint0 = 0;
signed short aint1 = 0;

#else
signed int aint0 = 0;
signed int aint1 = 0;

#endif

#else
signed int aint0 = 0;
signed int aint1 = 0;

#endif
signed char achar0 = 0;
signed char achar1 = 0;
signed char achar2 = 0;

void done()
{

  dummy++;

}

void check(void)
{
  if(achar0 != achar1)
    failures++;
}

void shift_left_1(void)
{

  achar0 <<= 1;

  check();
}

void shift_left_2(void)
{

  achar0 <<= 2;

  if(achar0 != achar1)
    failures++;
}


void shift_left_3(void)
{

  achar0 <<= 3;

  if(achar0 != achar1)
    failures++;
}

void shift_left_4(void)
{

  achar0 <<= 4;

  if(achar0 != achar1)
    failures++;
}

void shift_left_5(void)
{

  achar0 <<= 5;

  if(achar0 != achar1)
    failures++;
}

void shift_left_6(void)
{

  achar0 <<= 6;

  if(achar0 != achar1)
    failures++;
}

void shift_left_7(void)
{

  achar0 <<= 7;

  if(achar0 != achar1)
    failures++;
}

void shift_right_1(void)
{

  achar0 >>= 1;

  check();
}

void shift_right_2(void)
{

  achar0 >>= 2;

  check();
}

void shift_right_3(void)
{

  achar0 >>= 3;

  check();
}

void shift_right_4(void)
{

  achar0 >>= 4;

  check();
}

void shift_right_5(void)
{

  achar0 >>= 5;

  check();
}

void shift_right_6(void)
{

  achar0 >>= 6;

  check();
}

void shift_right_7(void)
{

  achar0 >>= 7;

  check();
}


int main(void)
{
	opentest(OUTFILE);

  /* call with both values zero */
  shift_left_1();
  fprintf(outfile,"failures: %d\n",failures);

  achar0 = 1;
  achar1 = 2;
  for(achar2=0; achar2<6; achar2++) {
    shift_left_1();
    achar1 <<=1;
  }
  fprintf(outfile,"failures: %d\n",failures);

  achar0 = 1;
  achar1 = 4;
  shift_left_2();
  fprintf(outfile,"failures: %d\n",failures);

  achar0 = 1;
  achar1 = 8;
  shift_left_3();
  fprintf(outfile,"failures: %d\n",failures);

  achar0 = 1;
  achar1 = 0x10;
  shift_left_4();
  fprintf(outfile,"failures: %d\n",failures);

  achar0 = 1;
  achar1 = 0x20;
  shift_left_5();
  fprintf(outfile,"failures: %d\n",failures);

  achar0 = 1;
  achar1 = 0x40;
  shift_left_6();
  fprintf(outfile,"failures: %d\n",failures);

  achar0 = 1;
  achar1 = 0x80;
  shift_left_7();
  fprintf(outfile,"failures: %d\n",failures);




  achar0 = 2;
  achar1 = 1;
  shift_right_1();
  fprintf(outfile,"failures: %d\n",failures);

  achar0 = 4;
  shift_right_2();
  fprintf(outfile,"failures: %d\n",failures);

  achar0 = 8;
  shift_right_3();
  fprintf(outfile,"failures: %d\n",failures);

  achar0 = 0x10;
  shift_right_4();
  fprintf(outfile,"failures: %d\n",failures);

  achar0 = 0x20;
  shift_right_5();
  fprintf(outfile,"failures: %d\n",failures);

  achar0 = 0x40;
  shift_right_6();
  fprintf(outfile,"failures: %d\n",failures);


  achar0 = 0xff;
  achar1 = 0xff;
  shift_right_1();
  fprintf(outfile,"failures: %d\n",failures);

  achar0 = 0xfe;
  achar1 = 0xff;
  shift_right_1();
  fprintf(outfile,"failures: %d\n",failures);

  achar0 = 0xfc;
  shift_right_2();
  fprintf(outfile,"failures: %d\n",failures);

  achar0 = 0xf8;
  shift_right_3();
  fprintf(outfile,"failures: %d\n",failures);

  achar0 = 0xf0;
  shift_right_4();
  fprintf(outfile,"failures: %d\n",failures);

  achar0 = 0xe0;
  shift_right_5();
  fprintf(outfile,"failures: %d\n",failures);

  achar0 = 0xc0;
  shift_right_6();
  fprintf(outfile,"failures: %d\n",failures);

  achar0 = 0x80;
  achar1 = 0xff;
  shift_right_7();


  success=failures;
  done();
  fprintf(outfile,"failures: %d\n",failures);
	closetest(THISFILE);

    return (0);
}
