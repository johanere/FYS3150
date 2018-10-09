#include "add.h"

void BuildToeplitz(mat &A, double Diag, double Nondiag)
{
  int i, j ;
  double rmin = 0;
  double rmax = 1;
  // Integration step length
  double rdomain= rmax - rmin;
  int Dim=size(A,0);
  double Step = (double) rdomain/ Dim;
  double DiagConst = Diag / (Step*Step);
  double NondiagConst =  Nondiag / (Step*Step);

  // Setting up tridiagonal matrix and diagonalization using Armadillo
    A(0,0) = DiagConst;
    A(0,1) = NondiagConst;

    A(Dim-1,Dim-1) = DiagConst;
    A(Dim-1,Dim-2) = NondiagConst;

    for(i = 1; i < Dim-1; i++)
    {
      A(i,i-1)    = NondiagConst;
      A(i,i)    = DiagConst;
      A(i,i+1)    = NondiagConst;
    }
}
