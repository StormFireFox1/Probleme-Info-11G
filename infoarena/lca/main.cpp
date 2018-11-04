#include <fstream>
#include <vector>

#define LMAX 18
#define NMAX 100001

using namespace std;

ifstream fin("lca.in");
ofstream fout("lca.out");

/** LCA (Lowest Common Ancestor)
 * 
 *  O explicatie foarte buna se poate gasi chiar pe infoarena: https://infoarena.ro/problema/lca
 * 
 *  Eu personal am inteles de pe acest site: https://www.topcoder.com/community/competitive-programming/tutorials/range-minimum-query-and-lowest-common-ancestor/
 */

int n,                 // numarul de noduri in arbore
    m,                 // numarul de query-uri
    r[LMAX][2 * NMAX], // matricea pentru RMQ
    e[2 * NMAX],       // vectorul de parcurgere Euler (i.e. luand un DFS prin arbore, notam fiecare numar intr-un vector, ordinea lor e dupa parcurgerea Euler)
    ne,                // numarul de elemente din e
    nivel[NMAX],       // nivelul unui element i in arbore
    lg[2 * NMAX],      // vector de logaritm in baza 2
    poz[NMAX];         // pozitia unui element i in arbore
vector<int> fii[NMAX]; // vectorul de fii, unde fii[x] inseamna toti fii lui x

// Depth First Search, dar notam in vectorul "e" parcurgerea Euler si in vectorul "nivel" nivelul nodului.
void dfs(int x) {
    e[++ne] = x;
    poz[x] = ne;
    for (auto y : fii[x]) {
        nivel[y] = 1 + nivel[x];
        dfs(y);
        e[++ne] = x;
    }
}

int main() {
    fin >> n >> m;
    int x;

    for (int i = 2; i <= 2 * (n + 1); i++) {
        lg[i] = lg[i / 2] + 1;
    }

    for (int i = 2; i <= n; i++) {
        fin >> x;
        fii[x].push_back(i);
    }

    dfs(1);

    for(int j = 1; j <= ne; j++) {
	    r[0][j] = e[j];
    }

    for(int i = 1; i <= lg[ne]; i++)
    {
        for(int j = (1 << i); j <= ne; j++)
        {
            int st = r[i - 1][j - (1 << (i - 1))];
            int dr = r[i - 1][j];
            if(nivel[st] <= nivel[dr])
                r[i][j] = st;
            else
                r[i][j] = dr;
        }
    }

    int sol;
    for(int i = 1; i <= m; i++) {
        int st, dr;
        fin >> st >> dr;
        st = poz[st];
        dr = poz[dr];
        if (st > dr) {
            swap(st, dr);
        }
        int diff = lg[dr - st + 1];
        st = r[diff][st + (1 << diff) - 1];
        dr = r[diff][dr];
        if (nivel[st] <= nivel[dr]) {
            sol = st;
        } else {
            sol = dr;
        }
        fout << sol << "\n";
    }

    return 0;
}