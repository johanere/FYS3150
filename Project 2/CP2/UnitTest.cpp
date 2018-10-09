#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "UnitTester_add.h"
//compile with: Jacobirotate.cpp BuildToeplitz.cpp


TEST_CASE("Testing max a(i,j)")
{
    //test variables
    int Dim=5;
    double Diag=2;
    double Nondiag=-1;

    mat A = zeros<mat>(Dim,Dim); //construct matrix
    A(1,3)=-25;

    int p, q;
    double max=2.0E-10;
    max=0;
    offdiag(A, &p, &q, &max ,Dim);
    REQUIRE(p==1); //check first index
    REQUIRE(q==3); // check second index
    REQUIRE(max==Approx(25)); // check max == abs(-25)=25
}

TEST_CASE("Testing eigenvalues")
{
    //test variables
    int Dim=5;
    double Diag=2;
    double Nondiag=-1;

    mat A = zeros<mat>(Dim,Dim); //construct matrix
    BuildToeplitz(A,Diag,Nondiag); //fill matrix

    //finding eigenvalues with armadillo
    vec eigval;
    mat eigvec;
    eig_sym(eigval, eigvec, A);

    //function to be tested
    Jacobi_solve(A,150); //solve with Jacobi

    //extract eigenvalues
    vec eigv(size(A,0)); //placeholder eigenvalues from A

    for (int i = 0; i < size(A,0); ++i) //place eigenvalues in evec
    {
      eigv(i)=A(i,i);
    }
    vec seigv=sort(eigv); //sorting eigenvalues
    //testing
    for (int i = 0; i < size(A,0); ++i) //place eigenvalues in evec
    {
      REQUIRE(eigval(i)==Approx(seigv(i)).epsilon(0.001));
    }

}
