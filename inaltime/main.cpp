#include <fstream>

using namespace std;

ifstream fin("inaltime.in");
ofstream fout("inaltime.out");

int t[101], maxim = 0;

int nivel(int nod)
{
	int niv = 1;
	while(t[nod] != 0)
	{
		niv++;
		nod = t[nod];
	}
	return niv;
}

int main()
{
	int n, x, k;
	fin >> n;
	for (int i = 1; i <= n; ++i)
	{
		fin >> x;
		t[i] = x;
	}
	fin >> k;
	for (int i = 1; i <= k; ++i) {
		fin >> x;
		maxim = max(nivel(x), maxim);
	}
	fout << maxim;
	return 0;
}