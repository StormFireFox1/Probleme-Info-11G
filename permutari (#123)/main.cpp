#include <iostream>
#include <fstream>
  using namespace std;
  ifstream fin("permutari.in");
  ofstream fout("permutari.out");
  const int N=20;
  int sol[N], n;
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
                      sol[p]=i;
                      c[i]=true;
                      bkt(p+1);
                      c[i]=false;  
                       }
                    }

      }
      
      int main()
      {
        fin>>n;
        bkt(1);
        return 0;
      }