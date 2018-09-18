#include <fstream>

using namespace std;

ifstream fin("graf_partial.in");
ofstream fout("graf_partial.out");

int n, m, v[101][101], nr;

int main()
{
	int x, y;
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
			if (v[i][j] == 1 && i % 2 == j % 2)
				v[i][j] = 0;
		}
		for (int j = 1; j <= n; j++)
		{
			if (v[i][j] == 1)
				nr++;
		}
	}
	fout << nr / 2;
	return 0;
}