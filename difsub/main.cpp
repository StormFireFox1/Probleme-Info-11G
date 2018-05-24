#include <fstream>

using namespace std;

ifstream fin("difsub.in");
ofstream fout("difsub.out");

int n, x, y, z, st[1001], dr[1001], a[1001], r[1001], rad, sumLeft, sumRight;


void SVD_left(int nod)
{
	if (nod != 0)
	{
		sumLeft += a[nod];
		SVD_left(st[nod]);
		SVD_left(dr[nod]);
	}
}

void SVD_right(int nod)
{
	if (nod != 0)
	{
		sumRight += a[nod];
		SVD_right(st[nod]);
		SVD_right(dr[nod]);
	}
}

void SVD_prime(int nod)
{
	if (nod != 0)
	{
		SVD_left(st[nod]);
		SVD_right(dr[nod]);
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
	SVD_prime(rad);
	fout << abs(sumRight - sumLeft);
	return 0;
}