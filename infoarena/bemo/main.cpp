#include <fstream>

#define R_MAX 1501
#define C_MAX 1501

/* "Bemo"
 *
 * Vom lua matricea, iterăm de la 1 la R*C-1 și verificăm dacă nu este "marchat".
 * "Marchat" înseamnă că nu putem ajunge la număr prin călătorie.
 * 
 * Luăm toate numerele și le găsim în matrice, "marcând" tot de
 * mai sus și din dreapta și de mai jos și din stânga, pentru că nu putem ajunge
 * la ele. Iterăm tot așa până avem doar câteva numere nemarcate. Nu remarcăm un
 * număr găsit.
 * 
 * Când ajungem așa, iterăm de sus de la matrice până jos, verificam marcarea și
 * dăm afară în ordinea de călătorie cum trebuie.
 * 
 */

using namespace std;

ifstream fin("bemo.in");
ofstream fout("bemo.out");

int v[R_MAX][C_MAX], r[R_MAX * C_MAX], c[R_MAX * C_MAX];
bool mark[R_MAX * C_MAX];

int main() {
    int R, C, i, j, x;
    fin >> R >> C;
    for (i = 1; i <= R; i++) {
        for (j = 1; j <= C; j++) {
            fin >> v[i][j];
            r[v[i][j]] = i;
            c[v[i][j]] = j;
        }
    }

    // iterăm peste fiecare element în ordine lexicografică (mic la mare)
    for (x = 1; x <= R * C; x++) {
        if (!mark[x]) { // este marcat? Dacă nu...
            // marcăm toate de la dreapta sus
            for (i = r[x] - 1; i >= 1; i--) {
                j = c[x] + 1;
                while (j <= C && !mark[v[i][j]]) {
                    mark[v[i][j]] = true;
                    j++;
                }
            }

            // marcăm toate de la stânga jos
            for (i = r[x] + 1; i <= R; i++) {
                j = c[x] - 1;
                while (j >= 1 && !mark[v[i][j]]) {
                    mark[v[i][j]] = true;
                    j--;
                }
            }
        }
    }

    i = 1;
    j = 1;

    // dăm elementele nemarcate pe afară
    while (i <= R && j <= C) {
        if (!mark[v[i][j]]) {
            fout << v[i][j] << " ";
        }
        if (!mark[v[i + 1][j]]) {
            i++;
        }
        if (!mark[v[i][j + 1]]) {
            j++;
        }
    }
    return 0;
}