#include "QHOadd2e.h"
#include <stdlib.h>

#include <fstream>
#include <iomanip>
#include <string>


// object for output files
ofstream ofile;

// build with QHOBuildToeplitz2e.cpp and QHOJacobirotate2e.cpp
int main(int argc,char *argv[])
{
  int Dim=stoi(argv[1]);
  double Diag=2;
  double Nondiag=-1;
  double rmax =atof(argv[2]);
  double omeg = atof(argv[3]);

  mat A = zeros<mat>(Dim,Dim); //construct matrix
  QHOBuildToeplitz(A,Diag,Nondiag,rmax,omeg); //fill matrix
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

  //write to file
  string filename;
  filename = argv[4];
  string fileout=filename;
  // write to output file
  ofile.open(fileout);
  ofile<<setiosflags(ios::showpoint | ios::uppercase);
  ofile<<setw(15)<<setprecision(8)<<Dim<<endl;
  ofile<<setw(15)<<setprecision(8)<<rmax<<endl;
  ofile<<setw(15)<<setprecision(8)<<omeg<<endl;
  for (int i = 0; i < Dim; i++)
  {
    ofile<<setw(15)<<setprecision(8)<<eigvec(i,0);
    }
  ofile.close();

  cout<<"Dim=            "<<Dim<<endl;
  cout<<"Rho=            "<<rmax<<endl;
  cout<<"Omg=            "<<omeg<<endl;
  cout<<"Grnd state eig: "<<eigval(0)<<endl;
  cout<<"File created:   "<<filename<<endl;
}
