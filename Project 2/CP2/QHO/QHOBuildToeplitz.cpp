#include "QHOadd.h"

void QHOBuildToeplitz(mat &A, double Diag, double Nondiag, double rmax)
{
  int i, j ;
  // Integration step length
  int Dim=size(A,0);
  double Step = (double) rmax/ (Dim-1);
  double DiagConst = Diag / (Step*Step);
  double NondiagConst =  Nondiag / (Step*Step);

  vec R = ones<vec>(Dim); //placeholder potential
  vec V = zeros<vec>(Dim); //placeholder potential
  R(0)=0;
  R(Dim-1) = rmax;
  V(Dim-1) = rmax*rmax;
  // Setting up tridiagonal matrix and diagonalization using Armadillo
  A(0,0) = DiagConst;
  A(0,1) = NondiagConst;

  A(Dim-1,Dim-1) = DiagConst+V(Dim-1);
  A(Dim-1,Dim-2) = NondiagConst;

  for(i = 1; i < Dim-1; i++)
  {
    R(i)=i*Step;
    V(i)=R(i)*R(i);
    A(i,i-1)    = NondiagConst;
    A(i,i)    = DiagConst+V(i);
    A(i,i+1)    = NondiagConst;
  }
}
