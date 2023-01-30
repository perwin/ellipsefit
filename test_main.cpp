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
  int  nDataVals, nStoredDataVals, startDataRow, endDataRow, nSavedRows;
  double  *xVals, *yVals, *zVals;

  if (argc < 2) {
    printf("Missing data filename!\n");
    exit(-1);
  }
  dataFileName = argv[1];
  printf("data filename = %s\n", dataFileName.c_str());
  
  /* GET THE DATA: */
  nDataVals = CountDataLines(dataFileName);
  startDataRow = 0;
  endDataRow = nDataVals - 1;
  printf("nDataVals = %d\n", nDataVals);
  if ((nDataVals < 1) || (nDataVals > MAX_N_DATA_VALS)) {
    /* file has no data *or* too much data (or an integer overflow occured 
       in CountDataLines) */
    printf("Something wrong: input file %s has too few or too many data points\n", 
           dataFileName.c_str());
    printf("(nDataVals = %d)\n", nDataVals);
    exit(1);
  }
  
  /* Allocate data vectors: */
  nStoredDataVals = endDataRow - startDataRow + 1;
  xVals = (double *)calloc( (size_t)nStoredDataVals, sizeof(double) );
  yVals = (double *)calloc( (size_t)nStoredDataVals, sizeof(double) );
  zVals = (double *)calloc( (size_t)nStoredDataVals, sizeof(double) );
  if ( (xVals == NULL) || (yVals == NULL) || (zVals == NULL)) {
    fprintf(stderr, "\nFailure to allocate memory for input data!\n");
    exit(-1);
  }
  
  /* Read in data */
  nSavedRows = ReadDataFile(dataFileName, startDataRow, endDataRow, xVals, yVals, zVals, NULL);
  if (nSavedRows > nStoredDataVals) {
    fprintf(stderr, "\nMore data rows saved (%d) than we allocated space for (%d)!\n",
            nSavedRows, nStoredDataVals);
    exit(-1);
  }
  
  printf("First five rows from data file:\n");
  for (int i = 0; i < 5; i++) {
    printf("%f\t%f\t%f\n", xVals[i], yVals[i], zVals[i]);
  }
  
  printf("\nDone.\n");
}
