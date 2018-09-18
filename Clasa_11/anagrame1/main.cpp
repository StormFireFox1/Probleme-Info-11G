/* anagrame1
   Problema clasica de backtracking. Practic este problema aranjamente, numai ca ai litere in loc de numere. Un lucru in
   plus este sortarea intrarii, ca noi vrem in ordine alfabetica anagramele. De altfel, si in celelalte probleme de back-
   tracking se primesc, efectiv, variabile in ordine lexicografica.
*/

#include <fstream>
#include <cstring>
 
using namespace std;
 
ifstream fin("anagrame1.in");
ofstream fout("anagrame1.out");
 
int n;
char st[20], cuv[20], aux;
 
void afisare()
{
    fout << st << '\n';
}
 
int valid(int k)
{
    for(int i = 0; i < k; i++)
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
    for(int i = 0; i <= n - 1; i++)
    {
        st[k] = cuv[i];
        if(valid(k))
        {
            if(k == n - 1)
                afisare();
            else
                backtrack(k + 1);
        }
    }
}
 
int main()
{
    int i, j;
    fin >> cuv;
    n = strlen(cuv);
    for(i = 0; i <= n - 1; i++)
    {
        for(j = 0; j < n - 1; j++)
            if(cuv[j] - 'a' > cuv[j + 1] - 'a')
            {
                aux = cuv[j];
                cuv[j] = cuv[j + 1];
                cuv[j + 1] = aux;
            }
    }
    backtrack(0);
    return 0;
}