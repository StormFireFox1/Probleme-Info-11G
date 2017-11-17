#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;
ifstream fin("anagrame1.in");
ofstream fout("anagrame1.out");

char x[10];
int n, v[10], k;

void afis()
{
  int i;
  for(i=1; i<=n; i++) 
  {
    fout<<x[v[i]-1];
  }
    fout<<'\n';
}  

int valid(int k)
{
  int i;
  for(i=1; i<k; i++)
  {
      if(v[i]==v[k]) return 0;
    }
  return 1;
}

void bkt(int k)
 {
   if(k==n+1) afis();
   else {
     for(int i=1; i<=n; i++)
     {
       v[k]=i;
       if(valid(k)) bkt(k+1);
     }
   } 
  } 
  
  int main()
  {
    
    fin>>x;
    n=strlen(x);
    sort(x, x+n);
    bkt(1);
    return 0;
  }