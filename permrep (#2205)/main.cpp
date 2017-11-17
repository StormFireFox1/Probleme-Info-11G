/* permrep
   Problema clasica de backtracking. Practic este permutari dar prelucrate din caractere.
*/

#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

ifstream fin("permrep.in");
ofstream fout("permrep.out");

int v[10001], f[10001], n, mx = 0, mn = 100000;
char c[10001];

void afisare()
{
	for (int i = 0; i<n; i++)
	{
		fout << (char)v[i];
	}
	fout << '\n';
}
void backtrack(int p)
{
	if (p == n)
	{
		afisare();
		return;
	}
	for (int i = mn; i <= mx; i++)
	{
		if (f[i] != 0)
		{
			v[p] = i;
			f[i]--;
			backtrack(p + 1);
			f[i]++;
		}
	}
}
int main()
{
	fin >> c;
	n = strlen(c);
	for (int i = 0; i<n; i++)
	{
		f[c[i]]++;
		mx = max(mx, (int)c[i]);
		mn = min(mn, (int)c[i]);
	}
	backtrack(0);
	return 0;
}