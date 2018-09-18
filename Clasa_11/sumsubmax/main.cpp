#include <bits/stdc++.h>
using namespace std;

ifstream fin("sumsubmax.in");
ofstream fout("sumsubmax.out");

int t[105], n, k, nr[105], val[105];

void dfs(int nod) {
	nr[nod] += val[nod];

	for (int i = 1; i <= n; i++)
		if(t[i] == nod)
		{
		  dfs(i);
		  nr[nod] += nr[i];
		}
}

int main() {
	int i, j, maxim = -999999999, rad;

	fin >> n;

	for (i = 1; i <= n; i++)
	{
	  fin >> t[i];
	  if(t[i] == 0) rad = i;
	}

	for(i = 1; i <= n; i++)
      fin >> val[i];

	 dfs(rad);

	for(i = 1; i <= n; i++)
	  maxim = max(maxim, nr[i]);

    for(i = 1; i <= n; i++)
        if(nr[i] == maxim) fout << i << ' ';


	return 0;
}
