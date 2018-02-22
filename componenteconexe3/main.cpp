#include <fstream>

using namespace std;

ifstream fin("componenteconexe3.in");
ofstream fout("componenteconexe3.out");

int n, m, v[10001], a[101][101], mx, a1, p, r, nr, x, y;
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
		a[x][y] = 1;
		a[y][x] = 1;
	}
	for (i = 1; i <= n; i++)
	{
		if (b[i] == 0)
		{
			bfs(i);
			a1 = 0;
			for (j = n; j > 0; j--)
			{
				if (b[j] != 0 && c[j] == 0)
				{
					c[j] = 1;
					a1++;
					p = b[j];
				}
			}
			if (mx < a1)
			{
				mx = a1;
				r = p;

			}
		}
	}
	fout << r << " " << mx;
	return 0;
}