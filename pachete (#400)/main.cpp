#include <fstream>

using namespace std;

ifstream fin("pachete.in");
ofstream fout("pachete.out");

int main()
{
	int n, v[103], i, poz, ok, j, a[200][3], k = 0;
	fin >> n;
	poz = n + 1;
	for(i = 1; i <= n; i++)
		fin >> v[i];
	for(i = 1; i <= n; i++)
	{
		if(v[i] != i)
		{
			v[poz] = v[i];
			ok = 0;
			if(i != poz)
			{
				k++;
				a[k][1] = i;
				a[k][2] = poz;
			}
			for(j = i + 1; j <= n + 1 && ok == 0; j++)
			{
				if(v[j] == i)
				{
					ok++;
					v[i] = i;
					if(i != j)
					{
						k++;
						a[k][1] = j;
						a[k][2] = i;
						poz = j;
					}
				}
			}
		}
	}
	fout << k << '\n';
	for(i = 1; i <= k; i++)
	{
		fout << a[i][1] << ' ' << a[i][2] << '\n';
	}
	return 0;
}