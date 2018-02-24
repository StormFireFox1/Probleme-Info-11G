/*
 * Implementare a algoritmului BFS folosind Standard Template Library (STL). Componentele folosite sunt sort, vector si queue.
 *
 * ACEST ALGORITM ESTE MULT MAI PERFORMANT DECAT CEL DIN MAIN.
 */

#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

ifstream fin("BFS.in");
ofstream fout("BFS.out");


vector <int> lista[101];
queue <int> coada;

int c[10001], u, p;
int n, m, x0;
bool vizitat[10001];

void bfs(int nod)
{
	vizitat[nod] = true;
	coada.push(nod);
	while (!coada.empty())
	{
		int nodCurent = coada.front();
		sort(lista[nodCurent].begin(), lista[nodCurent].end());
		coada.pop();
		for (int i = 0; i < lista[nodCurent].size(); ++i)
		{
			if (!vizitat[lista[nodCurent][i]])
			{
				vizitat[lista[nodCurent][i]] = true;
				coada.push(lista[nodCurent][i]);
				fout << lista[nodCurent][i] << " ";
			}
		}
	}
}

void citire()
{
	fin >> n >> m >> x0;
	int x, y;
	for (int i = 0; i < m; ++i)
	{
		fin >> x >> y;
		lista[x].push_back(y);
		lista[y].push_back(x);
	}
}

int main()
{
	citire();
	fout << x0 << " ";
	bfs(x0);
	return 0;
}
