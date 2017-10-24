#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("aranjamente.in");
ofstream fout("aranjamente.out");

const int N=20;
int sol[N], n, k;
bool c[N];

 void tipar()
 {
   int i;
   for(i=1; i<=k; i++)
   {
     fout<<sol[i]<<' ';
   }
   fout<<'\n';
 }

 void bkt(int p)
     {
        if(p-k>0)
            {
               tipar();
                 return;
                }
          for(int i=1; i<=n; i++)
                 {
                    if(!c[i])
                    {
                      sol[p]=i;
                      c[i]=true;
                      bkt(p+1);
                      c[i]=false;  
                       }
                    }

      }
      
int main()
{
  fin>>n>>k;
  bkt(1);
}