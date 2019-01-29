#include <fstream>
#define NMAX 5001
#define GMAX 10001
#define INF 1000000000

using namespace std;

ifstream fin("energii.in");
ofstream fout("energii.out");

/** "Energii"
 * 
 *  Literalmente problema rucsac, doar că verifici minimum din vectorul de dinamică.
 *
 */

int N,                // numărul de obiecte disponibile
    G,                // greutatea maximă admisibilă ghiozdanului
    w[NMAX],          // greutatea fiecărui obiect
    p[NMAX],          // profitul fiecărui obiect
    profit[GMAX + 1]; // profitul maxim care se poate obține cu obiecte care au suma greutăților = j

int main() {
    fin >> N >> G;
    for (int i = 1; i <= N; i++) {
        fin >> w[i] >> p[i];
    }

    profit[0] = 0;

    for (int j = 1; j <= GMAX; j++) {
        profit[j] = INF;
    }
    for (int i = 1; i <= N; i++) {
        for(int j = GMAX; j >= w[i]; j--) {
            if (profit[j] > profit[j - w[i]] + p[i]) {
                profit[j] = profit[j - w[i]] + p[i];
            }
        }
    }

    int sol = INF;
    for (int i = G; i <= GMAX; i++) {
        if (sol > profit[i]) {
            sol = profit[i];
        }
    }

    if (sol == INF) {
        fout << -1;
    } else {
        fout << sol;
    }
    return 0;
}