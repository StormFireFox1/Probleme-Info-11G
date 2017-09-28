#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("masini.in");
ofstream fout("masini.out");
int main(int argc, char const *argv[]) {
  int n, t, v[1001], i, s=0, k=0;
  fin>>n>>t;
  for(i=0; i<n; i++)
  fin>>v[i];

  sort(v, v+n);
    
  for(i=0; i<n && s<t; i++)
  {
      s+=v[i];
  }
  fout<<i-1;

  return 0;
}