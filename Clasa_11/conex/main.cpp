#include <fstream>

using namespace std;

ifstream fin("conex.in");
ofstream fout("conex.out");

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
	int x0, x, y, i;
	fin >> n;
	while (fin >> x >> y)
	{
		x0 = x;
		a[x][y] = 1;
		a[y][x] = 1;
	}
	bfs(x0);
	for (int i = 1; i <= n; i++)
	{
		if (!v[i])
		{
			fout << "NU";
			return 0;
		}
	}
	fout << "DA";
	return 0;
}
