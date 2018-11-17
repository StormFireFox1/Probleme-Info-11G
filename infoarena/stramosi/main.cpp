#include <fstream>

#define NMAX 390625
#define LMAX 20

using namespace std;
	
ifstream fin("stramosi.in");	
ofstream fout("stramosi.out");

int stramosi[LMAX][NMAX + 10]; // matricea de stramosi, unde stramosi[i][j] = al 2^i-lea stramos al lui j

int main() {	
    int n, m;
    fin >> n >> m;
	
    for (int i = 1; i <= n; ++i) {
        fin >> stramosi[0][i]; // citeste stramosii
	
    }
	
    for (int i = 1; (1 << i) <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            stramosi[i][j] = stramosi[i - 1][stramosi[i - 1][j]]; // construieste matricea
        }
    }
	
    while (m) {
        int q, p;
        fin >> q >> p;
        int poz = 17;
        while (poz >= 0 && p != 0) {
            if (p >= (1 << poz)) {
                q = stramosi[poz][q];
                p -= (1 << poz);
            }
            poz--;
        }
        fout << q << '\n';
        m--;
    }
    return 0;
}