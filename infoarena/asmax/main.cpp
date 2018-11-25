#include <fstream>
#include <vector>
#define INFINITY 1000000000
#define NMAX 16000

using namespace std;

ifstream fin("asmax.in");
ofstream fout("asmax.out");

int n,                        // numarul de noduri
    sol = -INFINITY,          // suma maxima finala, trebuie numar mic pentru maxim
    val[NMAX + 1],            // valorile fiecarui nod. valoare[x] = valoarea nodului x
    suma[NMAX + 1],           // suma[x] = suma pentru DFS din nod x
    vizitat[NMAX + 1];        // vectorul de vizitare.
vector<int> vecini[NMAX + 1]; // vectorul de vecini. vecini[x] = vecinii nodului x

void dfs(int nod) {
    vizitat[nod] = 1;
    for (auto vecin : vecini[nod]) {
        if (!vizitat[vecin]) {
            dfs(vecin);
            suma[nod] += max(suma[vecin], 0);
        }
    }
    suma[nod] += val[nod];
}

int main() {
    int x, y;
    fin >> n;
    for (int i = 1; i <= n; i++) {
        fin >> val[i];
    }
    for (int i = 1; i <= n - 1; i++) {
        fin >> x >> y;
        vecini[x].push_back(y);
        vecini[y].push_back(x);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        sol = max(sol, suma[i]);
    }
    fout << sol;
    return 0;
}