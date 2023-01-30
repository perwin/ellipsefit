// Code for timing things

#include <stdio.h>
#include <sys/time.h>
#include <string>

using namespace std;

#include "read_profile_pub.h"


#define MAX_N_DATA_VALS   1000000   /* max # data values we'll handle (1.0e6) */



int main( int argc, char *argv[] )
{
  string  dataFileName;
  int  nDataVals, nSavedRows;
  double  *xVals, *yVals, *zVals, *maskVals;

  if (argc < 2) {
    printf("Missing data filename!\n");
    exit(-1);
  }
  dataFileName = argv[1];
  printf("data filename = %s\n", dataFileName.c_str());
  
  /* GET THE DATA: */
  nDataVals = CountDataLines(dataFileName);
  if ((nDataVals < 1) || (nDataVals > MAX_N_DATA_VALS)) {
    /* file has no data *or* too much data (or an integer overflow occured 
       in CountDataLines) */
    printf("Something wrong: input file %s has too few or too many data points\n", 
           dataFileName.c_str());
    printf("(nDataVals = %d)\n", nDataVals);
    exit(1);
  }
  
  /* Allocate data vectors: */
  xVals = (double *)calloc( (size_t)nDataVals, sizeof(double) );
  yVals = (double *)calloc( (size_t)nDataVals, sizeof(double) );
  zVals = (double *)calloc( (size_t)nDataVals, sizeof(double) );
  if ( (xVals == NULL) || (yVals == NULL) || (zVals == NULL)) {
    fprintf(stderr, "\nFailure to allocate memory for input data!\n");
    exit(-1);
  }
  
  /* Read in data */
  maskVals = NULL;
  nSavedRows = ReadDataFile(dataFileName, 0, -1, xVals, yVals, zVals, maskVals);
  if (nSavedRows > nDataVals) {
    fprintf(stderr, "\nMore data rows saved (%d) than we allocated space for (%d)!\n",
            nSavedRows, nDataVals);
    exit(-1);
  }
  
}
