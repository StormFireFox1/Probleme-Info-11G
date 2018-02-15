#include <fstream>

using namespace std;

ifstream fin("BFS.in");
ofstream fout("BFS.out");

int c[10001], u, p, n, m, a[101][101];
bool v[10001];

void bfs(int nod)
{
	v[nod] = true;
	u = 1;
	p = 1;
	c[1] = nod;
	while (p <= u)
	{
		for (int i = 1; i <= n; i++)
		{
			if (a[nod][i] == 1 && !v[i])
			{
				u++;
				c[u] = i;
				v[i] = true;
			}
		}
		p++;
		nod = c[p];
	}
}

int main()
{
	int x0, x, y, i, j;
	fin >> n >> m >> x0;
	for (i = 1; i <= m; i++)
	{
		fin >> x >> y;
		a[x][y] = 1;
		a[y][x] = 1;
	}
	bfs(x0);
	for (i = 1; i <= u; i++)
	{
		fout << c[i] << " ";
	}
	return 0;
}
