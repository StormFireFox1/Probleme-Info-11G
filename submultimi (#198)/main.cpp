#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("submultimi.in");
ofstream fout("submultimi.out");

const int N=11;

int sol[N], n;

void afisare(int k)
{
  int i;
  for(i=1; i<=k; i++)
  {
    fout<<sol[i]<<' ';
  }
  fout<<'\n';
}

void back(int k)
{
  if(k-1==n) return;
  
  for(int i=1; i<=n; i++)
  {
    
    if(i>sol[k-1])
    {
       sol[k]=i;
       afisare(k);
       back(k+1);
    }
  }
}

int main()
{
  fin>>n;
  back(1);
}