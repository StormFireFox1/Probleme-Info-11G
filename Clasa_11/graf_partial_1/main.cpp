#include <fstream>

using namespace std;

ifstream fin("graf_partial_1.in");
ofstream fout("graf_partial_1.out");

long long n, m, v[101][101], mx, mn = 1000000, s, s2, sum[10001], nr;

int main()
{
	int x, y, i;
	fin >> n;
	while (fin >> x >> y)
	{
		v[x][y] = 1;
		v[y][x] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			sum[i] += v[i][j];
		}
	}
	for (i = 1; i <= n; i++)
	{
		mx = max(mx, sum[i]);
		mn = min(mn, sum[i]);
	}
	for (i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (v[i][j] && ((sum[i] == mx && sum[j] == mn) || (sum[i] == mn && sum[j] == mx)))
			{
				nr++;
				v[i][j] = v[j][i] = 0;
			}
		}
	}

	fout << nr << '\n';
	for (i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			fout << v[i][j] << " ";
		}
		fout << '\n';
	}
	return 0;
}