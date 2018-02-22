#include <fstream>

using namespace std;

ifstream fin("componenteconexe2.in");
ofstream fout("componenteconexe2.out");

int n, m, v[10001], a[101][101], a1, nr, x, y;
int b[10001], c[10001], z[1001][101];

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
		if (a[x][y] == 0)m++;
		a[x][y] = 1;
		a[y][x] = 1;
	}
	for (i = 1; i <= n; i++)
	{
		if (b[i] == 0)
		{
			bfs(i);
			for (j = 1; j <= n; j++)
			{
				if (b[j] != 0 && c[j] == 0)
				{
					c[j] = 1;
					a1++;
				}
			}
			a1--;
		}
	}
	fout << m - a1;
	return 0;
}