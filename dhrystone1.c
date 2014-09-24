
/* dhrystone - benchmark program */

#define REGISTER
/*
 *
 * "DHRYSTONE" Benchmark Program
 *
 * Version: C/1.1, 12/01/84
 *
 * Date:    PROGRAM updated 01/06/86, COMMENTS changed 01/31/87
 *
 * Author:     Reinhold P. Weicker,  CACM Vol 27, No 10, 10/84 pg.1013
 *       Translated from ADA by Rick Richardson
 *       Every method to preserve ADA-likeness has been used,
 *       at the expense of C-ness.
 *
 * Compile: cc -O dry.c -o drynr       : No registers
 *       cc -O -DREG=register dry.c -o dryr  : Registers
 *
 * Defines: Defines are provided for old C compiler's
 *       which don't have enums, and can't assign structures.
 *       The time(2) function is library dependant; Most
 *       return the time in seconds, but beware of some, like
 *       Aztec C, which return other units.
 *       The LOOPS define is initially set for 50000 loops.
 *       If you have a machine with large integers and is
 *       very fast, please change this number to 500000 to
 *       get better accuracy.  Please select the way to
 *       measure the execution time using the TIME define.
 *       For single user machines, time(2) is adequate. For
 *       multi-user machines where you cannot get single-user
 *       access, use the times(2) function.  Be careful to
 *       adjust the HZ parameter below for the units which
 *       are returned by your times(2) function.  You can
 *       sometimes find this in <sys/param.h>.  If you have
 *       neither time(2) nor times(2), use a stopwatch in
 *       the dead of the night.
 *       Use a "printf" at the point marked "start timer"
 *       to begin your timings. DO NOT use the UNIX "time(1)"
 *       command, as this will measure the total time to
 *       run this program, which will (erroneously) include
 *       the time to malloc(3) storage and to compute the
 *       time it takes to do nothing.
 *
 * Run:     drynr; dryr
 *
 * Results: If you get any new machine/OS results, please send to:
 *
 *          ihnp4!castor!pcrat!rick
 *
 *       and thanks to all that do.
 *
 * Note:    I order the list in increasing performance of the
 *       "with registers" benchmark.  If the compiler doesn't
 *       provide register variables, then the benchmark
 *       is the same for both REG and NOREG.
 *
 * PLEASE:     Send complete information about the machine type,
 *       clock speed, OS and C manufacturer/version.  If
 *       the machine is modified, tell me what was done.
 *       On UNIX, execute uname -a and cc -V to get this info.
 *
 * 80x8x NOTE: 80x8x benchers: please try to do all memory models
 *       for a particular compiler.
 *
 *
 * The following program contains statements of a high-level programming
 * language (C) in a distribution considered representative:
 *
 * assignments       53%
 * control statements      32%
 * procedure, function calls  15%
 *
 * 100 statements are dynamically executed.  The program is balanced with
 * respect to the three aspects:
 *    - statement type
 *    - operand type (for simple data types)
 *    - operand access
 *       operand global, local, parameter, or constant.
 *
 * The combination of these three aspects is balanced only approximately.
 *
 * The program does not compute anything meaningfull, but it is
 * syntactically and semantically correct.
 *
 */


/* Accuracy of timings and human fatigue controlled by next two lines */

/* Use this for slow or 16 bit machines */
#define LOOPS   500
/* Use this for slow or 16 bit machines */
//#define LOOPS   5000
/* Use this for slow or 16 bit machines */
//#define LOOPS   50000

/* Use this for faster machines */
//#define LOOPS  500000      


/* Compiler dependent options */

/* Define if compiler has no enum's */
//#define  NOENUM
/* Define if compiler can't assign structures */
//#define  NOSTRUCTASSIGN

/* Define only one of the next four defines */

/* Use getrusage(2) time function */
//#define GETRUSAGE
/* Use times(2) time function */
//#define TIMES
/* Use time(2) time function */
//#define TIME
/* use clock() */
#define CLOCK

/* Define the granularity of your times(2) function (when used) */
#define HZ   50			/* times(2) returns 1/50 second (europe?) */

