/* Permutari2
   Problema clasica de backtracking. In loc sa avem numere de la 1 la n, vom avea exact ca la problema permutari, numai ca
   vom avea sortate elementele inserate.
*/

#include <fstream>
#include <algorithm>
 
using namespace std;
 
ifstream fin("permutari2.in");
ofstream fout("permutari2.out");
 
int n, st[20], v[20];
 
void afisare()
{
    for(int i = 1; i <= n; i++)
	fout << st[i] << " ";
    fout << "\n";
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
    int i;
    fin >> n;
    for(i = 1; i <= n; i++)
	fin >> v[i];
    sort(v + 1, v + n + 1);
    backtrack(1);
    return 0;
}
