/** @file
    \brief Subclass of OptionsBase blass for profile-generation-specific program options.
 *
 */
#ifndef _OPTIONS_GENERATION_H_
#define _OPTIONS_GENERATION_H_

#include <string>
#include <vector>

using namespace std;

// #include "definitions.h"
#include "options_base.h"

const string  DEFAULT_OUTPUT_FILENAME = "ellipse_profile.dat";


//! Derived class for holding various options for profile-generation (set by command-line flags & options)
class GenerationOptions : public OptionsBase
{

  public:
    // Constructor:
    GenerationOptions( )
    {
      noOutputFileName = true;
      outputFileName = DEFAULT_OUTPUT_FILENAME;
    };

    // Extra data members (in addition to those in options_base.h):
    bool  noOutputFileName;
    string  outputFileName;

};


#endif  // _OPTIONS_GENERATION_H_
