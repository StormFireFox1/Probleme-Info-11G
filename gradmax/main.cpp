#include <fstream>

using namespace std;

ifstream fin("gradmax.in");
ofstream fout("gradmax.out");

int n, m, v[101][101], mx, mn = 1000000, s, sum[10001], sum2[10001], nr, x, y;

int main()
{
	int x, y, j;
	fin >> n;
	while (fin >> x >> y)
	{
		v[x][y] = 1;
		v[y][x] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		s = 0;
		for (j = 1; j <= n; j++)
		{
			s += v[i][j];
		}
		mx = max(mx, s);
	}
	for (int i = 1; i <= n; i++)
	{
		s = 0;
		for (j = 1; j <= n; j++)
		{
			s += v[i][j];
		}
		if (mx == s)
			nr++;
	}
	fout << nr << ' ';
	for (int i = 1; i <= n; i++)
	{
		s = 0;
		for (j = 1; j <= n; j++)
		{
			s += v[i][j];
		}
		if (mx == s)
			fout << i << " ";
	}
	return 0;
}