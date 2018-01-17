#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("adiacenta1.in");
ofstream fout("adiacenta1.out");

int n, m, a, b, x[101][101], mx = 0;

int main() {
    int i, j;
    while (fin >> a >> b) {
        mx = max(mx, a);
        mx = max(mx, b);
        x[a][b] = 1;
        x[b][a] = 1;
    }
    for (i = 1; i <= mx; i++) {
        for (j = 1; j <= mx; j++) {
            fout << x[i][j] << " ";
        }
        fout << '\n';
    }
    return 0;
}