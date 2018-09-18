/* permutari1
   Problema clasica de backtracking. Dar generarea se face invers ==> i parcurge de la n la 1.
*/

#include <fstream>
 
using namespace std;
 
ifstream fin("permutari1.in");
ofstream fout("permutari1.out");
 
int n, st[20];
 
void afisare()
{
    for(int i = 1; i <= n; i++)
	fout << st[i] << ' ';
    fout << '\n';
}
 
int valid(int k)
{
    for(int i = 1; i < k; i++)
        if(st[i] == st[k])
	    return 0;
    return 1;
}
 
void backtrack(int k)
{
    for(int i = n; i > 0; i--)
    {
        st[k] = i;
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
    fin >> n;
    backtrack(1);
    return 0;
}