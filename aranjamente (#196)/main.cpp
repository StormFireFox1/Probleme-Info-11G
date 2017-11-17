/* aranjamente
   Problema clasica de backtracking. Se verifica daca cumva a fost deja folosit un anume element in stiva, acest lucru in-
   validand un posibil aranjament.
*/

#include <fstream>
 
using namespace std;
 
ifstream fin("aranjamente.in");
ofstream fout("aranjamente.out");
 
int n, st[20], x;
 
void afisare()
{
    for(int i = 1; i <= x; i++)
    {
         fout << st[i] << ' ';
    }
    fout << '\n';
}
 
int valid(int k)
{
    for(int i = 1; i < k; i++)
    {
        if(st[i] == st[k])
        {
            return 0;
        }
    }
    return 1;
}
 
void backtrack(int k)
{
    for(int i = 1; i <= n; i++)
    {
        st[k] = i;
        if(valid(k))
        {
            if(k == x)
                afisare();
            else
                backtrack(k+1);
        }
    }
}
 
int main()
{
    fin >> n >> x;
    backtrack(1);
    return 0;
}
