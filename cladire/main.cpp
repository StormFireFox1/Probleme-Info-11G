#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("cladire.in");
ofstream fout("cladire.out");
int n, m, i, j, a[1001][1001], c, x;

int main()
{
    int x1, y1;
    fin >> n >> m;
    fin >> x;
    for (int h = 1; h <= x; h++) {
        fin >> x1 >> y1;
        a[x1][y1] = -1;
    }
    a[n][m] = 1;
    for (i = n; i > 0; i--) {
        for (j = m; j > 0; j--) {
            if (a[i][j] != -1) {
                if (j < m && a[i][j + 1] != -1)
                    a[i][j] += a[i][j + 1];
                if (i < n && a[i + 1][j] != -1)
                    a[i][j] += a[i + 1][j];
                a[i][j] = a[i][j] % 9901;
            }
        }
    }
    fout << a[1][1] % 9901;
    return 0;
}