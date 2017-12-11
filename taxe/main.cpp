

#include <fstream>

using namespace std;
ifstream fin("taxe.in");
ofstream fout("taxe.out");
int n, m, i, j, a[201][201], b[201][201];

int pd(int x, int y)
{
    if (x <= n && x > 0 && y <= m && y > 0) {
        if (b[x][y] != 0)return b[x][y];
        int mx;
        if (x == n) {
            mx = min(pd(x - 1, y + 1), pd(x, y + 1));
        } else if (x == 1) {
            mx = min(pd(x + 1, y + 1), pd(x, y + 1));
        } else {
            mx = min(pd(x - 1, y + 1), pd(x + 1, y + 1));
            mx = min(mx, pd(x, y + 1));
        }
        b[x][y] = a[x][y] + mx;
        return b[x][y];
    }
    return 0;
}

int main()
{
    int mn = 1000000;
    fin >> n >> m;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            fin >> a[i][j];
        }
    }
    for (i = 1; i <= n; i++) {
        mn = min(mn, pd(i, 1));
    }
    fout << mn;
    return 0;
}