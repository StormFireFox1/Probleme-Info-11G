#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("partitiinumar4.in");
ofstream fout("partitiinumar4.out");

int n, m;
int st[101], v[41];
int suma;

void afisare(int k)
{
    for(int i=1;i<k;i++) fout<<v[st[i]]<<" ";
    fout<<'\n';
}

void backtrack(int k)
{
    if(suma==n) afisare(k);
    else
    if(suma<n)
    {
        for(int i=st[k-1];i<=m;i++)
        {
            st[k]=i;
            suma=suma+v[i];
            backtrack(k+1);
            suma=suma-v[i];
        }
    }
}

int main()
{
    fin>>n>>m;
    for(int i=1; i<=m; i++) fin>>v[i];
    sort(v+1, v+m+1);
    st[0]=1;
    backtrack(1);
    return 0;
}
