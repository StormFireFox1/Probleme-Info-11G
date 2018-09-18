#include <iostream>

using namespace std;

int n, m, b, c, grad, ok = 1, s;
int a[101][101], viz[101];

int dfs(int nod)
{
    viz[nod] = 1;
    for (int k = 1; k <= n; k++)
        if (a[k][nod] == 1 && viz[k] == 0)
            dfs(k);
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> b >> c;
        a[b][c] = 1;
    }
    for (int i = 1; i <= n && ok; i++)
    {
        dfs(i);
        s = 0;
        for (int j = 1; j <= n; j++)
        {
            s += viz[j];
            viz[j] = 0;
        }
        if (s == n)
        {
            ok = 0;
            cout << i;
        }
    }
    if (ok == 1)
        cout << "NU EXISTA";
    return 0;
}