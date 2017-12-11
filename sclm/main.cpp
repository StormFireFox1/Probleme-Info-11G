#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("sclm.in");
ofstream fout("sclm.out");
int n, m, i, j, v[3001], mx, c, x, z[3001], p[3001], a[3001];

int main()
{
    int n;
    fin >> n;
    for (i = 1; i <= n; i++) {
        fin >> v[i];
        a[i] = 1;
    }
    for (i = 1; i <= n; i++) {
        mx = 0;
        for (j = 1; j < i; j++) {
            if (v[i] > v[j]) {
                if (mx < a[j]) {
                    mx = a[j];
                    p[i] = j;
                }
            }
        }
        a[i] = mx + 1;
    }
    p[1] = 0;
    mx = 0;
    for (i = 1; i <= n; i++) {
        if (mx < a[i]) {
            mx = a[i];
            x = i;
        }
    }
    fout << mx << '\n';
    while (x != 0) {
        z[++c] = x;
        x = p[x];
    }
    for (i = c; i > 0; i--) {
        fout << z[i] << " ";
    }
    return 0;
}