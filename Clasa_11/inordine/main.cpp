#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("inordine.in");
ofstream fout("inordine.out");

int n, x, y, z, st[1001], dr[1001], a[1001], r[1001], rad;

void SVD(int nod)
{
	if (nod != 0)
	{
		SVD(st[nod]);
		fout << a[nod] << ' ';
		SVD(dr[nod]);
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
	SVD(rad);

	return 0;
}