#include "QHOadd.h"

void offdiag(mat &A, int *p, int *q, double *max, int n)
{
  for (int i = 0; i < n; ++i) //iterating rows
  {
      for ( int j = i+1; j < n; ++j) //iterating columns
      {
          double aij = fabs(A(i,j)); //finding max offidag elem
          if ( aij > *max)
          {
            *max = aij; *p = i; *q = j; //updating maxvalue
          }
      }
  }
}

void Jacobi_rotate (mat &A, mat &R, int k, int l, int n)
{
  double s, c;
  if ( A(k,l) != 0.0 ) // check if element not equal zero
  {
      double t, tau; // t - tan of rotation angle, tau - cot 2t
      tau = (A(l,l) - A(k,k))/(2*A(k,l));  //finding cot(2xtan of angle of rotation)

      if ( tau >= 0 ) {
        t = 1.0/(tau + sqrt(1.0 + tau*tau));
      } else {  //avoiding complex
        t = -1.0/(-tau +sqrt(1.0 + tau*tau));
      }

      c = 1/sqrt(1+t*t); //finding angle
      s = c*t; // s - sine of angle, c - cosine of angle
  }
  else // in case element is zero, fix angle to zero
  {
    c = 1.0;
    s = 0.0;
  }



  double a_kk, a_ll, a_ik, a_il, r_ik, r_il;
  a_kk = A(k,k); //set old value of diagonal elements
  a_ll = A(l,l); //----
  A(k,k) = c*c*a_kk - 2.0*c*s*A(k,l) + s*s*a_ll; //assign new values to diag elements
  A(l,l) = s*s*a_kk + 2.0*c*s*A(k,l) + c*c*a_ll; //----
  A(k,l) = 0.0; // set old max non-diag elems to zero
  A(l,k) = 0.0; // ----
  for ( int i = 0; i < n; i++ )
  {
    if ( i != k && i != l )
    {
      a_ik = A(i,k);
      a_il = A(i,l);
      A(i,k) = c*a_ik - s*a_il; //updating all other non diag elems
      A(k,i) = A(i,k);
      A(i,l) = c*a_il + s*a_ik;
      A(l,i) = A(i,l);
    }
  // Updating eigenvectors
  r_ik = R(i,k);
  r_il = R(i,l);
  R(i,k) = c*r_ik - s*r_il;
  R(i,l) = c*r_il + s*r_ik;
  }
  return;
} // end of function jacobi_rotate

void Jacobi_solve (mat &A, int maxiter)
{
  double tolerance = 1.0E-10;
  int iterations = 0;
  int n = size(A,0);
  double max=2.0E-10;
  mat R= eye<mat>( size(A) );
  int p, q;
  while (max> tolerance && iterations <= maxiter)
  {
    max=0; //resetting max value
    offdiag(A, &p, &q, &max, n); //finding max and index of max
    Jacobi_rotate(A, R, p, q, n); // rotating
    iterations++;
  }
}
