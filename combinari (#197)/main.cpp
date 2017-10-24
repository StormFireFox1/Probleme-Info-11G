#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("combinari.in");
ofstream fout("combinari.out");

const int N=20;
int sol[N], n, k;

 void tipar()
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
   int i;
   for(i=1; i<=k; i++)
    {
      if(sol[k]>sol[k-1]) return true;
    }
    return false;
 }

 void bkt(int p)
     {
        if(p-k==1)
            {
               tipar();
                 return;
                }
          for(int i=1; i<=n; i++)
          {
            sol[p]=i;
            if(valid(p)) bkt(p+1);
          }
     }
      
int main()
{
  fin>>n>>k;
  bkt(1);
}