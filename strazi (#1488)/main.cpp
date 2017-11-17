/* Strazi
   Citire in float la strazi, dupaia calcule usoare. Easy. Referinta pentru citire in float.
   Folosim iomanip pentru functia setprecision() (pentru float, seteaza numarul de zecimale dupa virgula),
   si iostream pentru fixed (sa fie neaparat numarul de zecimale de la setprecision.

*/

#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

ifstream fin("strazi.in");
ofstream fout("strazi.out");

int main()
{
	int n, i, j, k, imax, d;
	float maxim = 0, x, y, r;
	fin >> n;
	fout << fixed; //fixeaza numarul de zecimale
	for (i = 1; i <= n; i++)
	{
		fin >> k;
		d = 1;
		fin >> y;
		for (j = 2; j <= k; j++)
		{
			fin >> x;
			if (x > y)
			{
				d++;
				y = x;
			}
		}
		r = (float)d / k;
		fout << setprecision(3) << r << '\n'; //seteaza la 3 digite
		if (r > maxim)
		{
			maxim = r;
			imax = i;
		}
	}
	fout << setprecision(3) << imax; //seteaza la 3 digite
    return 0;
}

