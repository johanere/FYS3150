#include "add.h"

void Dataoutput(vec se_vec, vec eigval, int *q, double *max, int n)
{
  // write to output file
  string fileout=filename;
  ofile.open(fileout);
  ofile<<setiosflags(ios::showpoint | ios::uppercase);
  for (int i = 0; i < n; i++)
  {
    double arma= eigval[i]
    double own = se_vec[i]
    double RelativeError=fabs((exact(xval)-v[i])/exact(xval));
    ofile<<setw(15)<<setprecision(8)<<xval;
    ofile << setw(15) << setprecision(8) << v[i];
    ofile << setw(15) << setprecision(8) << exact(xval);
    ofile << setw(15) << setprecision(8) << log10(RelativeError) << endl;
  }
  ofile.close();
}
