#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

#define NMAX 100000

using namespace std;

ifstream fin("chei.in");
ofstream fout("chei.out");

vector<int> lista[NMAX + 1];
bool vizitat[NMAX + 1];
queue<int> coada;

int n;

void bfs(int nod)
{
	vizitat[nod] = true;
	coada.push(nod);
	sort(lista[nod].begin(), lista[nod].end());
	while (!coada.empty())
	{
		int nodCurent = coada.front();
		coada.pop();
		for (int i = 0; i < lista[nodCurent].size(); ++i)
		{
			if (!vizitat[lista[nodCurent][i]])
			{
				vizitat[lista[nodCurent][i]] = true;
				coada.push(lista[nodCurent][i]);
			}
		}
	}
}

void citire()
{
	fin >> n;
	int a;
	for (int i = 1; i <= n; ++i)
	{
		fin >> a;
		lista[a].push_back(i);
		lista[i].push_back(a);
	}
}

bool ANewGraphaHasBeenFormed()
{
	for (int i = 1; i <= n; ++i)
	{
		if(vizitat[i])
			return true;
	}
	return false;
}

int main()
{
	citire();
	int nr = 0;
	for (int i = 1; i <= n; i++)
	{
		if (vizitat[i] == 0)
		{
			bfs(i);
			if (ANewGraphaHasBeenFormed())
				nr++;
		}

	}
	fout << nr;
}