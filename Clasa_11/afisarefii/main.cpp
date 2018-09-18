#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("afisarefii.in");
ofstream fout("afisarefii.out");

int n, k, x, c;
int t[101];

int main()
{
	fin >> n;
	for (int i = 1; i <= n; i++)
	{
		fin >> t[i];
	}
	fin >> k;
	for (int i = 1; i <= k; i++)
	{
		fin >> x;
		for (int j = 1; j <= n; j++)
			if (t[j] == x)
				c++;
		fout << c << ' ';
		if (c)
			for (int j = 1; j <= n && c; j++)
				if (t[j] == x)
				{
					fout << j << ' ';
					c--;
				}
		fout << '\n';
	}
	return 0;
}