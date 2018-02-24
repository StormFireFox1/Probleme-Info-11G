/*
 * Implementare a algoritmului DFS folosind Standard Template Library (STL). Componentele folosite sunt sort si vector.
 *
 * ACEST ALGORITM ESTE MULT MAI PERFORMANT DECAT CEL DIN MAIN.
 */

#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("dfs.in");
ofstream fout("dfs.out");

vector <int> lista[101];
bool vizitat[101];
int n, x;

void dfs(int nod)
{
	vizitat[nod] = true;
	sort(lista[nod].begin(), lista[nod].end());
	for (int i = 0; i < lista[nod].size(); ++i)
	{
		if (!vizitat[lista[nod][i]])
		{
			fout << lista[nod][i] << " ";
			dfs(lista[nod][i]);
		}
	}
}

void citire()
{
	int m, a, b;
	fin >> n >> m >> x;
	for (int i = 1; i <= m; ++i)
	{
		fin >> a >> b;
		lista[a].push_back(b);
		lista[b].push_back(a);
	}
	fout << x << " ";
}

int main()
{
	citire();
	dfs(x);
	return 0;
}
