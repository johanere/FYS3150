#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include "armadillo"

//timing libs
#include <chrono>
#include <ratio>
#include <ctime>


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
    int exponent = 3;

    cout<<"Running program with n up to="<<exponent<<endl;
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
    vec a(n+1);
    vec b(n+1); // right hand side
    vec c(n+1);
    vec d(n+1);  // diagonal elements
    vec v(n+1); // v to hold solution
    vec x(n+1);
    //double *x=new double [n+1];


    for (int i = 0; i <n+1; i++)
    {
      a[i]=c[i]=-1.0;
      d[i]=2.0;
	    x[i]= i*h;
      b[i] = hh*f(i*h);
    }
    v[0]=v[n]=0.0;
    // Forward subsitution
    double *m=new double[1];
    m = new double;
    for (int i = 2; i < n; i++)
    {
      *m=a[i]/d[i-1];

      d[i] -= *m*c[i-1];
      b[i] -= *m*b[i-1];
    }
    delete m;

    // Backward subsitution
    v[n-1]=b[n-1]/d[n-1];
    for (int i = n-2; i > 0; i--)
    {
      v[i] = (b[i]-c[i-1]*v[i+1])/d[i];
    }
    //Timing
    auto stop = chrono::high_resolution_clock::now();
    auto diff = stop-start;
    cout  << " Runtime of algorithm = " << chrono::duration <double,milli> (diff).count() << "ms" << endl;

    // write to output file
    ofile.open(fileout);
    ofile<<setiosflags(ios::showpoint | ios::uppercase);
    for (int i = 1; i <= n-1; i++)
    {
      double xval=x[i];
      double RelativeError=fabs((v[i]-exact(xval))/exact(xval));
      ofile<<setw(15)<<setprecision(8)<<xval;
      ofile << setw(15) << setprecision(8) << v[i];
      ofile << setw(15) << setprecision(8) << exact(xval);
      ofile << setw(15) << setprecision(8) << log10(RelativeError) << endl;
    }
    ofile.close();
    //delete [] a; delete [] b; delete [] c; delete [] d; delete [] v;delete [] x;

  }
}
