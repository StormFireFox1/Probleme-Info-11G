#include <fstream>

using namespace std;

ifstream fin("graf_partial_2.in");
ofstream fout("graf_partial_2.out");

int n, m, i, p, k, j, a[101][101], mx, mx1, nr, s[10001];

int main()
{
	int x, y;
	fin >> n;
	while (fin >> x >> y)
	{
		a[x][y] = 1;
		a[y][x] = 1;
		mx = max(mx, x);
		mx = max(mx, y);
	}
	for (i = 1; i <= mx; i++)
	{
		for (j = 1; j <= mx; j++)
		{
			s[i] += a[i][j];
		}
		mx1 = max(mx1, s[i]);
	}
	for (i = 1; i <= mx; i++)
	{
		for (j = 1; j <= mx; j++)
		{
			if ((s[i] == mx1 || s[j] == mx1) && a[i][j] == 1)
			{
				a[i][j] = 0;
				nr++;
			}
		}
	}
	fout << nr / 2 << '\n';
	for (i = 1; i <= mx; i++)
	{
		for (j = 1; j <= mx; j++)
		{
			fout << a[i][j] << " ";
		}
		fout << '\n';
	}
	return 0;
}