/* times(2) returns 1/60 second (most) */
//#define HZ  60
 /* times(2) returns 1/100 second (WECo) */
//#define HZ   100


/* For compatibility with goofed up version */

/* Define if you want the goofed up version */
#undef GOOF


#ifdef GOOF
char Version[] = "1.0";
#else
char Version[] = "1.1";
#endif


#ifdef   NOSTRUCTASSIGN
#define  structassign(d, s)   memcpy(&(d), &(s), sizeof(d))
#else
#define  structassign(d, s)   d = s
#endif


#ifdef   NOENUM
#define  Ident1   1
#define  Ident2   2
#define  Ident3   3
#define  Ident4   4
#define  Ident5   5
typedef int Enumeration;
#else
typedef enum
{
  Ident1, Ident2, Ident3, Ident4, Ident5
} Enumeration;

#endif


typedef int OneToThirty;
typedef int OneToFifty;
typedef char CapitalLetter;
typedef char String30[31];
typedef int Array1Dim[51];
typedef int Array2Dim[51][51];


struct Record
{
  struct Record *PtrComp;
  Enumeration Discr;
  Enumeration EnumComp;
  OneToFifty IntComp;
  String30 StringComp;
};


typedef struct Record RecordType;
typedef RecordType *RecordPtr;
typedef int boolean;


#define  NULL     0
#define  TRUE     1
#define  FALSE    0


#ifndef REG
#define  REG
#endif

#if 1
int Proc0 (void);
int Proc1 (REG RecordPtr PtrParIn);
int Proc2 (OneToFifty * IntParIO);
int Proc3 (RecordPtr * PtrParOut);
int Proc4 (void);
int Proc5 (void);
int Proc6 (REG Enumeration EnumParIn, REG Enumeration * EnumParOut);
void Proc7 (OneToFifty IntParI1, OneToFifty IntParI2, OneToFifty * IntParOut);
int Proc8 (Array1Dim Array1Par, Array2Dim Array2Par, OneToFifty IntParI1,
	   OneToFifty IntParI2);

Enumeration Func1 (CapitalLetter CharPar1, CapitalLetter CharPar2);
boolean Func2 (String30 StrParI1, String30 StrParI2);
int Func3 (REG Enumeration EnumParIn);
#else
extern Enumeration Func1 ();
extern boolean Func2 ();
#endif

#ifdef TIMES
#include <sys/param.h>
#include <sys/types.h>
#include <sys/times.h>
#endif


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef CLOCK
#include <time.h>
#endif

#ifdef TIME
#include <time.h>
#endif

main ()
{
  Proc0 ();
  exit (0);
}


/* Package 1  */
int IntGlob;
boolean BoolGlob;
char Char1Glob;
char Char2Glob;
Array1Dim Array1Glob;
Array2Dim Array2Glob;
RecordPtr PtrGlb;
RecordPtr PtrGlbNext;



