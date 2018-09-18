#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("flici.in");
ofstream fout("flici.out");
const int nmax=100001;

int main()
{
  long long s=0, n, x[nmax], v[nmax], i;
  fin>>n;
  for(i=0; i<n; i++)
   fin>>x[i];
  
    for(i=0; i<n; i++)
      fin>>v[i];
  
  sort(x, x+n);
  sort(v, v+n);

  for(i=0; i<n; i++)
  {
    s+=abs(x[i]-v[i]);
  }
  fout<<s;
}