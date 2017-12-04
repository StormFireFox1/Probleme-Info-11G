#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("masini.in");
ofstream fout("masini.out");

int main()
{
	int n, t, masini[1001];
    fin >> n >> t;
    int i = 0;
    for(i = 1; i <= n; i++)
    {
        fin >> masini[i];
    }
    sort(masini, masini + n + 1);
    int k = 0, suma = 0;
    for(i = 1; i <= n && suma < t; i++)
    {
        suma += masini[i];
        if(suma <= t)
        {
            k++;
        }
    }
    fout << k;
    return 0;
}
