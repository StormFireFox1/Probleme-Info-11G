#include <bits/stdc++.h>
using namespace std;

ifstream fin("subarbore2.in");
ofstream fout("subarbore2.out");

int t[101], n, k, nr[101], val[101], suma;

void dfs(int nod) {
	nr[nod] ++;

	suma += val[nod];

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

     for(i = 1; i <= n; i++)
      fin >> val[i];

      dfs(k);

    fout << suma;

	return 0;
}
