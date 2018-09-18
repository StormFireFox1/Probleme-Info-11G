#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("cladire2.in");
ofstream fout("cladire2.out");
int n, m, i, j, a[1001][1001], c, x, v[1001][1001], a1[1001], b[1001];

int main()
{
    int x1, y1;
    fin >> n >> m;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            fin >> a[i][j];
            if (i == 1 && j == 1)v[i][j] = a[i][j];
            else {
                if (v[i - 1][j] > v[i][j - 1])v[i][j] = a[i][j] + v[i - 1][j];
                else v[i][j] = a[i][j] + v[i][j - 1];
            }
        }
    }
    fout << v[n][m] << '\n';
    i = n;
    j = m;
    while (i > 0 && j > 0) {
        a1[++c] = i;
        b[c] = j;
        if (v[i - 1][j] > v[i][j - 1]) {
            i--;
        } else j--;
    }
    for (i = c; i > 0; i--) {
        fout << a1[i] << " " << b[i] << '\n';
    }


    return 0;
}