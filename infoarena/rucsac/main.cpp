#include <fstream>
#define NMAX 5001
#define GMAX 10001

using namespace std;

ifstream fin("rucsac.in");
ofstream fout("rucsac.out");

/** "Rucsac"
 * 
 *  Aceasta este problema clasica a rucsacului, scrisă în programare dinamică.
 *  Se poate găsi o descriere mai detaliată pe Wikipedia: https://en.wikipedia.org/wiki/Knapsack_problem
 */

int N,            // numărul de obiecte disponibile
    G,            // greutatea maximă admisibilă ghiozdanului
    w[NMAX],      // greutatea fiecărui obiect
    p[NMAX],      // profitul fiecărui obiect
    profit[GMAX]; // profitul maxim care se poate obține cu obiecte care au suma greutăților = j

int main() {
    fin >> N >> G;
    for (int i = 0; i < N; i++) {
        fin >> w[i] >> p[i];
    }

    for (int j = 1; j <= G; j++) {
        profit[j] = -1;
    }
    for (int i = 0; i < N; i++) {
        for(int j = G - w[i]; j >= 0; j--) {
            if (profit[j] != -1 && profit[j] + p[i] > profit[j + w[i]]) {
                profit[j + w[i]] = profit[j] + p[i];
            }
        }
    }

    int sol = 0;
    for (int j = G; j >= 0; j--) {
        if (sol < profit[j]) {
            sol = profit[j];
        }
    }

    fout << sol;
    return 0;
}