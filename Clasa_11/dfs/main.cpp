#include <fstream>

using namespace std;

ifstream fin("dfs.in");
ofstream fout("dfs.out");

int a[101][101];
int viz[101];
int n;

void dfs(int nod)
{
	viz[nod] = 1;
	for (int j = 1; j <= n; j++)
		if (a[nod][j] == 1 && viz[j] == 0)
		{
			fout << j << " ";
			dfs(j);
		}
}

int main()
{
	int m, x, i, c, b;
	fin >> n >> m >> x;
	for (i = 1; i <= m; i++)
	{
		fin >> b >> c;
		a[c][b] = 1;
		a[b][c] = 1;
	}
	fout << x << " ";
	dfs(x);
	return 0;
}
