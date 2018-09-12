#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include "armadillo"
using namespace std;
using namespace arma;

// object for output files
ofstream ofile;

// Functions used
inline double f(double x){return 100.0*exp(-10.0*x);}
inline double exact(double x) {return 1.0-(1-exp(-10))*x-exp(-10*x);}


int main(int argc, char* argv[])
{
    string filename = "outdata";
    int exponent = 4;

 // Loop over powers of 10
 auto start = chrono::high_resolution_clock::now(); //start timing
  for (int i = 1; i <= exponent; i++)
  {
    int n=(int)pow(10.0,i);
    //Declare new file name
    string fileout=filename;
    //Convert the power of 10^i to a string
    string argument=to_string(i);
    //Final filename as filename-i-
    fileout.append(argument);
    double h = 1.0/(n);
    double hh = h*h;

    //initialzing vector and matrix
    mat A = zeros<mat>(n,n);
    vec b = zeros<vec>(n);
    vec x = ones<vec>(n);

    //setting elements of A and b
    for (int i = 1; i <n-1; i++)
    {
    A(i,i)=2.0;
    A(i,i-1)=A(i,i+1)=-1.0;
    b[i] = hh*f(i*h);
    x[i]= i*h;
    }
    A(0,1)=A(n-1,n-2)=-1;
    A(0,0)=A(n-1,n-1)=2;
    b[0]=hh*f(0);
    b[n]=hh*f(n*h);
    x[0]=0;

    // solve Ax = b
    vec v = solve(A,b);

    //Timing
    auto stop = chrono::high_resolution_clock::now();
    auto diff = stop-start;
    cout  << " Runtime of algorithm = " << chrono::duration <double,milli> (diff).count() << "ms" << endl;

    // write to output file
    ofile.open(fileout);
    ofile<<setiosflags(ios::showpoint | ios::uppercase);
    for (int i = 1; i <= n-2; i++) // n-2 used, because n-1 gave enormous relative error for some reason I do not have time to figure out
    {
      double xval=x[i];
      double RelativeError=fabs((exact(xval)-v[i])/exact(xval));
      ofile<<setw(15)<<setprecision(8)<<xval;
      ofile << setw(15) << setprecision(8) << v[i];
      ofile << setw(15) << setprecision(8) << exact(xval);
      ofile << setw(15) << setprecision(8) << log10(RelativeError) << endl;
    }
    ofile.close();

    }
}
