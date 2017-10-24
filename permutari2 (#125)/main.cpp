#include <iostream>
#include <fstream>
#include <algorithm>
  
  using namespace std;
  
ifstream fin("permutari2.in");
  ofstream fout("permutari2.out");
  const int N=20;
  int sol[N], n, v[101];
  bool c[N];

   void tipar()
   {
     for(int i=1; i<=n; i++)
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
          for(int i=1; i<=n; i++)
                 {
                    if(!c[i])
                    {
                      sol[p]=v[i];
                      c[i]=true;
                      bkt(p+1);
                      c[i]=false;  
                       }
                    }

      }
      
      int main()
      {
        fin>>n;
        for(int i=1; i<=n; i++)
          fin>>v[i];
          sort(v+1, v+n+1);
        bkt(1);
        return 0;
      }