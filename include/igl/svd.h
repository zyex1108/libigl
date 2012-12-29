#ifndef IGL_SVD_H
#define IGL_SVD_H
namespace igl
{
  // Compute 3x3 SVD using lapack's dgesdd_ function
  //
  // Input:
  //   a  pointer to 3x3 matrix in COLUMN MAJOR order
  // Outputs:
  //   u  pointer to 3x3 matrix in COLUMN MAJOR order
  //   s  pointer to 3 vector 
  //   vt  pointer to 3x3 matrix in COLUMN MAJOR order, or think of this as v in
  //     row-major order
  // Returns true on success, false on failure
  bool svd3x3(double * a, double * u, double * s, double * vt);
};

#ifdef IGL_HEADER_ONLY
#include "svd.cpp"
#endif

#endif