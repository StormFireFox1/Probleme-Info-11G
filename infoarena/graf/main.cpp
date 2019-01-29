#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#define NMAX 7501

using namespace std;

ifstream fin("graf.in");
ofstream fout("graf.out");

/** Graf
 * 
 *  O problema de BFS, dar cu un pic de topping extra peste ea.
 *  In esenta, avem doua BFS, cu distantele marcate in distantaX si distantaY. Apoi cautam cele care s-au gasit optime in BFS-ul original.
 *  Notam caile continue prin cost in continuu[i], si apoi facem din nou o iteratie ca inainte, vedem printre care dintre ele am mai trecut.
 *  Si gata!
 */
int N, M, X, Y,      // variabile cu semnificatia din enunt
    distantaX[NMAX], // distanta de la oricare nod la X
    distantaY[NMAX], // distanta de la oricare nod la Y
    continuu[NMAX];  // vectorul in care tinem minte prin ce noduri poate parcurge calea optima

bool vizitat[NMAX];  // vector de vizitare, necesar pentru BFS

queue<int> coada;    // coada pentru BFS
vector<int> v[NMAX]; // vector cu muchiile grafului
vector<int> sol;     // nodurile cerute de problema

void clean() {
    coada.empty();
    for (int i = 1; i <= NMAX - 1; i++) {
        vizitat[i] = false;
    }
}

void bfs(int nod, int distanta[]) {
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
				distanta[v[nodCurent][i]] = distanta[nodCurent] + 1;
			}
		}
	}
}

int main() {
    fin >> N >> M >> X >> Y;
    for (int i = 1; i <= M; i++) {
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bfs(X, distantaX);
    clean();
    bfs(Y, distantaY);

    for (int i = 1; i <= N; i++) {
        if (distantaX[i] + distantaY[i] == distantaX[Y]) {
            continuu[distantaX[i]]++;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (continuu[distantaX[i]] == 1 && distantaX[i] + distantaY[i] == distantaX[Y]) {
            sol.push_back(i);
        }
    }
    fout << sol.size() << "\n";
    sort(sol.begin(), sol.end());
    
    for (auto x : sol) {
        fout << x << " ";
    }

    return 0;
}