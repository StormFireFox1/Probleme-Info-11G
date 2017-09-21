#include <iostream>

using namespace std;
int x[1001];

bool divegal(int st, int dr, int element)
{   
	if(st==dr)
	{
		if(element!=x[st]) 
		{
			return false;
		}
      else{
		  return true;
	  }
	} 
	
	else{
		int m=(st+dr)/2;
	   if(divegal(st, m, element)==false || divegal(m+1, dr, element)==false) {return false;}
			else{return true;}
	}
}

int main()
{  int n, i;
   cin>>n;
   for(i=1; i<=n; i++)
   {
	   cin>>x[i];
   }
   
   if(divegal(1, n, x[1])==true){
	   cout<<"DA";
   }
   
   else if(divegal(1, n, x[1])==false){
	   cout<<"NU";
   }

return 0;
}