//header guard
#ifndef QHO_ADD_H
#define QHO_ADD_H

#include <iostream>
#include <armadillo>
using namespace std;
using namespace arma;
//declarations
void QHOBuildToeplitz(mat &A, double Diag, double Nondiag, double rmax);
void Jacobi_solve (mat &A, int maxiter);
void Jacobi_rotate ( mat &A, mat &R, int k, int l, int n );
void offdiag(mat &A, int *p, int *q, double *max, int n);

//end of header guard
#endif
