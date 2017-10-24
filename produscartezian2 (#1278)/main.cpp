#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("produscartezian2.in");
ofstream fout("produscartezian2.out");

const int N=20;
int sol[N], n, k, v[N];

 void tipar()
 {
   int i;
   for(i=1; i<=n; i++)
   {
     fout<<sol[i]<<' ';
   }
   fout<<'\n';
 }

 void bkt(int p)
     {
         if(p-1==n)
            {
              tipar();
               return;
            }
            
          for(int i=1; i<=v[p]; i++)
          {
              sol[p]=i;
              
                bkt(p+1);
          }
     }
      
int main()
{
  fin>>n;
  int i;
     for(i=1; i<=n; i++)
        fin>>v[i];
      
  bkt(1);
}