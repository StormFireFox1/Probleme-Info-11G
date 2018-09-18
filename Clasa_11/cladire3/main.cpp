#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("cladire3.in");
ofstream fout("cladire3.out");
int n, m, i, j, a[201][201], s[201][201];

int main()
{
    fin >> n >> m;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            fin >> a[i][j];
        }
    }
    for (i = n; i > 0; i--) {
        for (j = 1; j <= m; j++) {
            if (j == 1) {
                s[i][j] = a[i][j] + s[i + 1][j];
            } else if (i == n) {
                s[i][j] = a[i][j] + s[i][j - 1];
            } else {
                if (s[i + 1][j] < s[i][j - 1]) {
                    s[i][j] = a[i][j] + s[i + 1][j];
                } else {
                    s[i][j] = a[i][j] + s[i][j - 1];
                }
            }

        }
    }
    fout << s[1][m];
    return 0;
}