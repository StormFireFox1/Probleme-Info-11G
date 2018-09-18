#include <fstream>

using namespace std;

ifstream fin("bete.int");
ofstream fout("bete.out");

int x[100];

int main()
{
    int n, s;
    fin >> n >> s;
    for (int i = 1; i <= n; i++)
        fin >> x[i];
    int v[s + 1], a[s + 1];
    for (int i = 1; i <= s; i++)
    {
        if (x[i] <= s) v[x[i]] = 1;
        for (int j = 1; j <= s; j++)
            if (v[i] == 1)
            {
                v[x[i] + j] = 1;
                a[j] = x[i];
            }
    }
    if (v[s] == 0) fout << "NU";
    else
    {
        fout << "DA";
        while (s > 0)
        {
            fout << a[s] << " ";
            s -= a[s];
        }
    }
    return 0;
}