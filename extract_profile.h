// Code for extracting surface-brightness profile along an ellipse

#ifndef _EXTRACT_PROFILE_H_
#define _EXTRACT_PROFILE_H_

#include <tuple>
#include <string>
#include <memory>


std::tuple<double *, double *, double *> GetEllipticalProfile( double *image, double x0,
			double y0, double a0, double pa0, double ell0 );


#endif  // _EXTRACT_PROFILE_H_
