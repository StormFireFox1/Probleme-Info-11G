#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("subarborenumarare.in");
ofstream fout("subarborenumarare.out");

int n, r, x, y;
int t[101], viz[101];
int a[101][101];

void dfs(int nod)
{
	x++;
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
	fout << x;
	return 0;
}