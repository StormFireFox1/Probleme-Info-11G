#include <iostream>

using namespace std;

int n, m, b, c, grad;
int gri[101], gre[101];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> b >> c;
        gri[c]++;
        gre[b]++;
    }
    for (int i = 1; i <= n; i++)
        if (gri[i] == 0)
        {
            cout << i << " ";
            grad++;
        }
    if (grad == 0)
        cout << "NU EXISTA";
    return 0;
}