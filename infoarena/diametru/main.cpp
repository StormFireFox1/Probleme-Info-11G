#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#define NMAX 100001

using namespace std;

ifstream fin("diametru.in");
ofstream fout("diametru.out");

int N,              // numărul de noduri în arbore
    distanta[NMAX], // distanta de la un nod la restul, acest vector este resetat la fiecare iteratie a BFS-ului.
    nodeToFollow,   // nodul de la care vom intoarce calea cea mai lunga
    tata[NMAX];     // vector de tati, populat de catre BFS
bool vizitat[NMAX]; // statusul de vizitare al unui nod, important pentru BFS

queue<int> coada;
vector<int> v[NMAX];

void clean() {
    for (int i = 1; i <= NMAX - 1; i++) {
        distanta[i] = 0;
        vizitat[i] = false;
        tata[i] = 0;
    }
    coada.empty();
}

void bfs(int nod)
{
    distanta[nod] = 0;
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
                tata[v[nodCurent][i]] = nodCurent;
			}
		}
	}
}

int diametru(int x) {
    int nodCurent = x;
    int sol = 0;
    int k = 2;
    int next = 0;
    int maxDist = -1;

    for(int i = 1; i <= k; i++) {
        clean();
        bfs(nodCurent);
        for (int i = 1; i <= N; i++) {
            if (maxDist < distanta[i]) {
                maxDist = distanta[i];
                next = i;
            }
        }
        sol = max(sol, maxDist);
        nodCurent = next;
    }
    return sol;
    nodeToFollow = next;
}

int main() {
    fin >> N;
    int x, y;

    for (int i = 1; i <= N; i++) {
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    fout << diametru(1) << "\n";

    while (tata[nodeToFollow] != 0) {
        fout << nodeToFollow << " ";
        nodeToFollow = tata[nodeToFollow];
    }
    fout << nodeToFollow;
    
    return 0;
}