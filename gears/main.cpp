#include <fstream>

using namespace std;

ifstream fin("gears.in");
ofstream fout("gears.out");

int a[101][101], marc[101], n, m, v;
bool viz[101];

void dfs(int nod, int x)
{
	int i, y;
	viz[nod] = true;
	marc[nod] = x;
	x *= -1;
	for (i = 1; i <= n; i++)
	{
		if (a[nod][i] && !viz[i])
			dfs(i, x);
	}
}

int main()
{
	int i, x, y;
	fin >> n >> v;
	for (i = 1; i <= n - 1; i++)
	{
		fin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}

	dfs(v, 1);

	for (i = 1; i <= n; i++)
		if (marc[i] == 1)
			fout << "D";
		else
			fout << "S";

	return 0;

}