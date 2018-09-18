/* cifregen2
   Problema tipica de backtracking. O diferenta este ca, totusi, noi construim dintr-un sir predefinit. De asemenea, condi-
   tia de verificare este foarte simpla.
*/

#include <iostream>
 
using namespace std;
 
int n, st[20], x;
int v[5]={0, 2, 3, 5, 7};
 
void afisare()
{
    for(int i = 1; i <= n; i++)
	cout << st[i];
    cout << '\n';
}
 
int valid(int k)
{
    for(int i = 1; i < 5; i++)
        if(st[k] == v[i])
	    return 1;
    return 0;
}
 
void backtrack(int k)
{
    for(int i = 1; i <= 5; i++)
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
    cin >> n;
    backtrack(1);
    return 0;
}