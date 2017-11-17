/* Problema voiajului

	"Se considera un comis voiajor care trebuie sa plece din orasul 1 si sa se intoarca in orasul 1 dupa ce
	strabate f orase pe care trebuie sa le viziteze o singura data.
	Intre orice 2 orase exista un drum pentru care stim distanta.
	a[i][j] == k inseamna ca intre orasul i si orasul j sunt k kilometri. Oricare ar fi i si j de la 1 la n
	cu i != j

	Problema de Greedy euristic.

*/

#include "stdafx.h"
#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("voiaj.in");
ofstream fout("voiaj.out");

int v[100];
int a[100][100], n, k, s;

int main()
{
	fin >> n;
	int i = 0, j = 0, mini, y = 0;
	int t = 0;
	while (fin >> i >> j >> k) //citim kilometrii
	{
		a[i][j] = k;
		if (y < k)
		{
			y = k;
		}
		a[j][i] = k;
	}
	v[1] = 1;
	int poz = 0;
	fout << '1' << ' ';
	i = 1;
	while (t < n)
	{
		mini = y;
		t++;
		for (j = 1; j <= n; j++)
		{
			if (i != j && a[i][j] < mini && v[j] == 0)
			{
				mini = a[i][j];
				poz = j;
			}
		}
		v[poz] = 1;
		fout << poz << ' ';
		s += a[i][poz];
		i = poz;
	}
	s += a[1][poz];
	fout << '\n' << s;
    return 0;
}

