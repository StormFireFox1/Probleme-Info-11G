#include <iostream>
using namespace std;

int main()
{
  int n, g[1001], v[1001], i, d=1;
  float gmax, x[1001], aux, sum=0;
  cin>>n>>gmax;
  
  for(i=1; i<=n; i++)
       cin>>g[i]>>v[i],
       
       x[i]=(float) v[i]/g[i];
       
    while(d)
    {
      d=0;
      for(i=1; i<n; i++)
      {
        if(x[i]<x[i+1])
        {
          aux=x[i];
          x[i]=x[i+1];
          x[i+1]=aux;
          
          aux=g[i];
          g[i]=g[i+1];
          g[i+1]=aux;
          
          aux=v[i];
          v[i]=v[i+1];
          v[i+1]=aux;
          
          d++;
        }
      }
    }
    
    for(i=1; i<=n && gmax>0; i++)
    {
      if(gmax>=g[i])
      {
        sum+=v[i];
        gmax-=g[i];
      }
      
      else 
      {
        sum+=(float) gmax*v[i]/g[i];
        gmax=0;
      }
    }
    
    cout<<sum;
    return 0;
}