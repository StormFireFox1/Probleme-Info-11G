#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream f("proiecte.in");
ofstream g("proiecte.out");

struct mas
{
    int t, ord;
};

bool cool(mas a, mas b)
{
    if(a.t<b.t) return true;
    return false;
}

int main()
{
    int n, i;
    mas v[1001];
    f>>n;
    for(i=1; i<=n; i++)
    {
        f>>v[i].t;
        v[i].ord=i;
    }
    sort(v+1, v+n+1, cool);
    for(i=1; i<=n; i++) g<<v[i].ord<<" ";
    return 0;
}