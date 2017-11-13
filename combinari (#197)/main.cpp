/* combinari
   Problema clasica de backtracking. Se verifica daca cumva a fost deja pus elementul in stiva, contrazicand ce ar fi
   o combinare. In rest, la fel.
*/

#include <fstream>
 
using namespace std;
 
ifstream fin("combinari.in");
ofstream fout("combinari.out");
 
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
         if(st[i] >= st[k])
         {
	      return 0;
	 }
    }
    return 1;
}
 
void backtrack(int k)
{
    for(int i = 1; i <= n - x + k; i++)
    {
        st[k] = i;
        if(valid(k))
        {
            if(k == x)
                afisare();
            else
                backtrack(k + 1);
        }
    }
}
 
int main()
{
    fin >> n >> x;
    backtrack(1);
    return 0;
}