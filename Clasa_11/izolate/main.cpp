#include <fstream>

using namespace std;

ifstream fin("izolate.in");
ofstream fout("izolate.out");

int n, m, i, p, k, j, nr, v[10001];

int main()
{
	int x, y;
	fin >> n;
	while (fin >> x >> y)
	{
		v[x]++;
		v[y]++;
	}
	for (i = 1; i <= n; i++)
	{
		if (v[i] == 0)
			nr++;
	}
	fout << nr << " ";
	for (i = 1; i <= n; i++)
	{
		if (v[i] == 0)
			fout << i << " ";
	}
	return 0;
}