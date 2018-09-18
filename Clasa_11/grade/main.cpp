#include <fstream>

using namespace std;

ifstream fin("grade.in");
ofstream fout("grade.out");

int n, m, v[101][101], nr, a[100001];

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
		nr = 0;
		for (int j = 1; j <= n; j++)
		{
			if (v[i][j] == 1)
				nr++;
		}
		fout << nr << " ";
	}
	return 0;
}