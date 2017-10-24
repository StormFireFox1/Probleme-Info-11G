#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
ifstream fin("sirpie.in");
ofstream fout("sirpie.out");

const int N=11;
int sol[N], n, v[N];

void tipar()
{
  int i;
  for(i=1; i<=n; i++)
  {
    fout<<sol[i]<<" ";
  }
   fout<<'\n';
}
 
 int cmmdc(int a, int b){
     
     if(b==0) {return a;}
     
     else{ return cmmdc(b,a%b);}
 }
 
 bool valid(int k)
 {

    for(int i=1; i<k; i++)
    {
       if( cmmdc(sol[i], sol[i+1])!=1 || sol[i]==sol[k] ) return false;
    }
        return true;
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
      sol[p]=v[i];
      
        if(valid(p)) bkt(p+1);
    }
  
  }
  
 int main()
 {
   fin>>n;
   for(int i=1; i<=n; i++)
      fin>>v[i];
      
    sort(v+1, v+n+1);
    bkt(1);
 }
 