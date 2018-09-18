#include <fstream>

using namespace std;

ifstream fin("listavecini.in");
ofstream fout("listavecini.out");

int a[102][102], n;

void citireMatrice()
{
	int i, j;
	fin >> n;
	while (fin >> i >> j)
	{
		a[i][j] = 1;
		a[j][i] = 1;
	}
}

int nrVecini(int k)
{
	int s = 0;
	for (int i = 1; i <= n; ++i)
	{
		s += a[k][i];
	}
	return s;
}

int main()
{
	citireMatrice();
	for (int i = 1; i <= n; ++i)
	{
		fout << nrVecini(i) << " ";
		for (int j = 1; j <= n; ++j)
		{
			if (a[i][j] == 1)
			{
				fout << j << " ";
			}
		}
		fout << endl;
	}
	return 0;
}