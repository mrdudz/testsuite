/*
  !!DESCRIPTION!! display type limits
  !!ORIGIN!!      LCC 4.1 Testsuite
  !!LICENCE!!     own, freely distributeable for non-profit. read CPYRIGHT.LCC
*/

#include <stdio.h>
#include <limits.h>

#include "util/output.c"
#define OUTFILE  "limits.out"
#define THISFILE "limits"

#define SSHRT_MAX 	SHRT_MAX
#define SINT_MAX 	INT_MAX
#define SLONG_MAX 	LONG_MAX

#define UCHAR_MIN   0
#define USHRT_MIN   0
#define SSHRT_MIN   SHRT_MIN
#define UINT_MIN    0
#define SINT_MIN    INT_MIN
#define ULONG_MIN   0l
#define SLONG_MIN   LONG_MIN

int main(void) {

	opentest(OUTFILE);

        fprintf(outfile,"CHAR_MAX:  0x%08x=%d\n", CHAR_MAX, CHAR_MAX);
        fprintf(outfile,"UCHAR_MAX: 0x%08x=%d\n", UCHAR_MAX, UCHAR_MAX);
        fprintf(outfile,"SCHAR_MAX: 0x%08x=%d\n", SCHAR_MAX, SCHAR_MAX);

        fprintf(outfile,"SHRT_MAX:  0x%08x=%d\n", SHRT_MAX, SHRT_MAX);
        fprintf(outfile,"USHRT_MAX: 0x%08x=%d\n", USHRT_MAX, USHRT_MAX);
        fprintf(outfile,"SSHRT_MAX: 0x%08x=%d\n", SSHRT_MAX, SSHRT_MAX);

        fprintf(outfile,"INT_MAX:   0x%08x=%d\n", INT_MAX, INT_MAX);
		fprintf(outfile,"UINT_MAX:  0x%08x=%d\n", UINT_MAX, UINT_MAX);
		fprintf(outfile,"SINT_MAX:  0x%08x=%d\n", SINT_MAX, SINT_MAX);

        fprintf(outfile,"LONG_MAX:  0x%08lx=%ld\n", LONG_MAX, LONG_MAX);
		fprintf(outfile,"ULONG_MAX: 0x%08lx=%ld\n", ULONG_MAX, ULONG_MAX);
		fprintf(outfile,"SLONG_MAX: 0x%08lx=%ld\n", SLONG_MAX, SLONG_MAX);

        fprintf(outfile,"CHAR_MIN:  0x%08x=%d\n", CHAR_MIN, CHAR_MIN);
        fprintf(outfile,"UCHAR_MIN: 0x%08x=%d\n", UCHAR_MIN, UCHAR_MIN);
        fprintf(outfile,"SCHAR_MIN: 0x%08x=%d\n", SCHAR_MIN, SCHAR_MIN);

        fprintf(outfile,"SHRT_MIN:  0x%08x=%d\n", SHRT_MIN, SHRT_MIN);
        fprintf(outfile,"USHRT_MIN: 0x%08x=%d\n", USHRT_MIN, USHRT_MIN);
        fprintf(outfile,"SSHRT_MIN: 0x%08x=%d\n", SSHRT_MIN, SSHRT_MIN);

        fprintf(outfile,"INT_MIN:   0x%08x=%d\n", INT_MIN, INT_MIN);
		fprintf(outfile,"UINT_MIN:  0x%08x=%d\n", UINT_MIN, UINT_MIN);
		fprintf(outfile,"SINT_MIN:  0x%08x=%d\n", SINT_MIN, SINT_MIN);

        fprintf(outfile,"LONG_MIN:  0x%08lx=%ld\n", LONG_MIN, LONG_MIN);
		fprintf(outfile,"ULONG_MIN: 0x%08lx=%ld\n", ULONG_MIN, ULONG_MIN);
		fprintf(outfile,"SLONG_MIN: 0x%08lx=%ld\n", SLONG_MIN, SLONG_MIN);

	closetest(THISFILE);

        return (0);
}





