#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;


int main()
{
int Dim=6;
double rmax=3;
vec R = ones<vec>(Dim);
R(2)=2;
double omeg2=0.5;
double v=R(2)*R(2)*omeg2+1.0/R(2);
cout<<v<<endl;
double faf=1.0/R(2);
cout<<faf<<endl;
}
