#include <fstream>

using namespace std;

ifstream fin("veriflant.in");
ofstream fout("veriflant.out");

int n, m, i, p, k, j, a[101][101], ok, ok2, b[101][101], mx, v[10001];

int main()
{
	int x, y;
	fin >> n >> m;
	for (i = 1; i <= m; i++)
	{
		fin >> x >> y;
		a[x][y] = 1;
		a[y][x] = 1;
	}
	fin >> k;
	for (i = 1; i <= k; i++)
	{
		fin >> p;
		ok = 1;
		ok2 = 1;
		for (j = 1; j <= n; j++)
		{
			for (int h = 1; h <= n; h++)
			{
				b[j][h] = 0;
			}
		}
		for (j = 1; j <= p; j++)
		{
			fin >> v[j];
			if (j > 1)
			{
				if (a[v[j]][v[j - 1]] == 0)
					ok = 0;
				if (b[v[j]][v[j - 1]] != 0)
					ok2 = 0;
				b[v[j]][v[j - 1]] = 1;
				b[v[j - 1]][v[j]] = 1;
			}
		}
		if (ok == 1)
		{
			if (ok2 == 1)
				fout << "ELEMENTAR" << '\n';
			else
				fout << "NEELEMENTAR" << '\n';
		} else {
			fout << "NU" << '\n';
		}
	}
	return 0;
}