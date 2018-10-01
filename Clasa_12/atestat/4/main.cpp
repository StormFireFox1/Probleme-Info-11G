#include <fstream>
#include <cmath>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

int s1(int k)
{
    int x = sqrt(k);
    return x * x;
}

void s2(int p, int q, int v[])
{
    bool ok = true;
    while (ok)
    {
        for (int i = p; i < q; i++)
        {
            if (v[i] > v[i + 1])
            {
                int aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                ok = 1;
            }
        }
    }
}

int main()
{
    int x;
    int i;
    int j = 1;
    int n, v[100];
    fin >> n;
    for (i = 1; i <= n; i++)
    {
        fin >> x;
        if (x == s1(x))
        {
            v[j] = x;
            j++;
        }
    }
    s2(1, j - 1, v);
    for (int i = 1; i < j; i++)
    {
        fout << v[i] << " ";
    }
    return 0;
}