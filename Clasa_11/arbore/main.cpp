#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("arbore.in");
ofstream fout("arbore.out");

int n, r, x, y;
int t[101], viz[101];
int a[101][101];

void dfs(int nod)
{
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
		fin >> x >> y;
		a[x][y] = 1;
		a[y][x] = 1;
	}
	dfs(r);
	for (int i = 1; i <= n; i++)
		fout << t[i] << " ";
	return 0;
}
