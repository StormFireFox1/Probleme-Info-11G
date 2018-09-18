#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("partitiinumar2.in");
ofstream fout("partitiinumar2.out");

const int N=50;

int sol[N], sum=0, n, m;

void afisare(int k)
{
  int i;
  for(i=1; i<=k; i++)
  {
    fout<<sol[i]<<' ';
  }
  fout<<'\n';
}

bool valid(int k)
{
  sum=0;
  
  if(sol[k]<sol[k-1]) return false;

  if(sol[k]==sol[k-1]) return false;
  
  for(int i=1; i<=k; i++)
  {
    sum+=sol[i];
  }
  if(sum<=n) return true;
  return false;
  
}

void back(int k)
{
  if(sum==n && k>m)
  {
    afisare(k-1);
    return;
  }
  
  for(int i=1; i<=n-k+1; i++)
  {
    sol[k]=i;
    if (valid(k)) back(k+1);
  }
}

int main()
{
  fin>>n>>m;
  back(1);
}