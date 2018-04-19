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
	int n;
	fin >> n;
	for (int i = 1; i <= n; ++i)
	{
		fin >> t[i];
	}
	int niv;
	for (int i = 1; i <= n; ++i)
	{
		niv = nivel(i);
		if (maxim < niv)
		{
			maxim = niv;
		}
	}
	fout << maxim;
	return 0;
}