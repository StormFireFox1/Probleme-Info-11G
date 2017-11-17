/* produscartezian2
   Problema clasica de backtracking. La fel ca la cealalta, nu este necesara verificarea pentru ca toate solutiile vor fi
   valide. Mai nasoala este implementarea produselor carteziene. 
*/

#include <fstream>
 
using namespace std;
 
ifstream fin("produscartezian2.in");
ofstream fout("produscartezian2.out");
 
int st[30], a[30], n;
 
void afisare()
{
    for(int i = 1;i <= n; i++)
        fout << st[i] << ' ';
    fout << '\n';
}
 
int valid(int k)
{
    return 1;
}
 
void backtrack(int k)
{
    if(k == n + 1)
	afisare();
    else
        for(int i = 1; i <= a[k]; i++)
        {
            st[k] = i;
            if(valid(k))
		backtrack(k + 1);
        }
}
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++)
        fin >> a[i];
    backtrack(1);
    return 0;
}