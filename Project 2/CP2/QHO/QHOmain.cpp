#include "QHOadd.h"
#include <stdlib.h>

// build with QHOBuildToeplitz.cpp and QHOJacobirotate.cpp
int main(int argc,char *argv[])
{
  int Dim=stoi(argv[1]);
  double Diag=2;
  double Nondiag=-1;
  double rmax =atof(argv[2]);

  mat A = zeros<mat>(Dim,Dim); //construct matrix
  QHOBuildToeplitz(A,Diag,Nondiag,rmax); //fill matrix
  //A.print("A after construction= ");
  vec eigval;
  mat eigvec;
  eig_sym(eigval, eigvec, A);

  //Jacobi_solve(A,5*Dim*Dim); //solve with Jacobi

  //extract eigenvalues
  vec evec(Dim); //placeholder eigenvalues from A

  for (int i = 0; i < Dim; ++i) //place eigenvalues in evec
  {
    evec(i)=A(i,i);
  }
  vec sevec=sort(evec); //sorting eigenvalues


  cout<<"Dim= "<<Dim<<endl;
  cout<<"Rho= "<<rmax<<endl;
  for (int i = 0; i < 6; ++i) //place eigenvalues in evec
  {
    cout<<eigval(i)<<endl;
  }


}
