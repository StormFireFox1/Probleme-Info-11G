#include <fstream>

using namespace std;

ifstream fin("dfs.in");
ofstream fout("dfs.out");

int n, m, X, n1, n2;

int viz[101];
int a[101][101];

void dfs(int nod)
{
	viz[nod] = 1;
	for (int i = 1; i <= n; ++i)
	{
		if (a[nod][i] == 1 && viz[i] == 0)
		{
			fout << i << " ";
			dfs(i);
		}
	}
}

int main()
{
	fin >> n >> m >> X;
	for (int i = 1; i <= n; ++i)
	{
		fin >> n1 >> n2;
		a[n1][n2] = a[n2][n1] = 1;
	}
	viz[X] = 1;
	fout << X << " ";
	dfs(X);
	return 0;
}