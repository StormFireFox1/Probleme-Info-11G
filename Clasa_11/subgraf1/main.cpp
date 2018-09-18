#include <fstream>

using namespace std;

ifstream fin("subgraf1.in");
ofstream fout("subgraf1.out");

int n, m, i, p, k, j, a[101][101], mx, mn = 100000, nr, s[10001];

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
			s[i] += a[i][j];
		}
		mn = min(mn, s[i]);
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if ((s[i] != mn && s[j] != mn) && a[i][j] == 1)
			{
				nr++;
			}
		}
	}
	fout << nr / 2 << '\n';
	return 0;
}