/* shuffle
   Problema clasica de backtracking. Conditia de verificare este mai complexa de scris, dar tot usoara.
*/

#include <fstream>
 
using namespace std;
 
ifstream fin("shuffle.in");
ofstream fout("shuffle.out");
 
int n, st[20], v[20];
 
void afisare()
{
    for(int i = 1; i <= n; i++)
	fout << st[i] << ' ';
    fout << '\n';
}
 
int valid(int k)
{
    for(int i = 1; i < k; i++)
        if(st[k] == st[i])
	    return 0;
        else
            for(int j = 1; j <= n; j++)
                if((st[i] == v[j] && st[i + 1] == v[j + 1]) || (st[i] == v[j + 1] && st[i + 1] == v[j]))
		    return 0;
    return 1;
}
 
void backtrack(int k)
{
    for(int i = 1; i <= n; i++)
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
    for(int i = 1; i <= n; i++)
	fin >> v[i];
    if(n <= 3)
        fout << "nu exista";
    else
        backtrack(1);
    return 0;
}