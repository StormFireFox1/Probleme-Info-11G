#include <fstream>
#include <vector>

#define LMAX 17
#define NMAX 32001
#define INFINITY 10000000

using namespace std;

ifstream fin("atac.in");
ofstream fout("atac.out");

/* Atac
 *
 * O problema de LCA, dar mai complexa un pic. Nu se dau toate query-urile, ci ti se dau mai interesant un pic.
 * Query-urile urmatoarele se calculeaza folosind formula din cerinta, de exemplu.
 * 
 */

int n,                    // numarul de noduri in arbore
    m,                    // numarul de perechi pe care le vom verifica
    p,                    // numarul de perechi pe care le vom afisa (ultimele p)
    A, B, C, D,           // numerele pentru formula specificata in enunt
    bombe[LMAX][NMAX],    // costul minim de bombe
    stramosi[LMAX][NMAX], // daca avem stramosi[i][j] = stramosi al 2^i-lea al lui j
//  ------------------------ restul de variabile sunt verbatim luate de la problema LCA
    rmq[LMAX][2 * NMAX],  // vectorul pentru RMQ
    e[2 * NMAX],          // vectorul de parcurgere Euler (i.e. luand un DFS prin arbore, notam fiecare numar intr-un vector, ordinea lor e dupa parcurgerea Euler)
    ne,                   // numarul de elemente din e
    nivel[NMAX],          // nivelul unui element i in arbore
    lg[2 * NMAX],         // vector de logaritm in baza 2
    poz[NMAX];            // pozitia unui element i in arbore
vector<int> fii[NMAX + 1];    // vectorul de fii, unde fii[x] inseamna toti fii lui x

pair <int, int> query;    // cea mai usoara metoda de a retine query-ul, sincer.

// Parcurgerea Euler.
void euler(int x) {
    ne++;
    rmq[0][ne] = x;
    poz[x] = ne;
    for (auto y : fii[x]) {
        euler(y);
        ne++;
        rmq[0][ne] = x;
    }
}

// Depth-First Search
void dfs(int x) {
    for (auto y : fii[x]) {
        nivel[y] = nivel[x] + 1;
        dfs(x);
    }
}

// Calculeaza vectorul de logaritmi, stiind n. lg[i] = log in baza 2 de i
void precalculareLg() {
    for (int i = 2; i <= ne; i++) {
        lg[i] = lg[i / 2] + 1;
    }
}

// Calculeaza matricea de RMQ. Boilerplate pentru viitor.
void constructRMQ() {
    for(int i = 1; (1 << i) <= ne; i++)
    {
        for(int j = 1; j + (1 << i) <= ne + 1; j++)
        {
            int st = rmq[i - 1][j + (1 << (i - 1))];
            int dr = rmq[i - 1][j];
            if(nivel[dr] < nivel[st])
                rmq[i][j] = dr;
            else
                rmq[i][j] = st;
        }
    }
}

// calculeaza costul minim pentru a bombarda drumul dintre 2 orase si il salveaza in "bombe"
void calculareCostBombe(int n) {
   for(int i = 1; (1 << i) <= n; i++)
    for(int j = 1; j <= n; j++) {
      bombe[i][j] = min(bombe[i - 1][j], bombe[i - 1][stramosi[i - 1][j]]);
      stramosi[i][j] = stramosi[i - 1][stramosi[i - 1][j]];
    }
}

// Algoritmul pentru LCA cu RMQ precalculat. Luat boilerplate din problema LCA.
int LCA(int st, int dr) {
    int sol = 0;
    st = poz[st];
    dr = poz[dr];
    if (st > dr) {
        swap(st, dr);
    }
    int diff = lg[dr - st + 1];
    st = rmq[diff][st];
    dr = rmq[diff][dr - (1 << diff) + 1];
    if (nivel[st] < nivel[dr]) {
        sol = st;
    } else {
        sol = dr;
    }
    return sol;    
}

// pasii prin stramosi pentru a descoperi numarul minim de bombe.
int solutie(int x, int y) {
    int level = nivel[x] - nivel[y];
    int nod = x;
    int sol = INFINITY;
    for(int i = LMAX; i >= 0; i--) {
        if (level >= (1 << i)) {
            level -= 1 << i;
            sol = min(sol, bombe[i][nod]);
            nod = stramosi[i][nod];
        }
    }
    return sol;
}

// Calculeaza urmatorul query conform enuntului.
void nextQuery(int z) {
    query = make_pair((query.first * A + query.second * B) % n + 1, (query.second * C + z * D) % n + 1);
}

int main() {
    fin >> n >> m >> p;

    for (int i = 2; i <= n; i++) {
        int u, v;
        fin >> u >> v;
        fii[u].push_back(i);
        stramosi[0][i] = u;
        bombe[0][i] = v;
    }
    precalculareLg();
    nivel[1] = 1;
    dfs(1);
    euler(1);
    constructRMQ();
    calculareCostBombe(n);

    fin >> query.first >> query.second >> A >> B >> C >> D;

    for (int i = 1; i <= m; i++) {
        int lca = LCA(query.first, query.second);
        int sol = min(solutie(query.first, lca), solutie(query.second, lca));
        if (sol = INFINITY) {
            sol = 0;
        }
        if (i > m - p) {
            fout << sol << '\n';
        }
        nextQuery(sol);
    }

    return 0;
}