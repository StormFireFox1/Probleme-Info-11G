#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#define NMAX 100001

using namespace std;

ifstream fin("capitala.in");
ofstream fout("capitala.out");

int N;

bool vizitat[NMAX];

vector<int> v[NMAX];
queue coada;

void bfs(int nod)
{
	vizitat[nod] = true;
	coada.push(nod);
	while (!coada.empty())
	{
		int nodCurent = coada.front();
		sort(v[nodCurent].begin(), v[nodCurent].end());
		coada.pop();
		for (int i = 0; i < v[nodCurent].size(); ++i)
		{
			if (!vizitat[v[nodCurent][i]])
			{
				vizitat[v[nodCurent][i]] = true;
				coada.push(v[nodCurent][i]);
				fout << v[nodCurent][i] << " ";
			}
		}
	}
}

int main() {
    fin >> N;
    for(int i = 1; i <= N; i++) {
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    
}