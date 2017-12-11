#include <bits/stdc++.h>

using namespace std;
ifstream fin("comori.in");
ofstream fout("comori.out");
int n, m, i, j, a[201][201], b[201][201];

int pd(int x, int y)
{
    if (x <= n && x > 0 && y <= m && y > 0) {
        if (b[x][y] != 0)return b[x][y];
        int mx;
        if (y == m) {
            mx = max(pd(x + 1, y), pd(x + 1, y - 1));
        } else if (y == 1) {
            mx = max(pd(x + 1, y), pd(x + 1, y + 1));
        } else {
            mx = max(pd(x + 1, y), pd(x + 1, y + 1));
            mx = max(mx, pd(x + 1, y - 1));
        }
        b[x][y] = a[x][y] + mx;
        return b[x][y];
    }
    return 0;
}

int main()
{
    int mn = 0;
    fin >> n >> m;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            fin >> a[i][j];
        }
    }
    for (i = 1; i <= m; i++) {
        mn = max(mn, pd(1, i));
    }
    fout << mn;
    return 0;
}