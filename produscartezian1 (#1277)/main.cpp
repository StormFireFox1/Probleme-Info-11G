/* produscartezian1
   Problema clasica de backtracking. O diferenta foarte faina este ca nu este necesara nicio verificare, deci e foarte usor.
*/

#include <iostream>
#include <fstream>
 
using namespace std;
 
ifstream fin("produscartezian1.in");
ofstream fout("produscartezian1.out");
 
int n, st[20], v[1003], m, c;
 
void afisare()
{
    for(int i = 1; i <= m; i++)
    {
         fout << st[i] << ' ';
    }
    fout << '\n';
}
 
void backtrack(int k)
{
    for(int i = 1; i <= n; i++)
    {
        st[k] = i;
        if(k == m)
            afisare();
        else
            backtrack(k + 1);
    }
}
 
int main()
{
    fin >> n >> m;
    backtrack(1);
    return 0;
}