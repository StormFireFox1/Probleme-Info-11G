#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("knivel.in");
ofstream fout("knivel.out");

int n, k, x;
int t[101];

int niv(int nod)
{
	int nivel = 1;
	while (t[nod] != 0)
	{
		nivel++;
		nod = t[nod];
	}
	return nivel;
}

int main()
{
	fin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		fin >> t[i];
	}
	for (int i = 1; i <= n; i++)
		if (niv(i) == k)
			fout << i << " ";

	return 0;
}