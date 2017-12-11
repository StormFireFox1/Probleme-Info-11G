#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("cladire5.in");
ofstream fout("cladire5.out");
int n, m, i, j, a[201][201], x, s[201][201];

int main()
{
    fin >> n >> m >> x;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            fin >> a[i][j];
        }
    }
    for (i = 1; i <= n; i++) {
        for (j = m; j > 0; j--) {
            if (j == m) {
                s[i][j] = a[i][j] + s[i - 1][j];
            } else if (i == 1) {
                s[i][j] = a[i][j] + s[i][j + 1];
            } else {
                if (s[i - 1][j] < s[i][j + 1]) {
                    s[i][j] = a[i][j] + s[i - 1][j];
                } else {
                    s[i][j] = a[i][j] + s[i][j + 1];
                }
            }

        }
    }
    fout << x - s[n][1];
    return 0;
}