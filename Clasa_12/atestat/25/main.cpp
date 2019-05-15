#include <iostream>

using namespace std;

struct fractie {
    int a,b;
};
 
void S1( fractie x, fractie &y) {
   y.a=x.a*y.b+x.b*y.a;
   y.b=x.b*y.b;
}

int S2 (int x,int y) {
     int r;
     while (y!=0) {
        r=x%y;
        x=y;
        y=r;
     
 }
 return x;
 }
  

int main()
{
 int n,t;
 fractie fr;
 fractie s;
 cin>>n;
 s.a=0;
 s.b=1;
 for (int i=1;i<=n;i++) {
     cin>>fr.a>>fr.b;
     S1(fr,s);
     
 }
  while (S2(s.a,s.b)!=1) {
      t=S2(s.a,s.b);
      s.a=s.a/t;
      s.b=s.b/t;
      
  }
  
  cout<<s.a<<"/"<<s.b;
  
  return 0;
}
