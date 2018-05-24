#include <fstream>

using namespace std;

ifstream fin("postordine.in");
ofstream fout("postordine.out");

int n, x, y, z, st[1001], dr[1001], a[1001], r[1001], rad;

void SDV(int nod)
{
	if (nod != 0)
	{
		SDV(st[nod]);
		SDV(dr[nod]);
		fout << a[nod] << ' ';
	}
}

int main()
{
	fin >> n;
	for (int i = 1; i <= n; i++)
	{
		fin >> x >> y >> z;
		a[i] = x;
		st[i] = y;
		dr[i] = z;
		r[y] = 1;
		r[z] = 1;
	}
	for (int i = 1; i <= n; i++)
		if (r[i] == 0)
			rad = i;
	SDV(rad);

	return 0;
}