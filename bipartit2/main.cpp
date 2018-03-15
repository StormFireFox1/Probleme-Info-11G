#include <fstream>

using namespace std;

ifstream fin("bipartit2.in");
ofstream fout("bipartit2.out");

int a[101][101], marc[101], bipartit = true, n, m;
bool viz[101];

void dfs(int nod, int x)
{
	int i, y;
	viz[nod] = true;
	marc[nod] = x;
	x *= -1;

	for (i = 1; i <= n && bipartit; i++)
	{
		if (a[nod][i])
		{
			if (!viz[i])
				dfs(i, x);
			else if (marc[i] != x)
				bipartit = false;
		}
	}
}

int main()
{
	int i, x, y;
	fin >> n >> m;
	for (i = 1; i <= m; i++)
	{
		fin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}
	dfs(1, 1);
	if (!bipartit)
		fout << "NU";
	else
	{
		fout << "DA" << '\n';
		for (i = 1; i <= n; i++)
			if (marc[i] == 1)
				fout << i << ' ';

		fout << '\n';

		for (i = 1; i <= n; i++)
			if (marc[i] == -1)
				fout << i << ' ';
	}
	return 0;
}