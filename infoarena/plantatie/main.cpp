#include <fstream>

#define NMAX 501
#define LMAX 9

int rmq[LMAX][NMAX][NMAX], lg[NMAX], n, m;

using namespace std;

ifstream fin("plantatie.in");
ofstream fout("plantatie.out");

/** Plantatie
 * 
 *  Plantatie este problema RMQ, generalizata pe 2D.
 */
int main() {
    fin >> n >> m;

    for (int i = 1; i <= n; i++) {
        lg[i] = lg[i / 2] + 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fin >> rmq[0][i][j];
        }
    }

    int l, p, x, y;
	for(int k = 1; k <= lg[n]; k++) {
        l = n - (1 << k) + 1;
        p = 1 << (k - 1);
        for(int i = 1; i <= l; i++) {
            for(int j = 1; j <= l; j++) {
                x = max(rmq[k - 1][i][j], rmq[k - 1][i + p][j + p]);
                y = max(rmq[k - 1][i + p][j], rmq[k - 1][i][j + p]);
                rmq[k][i][j] = max(x, y);
            }
        }
    }

    int i, j, k;
    for (int q = 1; q <= m; q++) {
        fin >> i >> j >> p;
        k = lg[mic - 1];
        mic -= 1 << k;
        x = max(rmq[k][i][j], rmq[k][i + mic][j + mic]);
	    y = max(rmq[k][i + mic][j], rmq[k][i][j + mic]);
        fout << max(x, y) << '\n';        
    }

    return 0;
}