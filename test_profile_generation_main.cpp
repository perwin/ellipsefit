// Code for testing ellipse-fitting: extract profile from image
//
// Currently, the goal is to extract a single profile and save it to disk

#include <stdio.h>
#include <sys/time.h>
#include <string>

using namespace std;

#include "options_base.h"
#include "options_generation.h"
#include "commandline_parser.h"
#include "utilities_pub.h"
#include "image_io.h"


#define VERSION_STRING      "0.1"


/* ------------------- Function Prototypes ----------------------------- */

void ProcessInput( int argc, char *argv[], shared_ptr<GenerationOptions> theOptions );



int main( int argc, char *argv[] )
{
  shared_ptr<GenerationOptions> options;

  // process input; get: ellipse parameters (x0, y0, a, pa, ellipticity)
  options = make_shared<GenerationOptions>();    
  ProcessInput(argc, argv, options);

  // read in image
  
  // extract profile
  
  // save profile
}



void ProcessInput( int argc, char *argv[], shared_ptr<GenerationOptions> theOptions )
{

  CLineParser *optParser = new CLineParser();
  string  tempString = "";

  /* SET THE USAGE/HELP   */
  optParser->AddUsageLine("Usage: ");
  optParser->AddUsageLine("   test_profile_generation [image_file] [options]");
  optParser->AddUsageLine(" -h  --help                   Prints this help");
  optParser->AddUsageLine(" -v  --version                Prints version number");
  optParser->AddUsageLine(" -o  --output <output-filename>        name for output profile file [default = ellipse_profile.dat]");
  optParser->AddUsageLine("     --max-threads <int>      Maximum number of threads to use [UNUSED]");
  optParser->AddUsageLine("");
#ifdef USE_LOGGING
  optParser->AddUsageLine("     --logging                Save logging outputs to file");
  optParser->AddUsageLine("");
#endif
  optParser->AddUsageLine("");
  optParser->AddUsageLine("EXAMPLES:");
  optParser->AddUsageLine("   test_profile_generation");
  optParser->AddUsageLine("   test_profile_generation data/n2775gss.fit");
  optParser->AddUsageLine("");

  optParser->AddFlag("help", "h");
  optParser->AddFlag("version", "v");
  optParser->AddOption("output", "o");
  optParser->AddOption("max-threads");
#ifdef USE_LOGGING
  optParser->AddFlag("logging");
#endif
  // Comment this out if you want unrecognized (e.g., mis-spelled) flags and options
  // to be ignored only, rather than causing program to exit
  optParser->UnrecognizedAreErrors();

  /* parse the command line:  */
  int status = optParser->ParseCommandLine( argc, argv );
  if (status < 0) {
    printf("\nError on command line... quitting...\n\n");
    delete optParser;
    exit(1);
  }


  /* Process the results: actual arguments, if any: */
  if (optParser->nArguments() > 0) {
    theOptions->imageFileName = optParser->GetArgument(0);
    theOptions->noImage = false;
  }

  /* Process the results: flags and options */
  // First two are options which print useful info and then exit the program
  if ( optParser->FlagSet("help") || optParser->CommandLineEmpty() ) {
    optParser->PrintUsage();
    delete optParser;
    exit(1);
  }
  if ( optParser->FlagSet("version") ) {
    printf("makeimage version %s\n\n", VERSION_STRING);
    delete optParser;
    exit(1);
  }
  if (optParser->OptionSet("output")) {
    theOptions->outputFileName = optParser->GetTargetString("output");
    theOptions->noOutputFileName = false;
  }
  if (optParser->OptionSet("max-threads")) {
    if (NotANumber(optParser->GetTargetString("max-threads").c_str(), 0, kPosInt)) {
      fprintf(stderr, "*** ERROR: max-threads should be a positive integer!\n\n");
      delete optParser;
      exit(1);
    }
    theOptions->maxThreads = atol(optParser->GetTargetString("max-threads").c_str());
    theOptions->maxThreadsSet = true;
  }
#ifdef USE_LOGGING
  if (optParser->FlagSet("logging")) {
    theOptions->loggingOn = true;
  }
#endif
  
  delete optParser;
}


