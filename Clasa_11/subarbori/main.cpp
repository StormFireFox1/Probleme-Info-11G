#include <bits/stdc++.h>
using namespace std;

ifstream fin("subarbori.in");
ofstream fout("subarbori.out");

int t[101], n, k, nr[101], total;

void dfs(int nod) {
	nr[nod] ++;
	
	for (int i = 1; i <= n; i++)
		if(t[i] == nod)
		{
		  dfs(i);
		  nr[nod] += nr[i];
		}
}

int main() {
	int i, j, radacina;

	fin >> n;
	
	for (i = 1; i <= n; i++)
	{
	  fin >> t[i];
	  if(t[i] == 0) radacina = i;
	}
   
   dfs(radacina);
    
    for(i = 1; i <= n; i++)
  {
      for(j = i + 1; j <= n; j++)
      {
        if(nr[i] == nr[j] && nr[i] > 1) total++;
      } 
  }
  
  fout << total;
  
	return 0;
}