// This file is part of libigl, a simple c++ geometry processing library.
// 
// Copyright (C) 2013 Alec Jacobson <alecjacobson@gmail.com>
// 
// This Source Code Form is subject to the terms of the Mozilla Public License 
// v. 2.0. If a copy of the MPL was not distributed with this file, You can 
// obtain one at http://mozilla.org/MPL/2.0/.
#include "full.h"

template <typename T,typename DerivedB>
IGL_INLINE void igl::full(
  const Eigen::SparseMatrix<T> & A,
  Eigen::PlainObjectBase<DerivedB>& B)
{
  assert(false && "Obsolete. Just call B = Matrix(A)");
  using namespace Eigen;
  B = PlainObjectBase<DerivedB >::Zero(A.rows(),A.cols());
  // Iterate over outside
  for(int k=0; k<A.outerSize(); ++k)
  {
    // Iterate over inside
    for(typename SparseMatrix<T>::InnerIterator it (A,k); it; ++it)
    {
      B(it.row(),it.col()) = it.value();
    }
  }
}

template <typename DerivedA,typename DerivedB>
IGL_INLINE void igl::full(
  const Eigen::PlainObjectBase<DerivedA>& A,
  Eigen::PlainObjectBase<DerivedB>& B)
{
  assert(false && "Obsolete. Just call B = Matrix(A)");
  B = A;
}

#ifdef IGL_STATIC_LIBRARY
// Explicit template specialization
// generated by autoexplicit.sh
template void igl::full<Eigen::Matrix<double, -1, -1, 0, -1, -1>, Eigen::Matrix<double, -1, -1, 0, -1, -1> >(Eigen::PlainObjectBase<Eigen::Matrix<double, -1, -1, 0, -1, -1> > const&, Eigen::PlainObjectBase<Eigen::Matrix<double, -1, -1, 0, -1, -1> >&);
// generated by autoexplicit.sh
template void igl::full<double, Eigen::Matrix<double, -1, -1, 0, -1, -1> >(Eigen::SparseMatrix<double, 0, int> const&, Eigen::PlainObjectBase<Eigen::Matrix<double, -1, -1, 0, -1, -1> >&);
#endif
