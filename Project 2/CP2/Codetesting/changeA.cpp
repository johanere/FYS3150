//in: catchtester.cpp
#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;


void changemore(mat &A)
{
  cout<<"ye"<<endl;
  A(4,4)=1234;
}
