#include <fstream>

using namespace std;

ifstream fin("lanturi1.in");
ofstream fout("lanturi1.out");

int a[21][21], st[200], n, m, p, q, r, k, x, y;

int ok(int k)
{
	for (int i = 1; i < k; i++)
		if (st[i] == st[k])
			return 0;
	return 1;
}

void DFS(int nod, int k)
{
	if (nod == q)
	{
		for (int i = 1; i < k; i++)
			fout << st[i] << ' ';
		fout << endl;
	} else
	{
		for (int i = 1; i <= n; i++)
			if (a[nod][i] == 1)
			{
				st[k] = i;
				if (ok(k) == 1)
					DFS(i, k + 1);
			}
	}
}

int main()
{
	fin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		fin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}

	fin >> p >> q >> r;
	for (int j = 1; j <= n; j++)
		a[r][j] = a[j][r] = 0;

	st[1] = p;
	DFS(p, 2);
}