#include <iostream>
#include <fstream>

using namespace std;

ifstream f("sumtri1.in");
ofstream g("sumtri1.out");

int a[101][101], b[101][101], mini, v[101];

int main() {
    int i, j, n, cn;
    f >> n;
    cn = n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= i; j++)
            f >> a[i][j];
    for (i = 1; i <= n; i++)
        b[n][i] = a[n][i];
    for (i = n - 1; i > 0; i--)
        for (j = 1; j <= i; j++) {
            b[i][j] = a[i][j] + min(b[i + 1][j], b[i + 1][j + 1]);
        }
    g << b[1][1] << endl << a[1][1];
    j = 1;
    for (i = 2; i <= n; i++) {
        if (b[i][j] > b[i][j + 1])
            j++;
        g << " " << a[i][j];
    }
    return 0;
}