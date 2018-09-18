#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("plopi1.in");
ofstream fout("plopi1.out");
int n, m, i, j, v[10001], mx, a[10001];

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
            if (v[i] < v[j]) {
                if (mx < a[j])mx = a[j];
            }
        }
        a[i] = mx + 1;
    }
    mx = 0;
    for (i = 1; i <= n; i++) {
        if (mx < a[i])mx = a[i];
    }
    fout << n - mx;
    return 0;
}