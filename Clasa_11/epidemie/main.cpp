#include <fstream>

using namespace std;

ifstream fin("epidemie.in");
ofstream fout("epidemie.out");

const int N = 1001;

int n, m, mat[N][N], k, e[N], coada[N];

int viz[N];

void read()
{
	int i, x, y;
	fin >> n >> m;
	for (i = 1; i <= m; i++)
	{
		fin >> x >> y;

		mat[x][y] = 1;
		mat[y][x] = 1;
	}
	fin >> k;
	for (i = 1; i <= k; i++)
		fin >> e[i];
}

void bfs()
{
	int u = 0, p = 1, i;
	for (int i = 1; i <= k; i++)
	{
		coada[++u] = e[i];
		viz[e[i]] = 1;
	}
	while (p <= u)
	{
		int y = coada[p];
		for (i = 1; i <= n; i++)
		{
			if (mat[y][i] == 1 && viz[i] == 0)
			{
				coada[++u] = i;
				viz[i] = 1 + viz[y];
			}
		}
		p++;
	}
}

int main()
{
	int i, maxim = 0;

	read();

	bfs();
	for (i = 1; i <= n; i++)
		maxim = max(maxim, viz[i]);
	fout << maxim;

	return 0;
}