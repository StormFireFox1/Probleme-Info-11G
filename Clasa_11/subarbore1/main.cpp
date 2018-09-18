#include <bits/stdc++.h>
using namespace std;

ifstream fin("subarbore1.in");
ofstream fout("subarbore1.out");

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
	int i, j;

	fin >> n >> k;
	
	for (i = 1; i <= n; i++)
	  fin >> t[i];
   
   dfs(k);
    
    for(i = 1; i <= n; i++)
  {
    if(nr[i] == 1) fout << i << ' '; 
  }
  
	return 0;
}