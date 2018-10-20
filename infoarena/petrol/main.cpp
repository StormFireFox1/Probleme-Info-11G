#include <fstream>
#define L_MAX 501
using namespace std;

ifstream fin("petrol.in");
ofstream fout("petrol.out");

int sum[L_MAX][L_MAX];

/* "Petrol"
 *
 * Această problemă se rezolvă cu sume parțiale pe matrice.
 * 
 * O sumă parțială pe matrice se face ceva de genul acesta:
 * 
 * sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j]
 * unde sum[i][j] este egal cu suma tuturor elementelor din submatricea cu coltul stanga-sus la 0,0 si coltul dreapta-jos i,j.
 * 
 * Pentru cazul in care vrem o sumă parțială a oricărei matrici:
 * 
 * S(l1, c1, l2, c2) = sum[l2][c2] - sum[l1-1][c2] - sum[l2][c1-1] + sum[l1-1][c1-1]
 * S(i - l, j - l, i, j)
 * unde li = linia i, cj = coloana j
 * 
 * În cazul acestei probleme, complexitatea este O(q * n^2), pentru că încercăm fiecare indice din matrice pentru pătratul cu profit.
 */

int main() {
    int n, m, q, l;
    fin >> n >> m;
    int x;
    for (int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            fin >> x;
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + x;
        }
    }

    fin >> q;
    int smax, imax, jmax, s;
    smax = -2147483647 - 1;
    while (q) {
        fin >> l;
        for (int i = n; i >= l + 1; i--) {
            for(int j = m; j >= l + 1; j--) {
                /*
                 * l1 - i - l
                 * c1 - j - l
                 * l2 - i
                 * c2 - j
                 */
                s = sum[i][j] - sum[i - l + 1][j] - sum[i][j - l + 1] + sum[i - l + 1][j - l + 1];
                if (s > smax) {
                    smax = s;
                    imax = i - l;
                    jmax = j - l;
                }
            }
        }
        fout << smax << " " << imax << " " << jmax << '\n';
        q--;
    }
    return 0;
}