Proc0 ()
{
  OneToFifty IntLoc1;
  REG OneToFifty IntLoc2;
  OneToFifty IntLoc3;
  REG char CharLoc;
  REG char CharIndex;
  Enumeration EnumLoc;
  String30 String1Loc;
  String30 String2Loc;
#if 0
  extern char *malloc ();
#endif
  register unsigned int i;

#ifdef CLOCK
//  long time();
  clock_t starttime;
  clock_t stoptime;
  clock_t benchtime;
  clock_t nulltime;


  starttime = clock ();
  for (i = 0; i < LOOPS; ++i)
    {
      // wait
//        printf("%d\n",(int)clock());
    }
  nulltime = clock () - starttime;	/* Computes o'head of loop */
#endif

#ifdef TIME
#if 0
  long time ();
#endif
  time_t starttime;
  time_t benchtime;
  time_t nulltime;


  starttime = time ((time_t *) 0);
  for (i = 0; i < LOOPS; ++i)
    {
      // wait
    }
  nulltime = time ((time_t *) 0) - starttime;	/* Computes o'head of loop */
#endif

#ifdef TIMES
  time_t starttime;
  time_t benchtime;
  time_t nulltime;
  struct tms tms;


  times (&tms);
  starttime = tms.tms_utime;
  for (i = 0; i < LOOPS; ++i);
  times (&tms);
  nulltime = tms.tms_utime - starttime;	/* Computes overhead of looping */
#endif

#ifdef GETRUSAGE
  struct rusage starttime;
  struct rusage endtime;
  struct timeval nulltime;

  getrusage (RUSAGE_SELF, &starttime);
  for (i = 0; i < LOOPS; ++i);
  getrusage (RUSAGE_SELF, &endtime);
  nulltime.tv_sec = endtime.ru_utime.tv_sec - starttime.ru_utime.tv_sec;
  nulltime.tv_usec = endtime.ru_utime.tv_usec - starttime.ru_utime.tv_usec;
#endif

  printf ("Dhrystone starttime: %d\n", (int) starttime);
  printf ("Dhrystone nulltime: %d\n", (int) nulltime);

  PtrGlbNext = (RecordPtr) malloc (sizeof (RecordType));
  PtrGlb = (RecordPtr) malloc (sizeof (RecordType));
  PtrGlb->PtrComp = PtrGlbNext;
  PtrGlb->Discr = Ident1;
  PtrGlb->EnumComp = Ident3;
  PtrGlb->IntComp = 40;
  strcpy (PtrGlb->StringComp, "DHRYSTONE PROGRAM, SOME STRING");
#ifndef  GOOF
  strcpy (String1Loc, "DHRYSTONE PROGRAM, 1'ST STRING");	/* GOOF */
#endif

  Array2Glob[8][7] = 10;	/* Was missing in published program */


/*****************
-- Start Timer --
*****************/
#ifdef CLOCK
  starttime = clock ();
#endif

#ifdef TIME
  starttime = time ((time_t *) 0);
#endif

#ifdef TIMES
  times (&tms);
  starttime = tms.tms_utime;
#endif
#ifdef GETRUSAGE
  getrusage (RUSAGE_SELF, &starttime);
#endif

  printf ("Dhrystone starttime %d\n", (int) starttime);

  for (i = 0; i < LOOPS; ++i)
    {

      Proc5 ();
      Proc4 ();
      IntLoc1 = 2;
      IntLoc2 = 3;
      strcpy (String2Loc, "DHRYSTONE PROGRAM, 2'ND STRING");
      EnumLoc = Ident2;
      BoolGlob = !Func2 (String1Loc, String2Loc);
      while (IntLoc1 < IntLoc2)
	{
	  IntLoc3 = 5 * IntLoc1 - IntLoc2;
	  Proc7 (IntLoc1, IntLoc2, &IntLoc3);
	  ++IntLoc1;
	}
      Proc8 (Array1Glob, Array2Glob, IntLoc1, IntLoc3);
      Proc1 (PtrGlb);
      for (CharIndex = 'A'; CharIndex <= Char2Glob; ++CharIndex)
	if (EnumLoc == Func1 (CharIndex, 'C'))
	  Proc6 (Ident1, &EnumLoc);
      IntLoc3 = IntLoc2 * IntLoc1;
      IntLoc2 = IntLoc3 / IntLoc1;
      IntLoc2 = 7 * (IntLoc3 - IntLoc2) - IntLoc1;
      Proc2 (&IntLoc1);
    }


/*****************
-- Stop Timer --
*****************/
#ifdef CLOCK
  stoptime = clock ();
  printf ("Dhrystone stoptime: %d\n", (int) stoptime);

  benchtime = stoptime - starttime - nulltime;
  printf ("Dhrystone benchtime: %d\n", (int) benchtime);
//  benchtime=benchtime/CLOCKS_PER_SEC;
//  printf("Dhrystone benchtime: %d\n",(int)benchtime);

  printf ("Dhrystone(%s) ", Version);
  printf ("time for %ld ", (long) LOOPS);
  printf ("passes = %d\n", (int) (benchtime / CLOCKS_PER_SEC));

//    benchtime=709;

//  benchtime=benchtime/CLOCKS_PER_SEC;


//  printf("Dhrystone benchtime: %d\n",(int)benchtime);

  printf ("Dhrystone(%s) time for %ld passes = %d\n",
	  Version, (long) LOOPS, (int) (benchtime / CLOCKS_PER_SEC));
  printf ("This machine benchmarks at %ld dhrystones/second\n",
	  ((long) LOOPS) * CLOCKS_PER_SEC / benchtime);
#endif

#ifdef TIME
  benchtime = time ((time_t *) 0) - starttime - nulltime;
  printf ("Dhrystone(%s) time for %ld passes = %ld\n",
	  Version, (long) LOOPS, benchtime);
  printf ("This machine benchmarks at %ld dhrystones/second\n",
	  ((long) LOOPS) / benchtime);
#endif

#ifdef TIMES
  times (&tms);
  benchtime = tms.tms_utime - starttime - nulltime;
  printf ("Dhrystone(%s) time for %ld passes = %ld\n",
	  Version, (long) LOOPS, benchtime / HZ);
  printf ("This machine benchmarks at %ld dhrystones/second\n",
	  ((long) LOOPS) * HZ / benchtime);
#endif
#ifdef GETRUSAGE
  getrusage (RUSAGE_SELF, &endtime);
  {
    double t = (double) (endtime.ru_utime.tv_sec
			 - starttime.ru_utime.tv_sec
			 - nulltime.tv_sec)
      + (double) (endtime.ru_utime.tv_usec
		  - starttime.ru_utime.tv_usec - nulltime.tv_usec) * 1e-6;
    printf ("Dhrystone(%s) time for %ld passes = %.1f\n",
	    Version, (long) LOOPS, t);
    printf ("This machine benchmarks at %.0f dhrystones/second\n",
	    (double) LOOPS / t);
  }
#endif

}


