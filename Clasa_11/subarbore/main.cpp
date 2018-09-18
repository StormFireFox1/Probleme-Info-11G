#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("subarbore.in");
ofstream fout("subarbore.out");

int n, r, x, y;
int t[101], viz[101], l[101];
int a[101][101];

void dfs(int nod)
{
	x++;
	l[x] = nod;
	viz[nod] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (a[i][nod] == 1 && viz[i] == 0)
		{
			t[i] = nod;
			dfs(i);
		}
	}
}

int main()
{
	fin >> n >> r;
	for (int i = 1; i <= n; i++)
	{
		fin >> t[i];
		a[i][t[i]] = 1;
		a[t[i]][i] = 1;
	}
	a[r][t[r]] = 0;
	a[t[r]][r] = 0;
	dfs(r);
	sort(l + 1, l + x + 1);
	for (int i = 1; i <= x; i++)
		fout << l[i] << " ";
	return 0;
}