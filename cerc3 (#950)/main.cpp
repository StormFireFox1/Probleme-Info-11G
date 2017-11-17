#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream fin("cerc3.in");
ofstream fout("cerc3.out");

int n, v[10001], x[1000001], k = 1, j, ok, c, m, r, i;

int main()
{
    fin >> n;
    for(i = 1;i <= n;i++)
    {
        fin >> m >> r;
        v[i] = m - r;
        x[i] = m + r;
    }
    while(k != 0)
    {
        k = 0;
        for(i = 1; i < n; i++)
        {
            if(x[i] > x[i+1])
            {
                int aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                aux = x[i];
                x[i] = x[i + 1];
                x[i + 1] = aux;
                k++;
            }
        }
    }
    j = 1;c = 1;
    for(i = 1; i <= n; i++)
    {
       ok = 0;
        while(x[i] >= v[j] && j < n)
        {
            j++;
            if(x[i] < v[j])
                ok = 1;
        }
        if(x[i] > v[j])
            j++;
        i = j - 1;
        if(ok == 1)
            c++;
    }
    fout << c;
    return 0;
}