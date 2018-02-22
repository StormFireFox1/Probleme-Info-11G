#include <fstream>

using namespace std;

ifstream fin("componenteconexe1.in");
ofstream fout("componenteconexe1.out");

int n, m, v[10001], a[101][101], nr, x, y;
int b[10001], c[10001], z[101][101];

void bfs(int k)
{
	int st = 0, dr = -1, i;
	v[++dr] = k;
	b[k] = k;
	while (st <= dr)
	{
		k = v[st++];
		for (i = 1; i <= n; i++)
		{
			if (a[k][i] == 1 && b[i] == 0)
			{
				b[i] = i;
				v[++dr] = i;
			}
		}
	}
}

int main()
{
	int i, j;
	fin >> n;
	while (fin >> x >> y)
	{
		a[x][y] = 1;
		a[y][x] = 1;
	}
	for (i = 1; i <= n; i++)
	{
		if (b[i] == 0)
		{
			bfs(i);
			int ok = 0;
			for (j = 1; j <= n; j++)
			{
				if (b[j] != 0)
					ok = 1;
			}
			if (ok == 1)
				nr++;
		}

	}
	for (i = 1; i <= n; i++)b[i] = 0;
	fout << nr - 1 << '\n';
	nr = 0;
	for (i = 1; i <= n; i++)
	{
		if (b[i] == 0)
		{
			int a = 0;
			bfs(i);
			nr++;
			for (j = 1; j <= n; j++)
			{
				if (b[j] != 0 && c[j] == 0)
				{
					c[j] = 1;
					z[nr][++a] = b[j];
				}
			}
		}

	}
	for (i = 1; i < nr; i++)
	{
		fout << z[i][1] << " " << z[i + 1][1] << '\n';
	}
	return 0;
}