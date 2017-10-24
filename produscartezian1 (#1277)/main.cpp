#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("produscartezian1.in");
ofstream fout("produscartezian1.out");

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

 void bkt(int p)
     {
        
          for(int i=1; i<=n; i++)
          {
              sol[p]=i;
            if(p==k)
            {
              tipar();
            }
            
             else  bkt(p+1);
          }
     }
      
int main()
{
  fin>>n>>k;
  bkt(1);
}