#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("subsecv.in");
ofstream fout("subsecv.out");

int main()
{
  int n, v[10001], s, i, j;
  fin>>n;
  
  for(i=1; i<=n; i++)
      fin>>v[i];
      
  for(i=1; i<=n; i++)
  {
    s=v[i];
    if(s%n==0)
    {
      fout<<i<<" "<<i;
      return 0;
    }
    
    for(j=i+1; j<n; j++)
    {
      s+=v[j]%n;
      if(s%n==0)
      {
        fout<<i<<" "<<j;
        return 0;
      }
    }
  }

  return 0;
}