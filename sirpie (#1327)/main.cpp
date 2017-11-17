/* sirpie
   Problema mai nasoala de backtracking. Se adauga anumite conditii de validare fata de normal. Tot aceeasi idee, oricum.
*/

#include <algorithm>
#include <fstream>
 
using namespace std;
 
ifstream fin("sirpie.in");
ofstream fout("sirpie.out");
 
int n, st[20], v[20];
 
void afisare()
{
    for(int i = 1; i <= n; i++)
    {
        fout << st[i] << ' ';
    }
    fout << '\n';
}
 
int cmmdc(int a, int b)
{
    int r = a % b;
    while(r)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}
 
int valid(int k)
{
    for(int i = 1; i < k; i++)
        if(cmmdc(st[i], st[i + 1]) != 1 || st[i] == st[k]) //daca numerele nu sunt prime intre ele sau sunt aceleasi...
	    return 0; //...atunci e invalid, f off
    return 1;
}
 
void backtrack(int k)
{
    for(int i = 1; i <= n; i++)
    {
        st[k] = v[i];
        if(valid(k))
        {
            if(k == n)
                afisare();
            else
                backtrack(k + 1);
        }
    }
}
 
int main()
{
    int i, j, aux;
    fin >> n;
    for(i = 1; i <= n; i++)
    {
        fin >> v[i];
    }
    sort(v + 1, v + n + 1);
    backtrack(1);
    return 0;
}
