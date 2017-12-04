/* permPF
   Problema clasica de backtracking. Practic este permutari dar cu o validare in plus
*/

#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("permpf.in");
ofstream fout("permpf.out");

int v[10001], f[10001], n;
bool b[10001];

void afisare()
{
	int ok = 1;
	for (int i = 1; i <= n; i++)
	{
		if (v[i] == i)
		{
			ok = 0;
		}
	}
	if (ok == 1)
	{
		for (int i = 1; i <= n; i++)
		{
			fout << v[i] << ' ';
		}
		fout << '\n';
	}
}
void backtrack(int p)
{
	if (p == n + 1)
	{
		afisare();
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (b[i] == false)
		{
			v[p] = i;
			b[i] = true;
			backtrack(p + 1);
			b[i] = false;
		}
	}
}
int main()
{
	fin >> n;
	backtrack(1);
	return 0;
}