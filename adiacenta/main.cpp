#include <fstream>

using namespace std;
int n, m, a, b, x[101][101];

int main() {
    ifstream fin("adiacenta.in");
    ofstream fout("adiacenta.out");

    fin >> n >> m;

    for (int k = 0; k < m; ++k) {
        fin >> a >> b;
        x[a][b] = 1;
        x[b][a] = 1;
    }

    for (int l = 1; l <= n; ++l) {
        for (int k = 1; k <= n; ++k) {
            fout << x[l][k] << " ";
        }
        fout << '\n';
    }

    return 0;
}