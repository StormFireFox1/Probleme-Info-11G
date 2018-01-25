#include <fstream>

using namespace std;

ifstream fin("lant.in");
ofstream fout("lant.out");

int n, m, i, a, b, k, j, nr, v[10001], a1[101][101];
bool b1[10001];

void afis(int nr)
{
	for (int i = 1; i <= nr; i++)
	{
		fout << v[i] << " ";
	}
	fout << '\n';
}

void bk(int p)
{
	for (int i = 1; i <= n; i++)
	{
		if (!b1[i] && a1[i][v[p - 1]] == 1 && a1[v[p - 1]][i] == 1)
		{
			b1[i] = true;
			v[p] = i;
			if (v[p] == b)
				afis(p);
			bk(p + 1);
			b1[i] = false;
		}
	}
}

int main()
{
	int x, y;
	fin >> n >> m;
	for (i = 1; i <= m; i++)
	{
		fin >> x >> y;
		a1[x][y] = 1;
		a1[y][x] = 1;
	}
	fin >> a >> b;
	v[1] = a;
	b1[a] = true;
	bk(2);
	return 0;
}