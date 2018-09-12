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
    int exponent = 7;

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

    //initialzing vectors and assigning values to known entities
    vec b(n+1); // right hand side
    vec d(n+1); // diagonal elements
    vec v(n+1); // v to hold solution
    vec x(n+1); // Grid

    for (int i = 0; i <n+1; i++)
    {
	    x[i]= i*h;
      b[i] = hh*f(i*h);
    }

    v[0]=v[n]=0.0;
    d[0]=d[n]=2;
    // Forward subsitution
    for (int i = 2; i < n; i++)
    {
      d[i]=float (i+1)/i;
      b[i] += float ((i-1)*b[i-1])/i;
    }

    // Backward subsitution
    v[n-1]=b[n-1]/d[n-1];
    for (int i = n-2; i > 0; i--)
    {
      v[i] =float (b[i]+v[i+1])*i/(i+1);
    }
    //Timing
    auto stop = chrono::high_resolution_clock::now();
    auto diff = stop-start;
    cout  << " Runtime of algorithm = " << chrono::duration <double,milli> (diff).count() << "ms" << endl;
/*
    // write to output file
    ofile.open(fileout);
    ofile<<setiosflags(ios::showpoint | ios::uppercase);
    for (int i = 1; i <= n-1; i++)
    {
      double xval=x[i];
      double RelativeError=fabs((exact(xval)-v[i])/exact(xval));
      ofile<<setw(15)<<setprecision(8)<<xval;
      ofile << setw(15) << setprecision(8) << v[i];
      ofile << setw(15) << setprecision(8) << exact(xval);
      ofile << setw(15) << setprecision(8) << log10(RelativeError) << endl;
    }
    ofile.close();
    */
    }
}
