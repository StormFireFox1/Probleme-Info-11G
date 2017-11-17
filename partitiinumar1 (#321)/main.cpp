#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("partitiinumar1.in");
ofstream fout("partitiinumar1.out");

const int N=50;

int n, sol[N], sum;

void afisare(int k)
{
  int i;
  for(i=1; i<=k; i++)
  {
    fout<<sol[i]<<' ';
  }
  fout<<'\n';
}

bool valid (int p)
{
   sum=0;
   int i;
   
  if(sol[p]<sol[p-1]) return false;
  
  if(sol[p]==sol[p-1]) return false;
  
  for(i=1; i<=p; i++)
  {
    sum+=sol[i];
  }
  if(sum<=n) return true;
  
  return false;
}

void back(int p)
{
  int i; 
  
  if(sum==n)
  {
    afisare(p-1);
    return;
  }
  
  for(i=1; i<=n-p+1; i++)
  {
    sol[p]=i;
    if(valid(p)) back(p+1);
  }
}

int main()
{
  fin>>n;
  back(1);
}