Proc1 (PtrParIn)
     REG RecordPtr PtrParIn;
{
#define  NextRecord  (*(PtrParIn->PtrComp))

  structassign (NextRecord, *PtrGlb);
  PtrParIn->IntComp = 5;
  NextRecord.IntComp = PtrParIn->IntComp;
  NextRecord.PtrComp = PtrParIn->PtrComp;
// BUG? why does this not compile with cc65?
//  Proc3(NextRecord.PtrComp);
  Proc3 ((RecordPtr *) NextRecord.PtrComp);
  if (NextRecord.Discr == Ident1)
    {
      NextRecord.IntComp = 6;
      Proc6 (PtrParIn->EnumComp, &NextRecord.EnumComp);
      NextRecord.PtrComp = PtrGlb->PtrComp;
      Proc7 (NextRecord.IntComp, 10, &NextRecord.IntComp);
    }
  else
    structassign (*PtrParIn, NextRecord);


#undef   NextRecord
}


Proc2 (IntParIO)
     OneToFifty *IntParIO;
{
  REG OneToFifty IntLoc;
  REG Enumeration EnumLoc;


  IntLoc = *IntParIO + 10;
  for (;;)
    {
      if (Char1Glob == 'A')
	{
	  --IntLoc;
	  *IntParIO = IntLoc - IntGlob;
	  EnumLoc = Ident1;
	}
      if (EnumLoc == Ident1)
	break;
    }
}


Proc3 (PtrParOut)
     RecordPtr *PtrParOut;
{
  if (PtrGlb != NULL)
    *PtrParOut = PtrGlb->PtrComp;
  else
    IntGlob = 100;
  Proc7 (10, IntGlob, &PtrGlb->IntComp);
}


Proc4 ()
{
  REG boolean BoolLoc;


  BoolLoc = Char1Glob == 'A';
  BoolLoc |= BoolGlob;
  Char2Glob = 'B';
}


Proc5 ()
{
  Char1Glob = 'A';
  BoolGlob = FALSE;
}


extern boolean Func3 ();


Proc6 (EnumParIn, EnumParOut)
     REG Enumeration EnumParIn;
     REG Enumeration *EnumParOut;
{
  *EnumParOut = EnumParIn;
  if (!Func3 (EnumParIn))
    *EnumParOut = Ident4;
  switch (EnumParIn)
    {
    case Ident1:
      *EnumParOut = Ident1;
      break;
    case Ident2:
      if (IntGlob > 100)
	*EnumParOut = Ident1;
      else
	*EnumParOut = Ident4;
      break;
    case Ident3:
      *EnumParOut = Ident2;
      break;
    case Ident4:
      break;
    case Ident5:
      *EnumParOut = Ident3;
    }
}

