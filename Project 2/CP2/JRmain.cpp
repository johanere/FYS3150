#include "add.h"
#include <armadillo>

//timing libs
#include <chrono>
#include <ratio>
#include <ctime>

// build with BuildToeplitz.cpp and Jacobirotate.cpp
int main()
{
  int Dim=100;
  double Diag=2;
  double Nondiag=-1;
  double maxrot=5*Dim*Dim;
  cout<<Dim<<endl;
  mat A = zeros<mat>(Dim,Dim); //construct matrix
  BuildToeplitz(A,Diag,Nondiag); //fill matrix

  // run and time eigsys from armadillo
  //cout<<"Timing eigsys from armadillo with matrix dim="<<Dim<<endl;
  auto start1 = chrono::high_resolution_clock::now(); //start timing
  vec eigval;
  mat eigvec;
  eig_sym(eigval, eigvec, A);

  //Timing
  auto stop1 = chrono::high_resolution_clock::now();
  auto diff1 = stop1-start1;
  cout  << "Runtime = " << chrono::duration <double,milli> (diff1).count() << endl;

  // run and time Jacobi
  //cout<<"Timing jacobi based program with matrix dim="<<Dim<<endl;
  auto start = chrono::high_resolution_clock::now(); //start timing
  Jacobi_solve(A,maxrot); //solve with Jacobi
  //Timing
  auto stop = chrono::high_resolution_clock::now();
  auto diff = stop-start;
  cout  << "Runtime = " << chrono::duration <double,milli> (diff).count() << endl;

  //extract eigenvalues
  vec e_vec(size(A,0)); //placeholder eigenvalues from A

  for (int i = 0; i < size(A,0); ++i) //place eigenvalues in evec
  {
    e_vec(i)=A(i,i);
  }
  vec se_vec=sort(e_vec); //sorting eigenvalues

  //print select eigvalues
  int jump = Dim/5;
  int eigindex=0;
  while (eigindex< Dim) //place eigenvalues in evec
  {
    cout<<"Comparison of sorted eigenvalue nr "<<eigindex<<": Own= "<<se_vec(eigindex)<<" Eigsys="<<eigval(eigindex)<<endl;
    eigindex=eigindex+jump;
  }
}
