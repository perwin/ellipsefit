/** @file
    \brief Base class for program options; meant to be subclassed
 *
 *  Fundamentally, this is a list of parameter values and settings. For ease
 *  of access, all data members are public. (The only reason we don't use a C-style
 *  struct is so we can use the constructor to set default values automatically,
 *  and so we can have derived classes with the same base set of parameters.)
 *
 *  In addition to serving as a base class for expanded, program-specific option
 *  listing, this interface is meant for use by SetupModelImage(), so that any
 *  instance of a derived class can be used by that function.
 */
#ifndef _OPTIONS_BASE_H_
#define _OPTIONS_BASE_H_

#include <string>
#include <vector>

using namespace std;

#include "definitions.h"


//! base class for holding various imfit options (set by command-line flags & options)
class OptionsBase
{

  public:
    // Constructor:
    OptionsBase( )
    {
      noImage = true;
      imageFileName = "";
  
      maxThreads = 0;
      maxThreadsSet = false;

      verbose = 1;
      debugLevel = 0;

      loggingOn = false;
    };

    // Data members:
    bool  noImage;
    string  imageFileName;
  
    int  maxThreads;
    bool  maxThreadsSet;
  
    int  debugLevel;
    int  verbose;

    bool  loggingOn;
};


#endif  // _OPTIONS_BASE_H_
