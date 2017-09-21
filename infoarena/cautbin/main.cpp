#include <fstream>
 
using namespace std;
 
ifstream fin("cautbin.in");
ofstream fout("cautbin.out");
 
const int NMAX = 100000;
 
int v[NMAX + 1];
int n, n2;
 
int cautbin0(int x)
{
    int sol = 0;
    for(int i = n2; i > 0; i/=2)
    {
        if(sol + i <= n && v[sol + i] <= x)
        {
            sol += i;
        }
    }
    if(x == v[sol])
    {
        return sol;
    }
    else
    {
        return -1;
    }
}
 
int cautbin1(int x)
{
    int sol = 0;
    for(int i = n2; i > 0; i/=2)
    {
        if(sol + i <= n && v[sol + i] <= x)
        {
            sol += i;
        }
    }
    return sol;
}
 
int cautbin2(int x)
{
    int sol = n + 1;
    for(int i = n2; i > 0; i/=2)
    {
        if(sol - i >= 1 && v[sol - i] >= x)
        {
            sol -= i;
        }
    }
    return sol;
}
 
int main()
{
    int m;
    fin >> n;
    for(n2 = 1; n2 * 2 <= n; n2*=2)
    {
    }
    for(int i = 1; i <= n; i++)
    {
        fin >> v[i];
    }
    fin >> m;
    for(int i = 1; i <= m; i++)
    {
        int tip, nr;
        fin >> tip >> nr;
        if(tip == 0)
        {
            fout << cautbin0(nr) << "\n";
        }
        else if(tip == 1)
        {
            fout << cautbin1(nr) << "\n";
        }
        else
        {
            fout << cautbin2(nr) << "\n";
        }
    }
    return 0;
}