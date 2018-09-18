#include <fstream>

using namespace std;

ifstream fin("subgraf.in");
ofstream fout("subgraf.out");

int n, m, i, p, k, j, a[101][101], nr, s[10001];

bool prim(int n)
{
	if (n < 2)
		return false;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int x, y;
	fin >> n;
	while (fin >> x >> y)
	{
		a[x][y] = 1;
		a[y][x] = 1;
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if ((!prim(i) && !prim(j)) && a[i][j] == 1)
			{
				nr++;
			}
		}
	}
	fout << nr / 2 << '\n';
	return 0;
}