#ifdef NO_OLD_FUNC_DECL
void
Proc7 (OneToFifty IntParI1, OneToFifty IntParI2, OneToFifty * IntParOut)
#else
Proc7 (IntParI1, IntParI2, IntParOut)
     OneToFifty IntParI1;
     OneToFifty IntParI2;
     OneToFifty *IntParOut;
#endif
{
  REG OneToFifty IntLoc;


  IntLoc = IntParI1 + 2;
  *IntParOut = IntParI2 + IntLoc;
}

#ifdef NO_OLD_FUNC_DECL
Proc8 (Array1Dim Array1Par, Array2Dim Array2Par, OneToFifty IntParI1,
       OneToFifty IntParI2)
#else
Proc8 (Array1Par, Array2Par, IntParI1, IntParI2)
     Array1Dim Array1Par;
     Array2Dim Array2Par;
     OneToFifty IntParI1;
     OneToFifty IntParI2;
#endif
{
  REG OneToFifty IntLoc;
  REG OneToFifty IntIndex;


  IntLoc = IntParI1 + 5;
  Array1Par[IntLoc] = IntParI2;
  Array1Par[IntLoc + 1] = Array1Par[IntLoc];
  Array1Par[IntLoc + 30] = IntLoc;
  for (IntIndex = IntLoc; IntIndex <= (IntLoc + 1); ++IntIndex)
    Array2Par[IntLoc][IntIndex] = IntLoc;
  ++Array2Par[IntLoc][IntLoc - 1];
  Array2Par[IntLoc + 20][IntLoc] = Array1Par[IntLoc];
  IntGlob = 5;
}

#ifdef NO_OLD_FUNC_DECL
Enumeration
Func1 (CapitalLetter CharPar1, CapitalLetter CharPar2)
#else
Enumeration
Func1 (CharPar1, CharPar2)
     CapitalLetter CharPar1;
     CapitalLetter CharPar2;
#endif
{
  REG CapitalLetter CharLoc1;
  REG CapitalLetter CharLoc2;


  CharLoc1 = CharPar1;
  CharLoc2 = CharLoc1;
  if (CharLoc2 != CharPar2)
    return (Ident1);
  else
    return (Ident2);
}

#ifdef NO_OLD_FUNC_DECL
boolean
Func2 (String30 StrParI1, String30 StrParI2)
#else
boolean
Func2 (StrParI1, StrParI2)
     String30 StrParI1;
     String30 StrParI2;
#endif
{
  REG OneToThirty IntLoc;
  REG CapitalLetter CharLoc;


  IntLoc = 1;
  while (IntLoc <= 1)
    if (Func1 (StrParI1[IntLoc], StrParI2[IntLoc + 1]) == Ident1)
      {
	CharLoc = 'A';
	++IntLoc;
      }
  if (CharLoc >= 'W' && CharLoc <= 'Z')
    IntLoc = 7;
  if (CharLoc == 'X')
    return (TRUE);
  else
    {
      if (strcmp (StrParI1, StrParI2) > 0)
	{
	  IntLoc += 7;
	  return (TRUE);
	}
      else
	return (FALSE);
    }
}

#ifdef NO_OLD_FUNC_DECL
boolean
Func3 (REG Enumeration EnumParIn)
#else
boolean
Func3 (EnumParIn)
     REG Enumeration EnumParIn;
#endif
{
  REG Enumeration EnumLoc;


  EnumLoc = EnumParIn;
  if (EnumLoc == Ident3)
    return (TRUE);
  return (FALSE);
}


#ifdef   NOSTRUCTASSIGN
memcpy (d, s, l)
     register char *d;
     register char *s;
     register int l;
{
  while (l--)
    *d++ = *s++;
}
#endif

/* -----------------------------------------------------------------------------------------
THE END
*/
