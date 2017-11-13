/* cifregen
   Problema simpla de backtracking. Singura diferenta e ca valorile pe nivel sunt de la a la b, nu de la 1 la n.
*/

#include <iostream>
 
using namespace std;
 
int n, st[20], v[20], a, b;
 
void afisare()
{
    for(int i = 1; i <= n; i++)
	cout << st[i];
    cout << '\n';
}
 
void backtrack(int k)
{
    for(int i = a; i <= b; i++)
    {
        st[k] = i;
        if(k == n)
                afisare();
            else
                backtrack(k + 1);
 
    }
}
 
int main()
{
    cin >> a >> b >> n;
    backtrack(1);
    return 0;
}