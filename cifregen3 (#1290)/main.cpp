/* cifregen3
   Problema tipica de backtracking. Conditia de verificare este foarte simpla.
*/

#include <iostream>
 
using namespace std;
 
int n, st[20], m;
 
void afisare()
{
    for(int i = 1; i < n; i++)
	cout << st[i];
    cout << st[1] << '\n';
}
 
int valid(int k)
{
    if(st[1] == 0)
	return 0;
    return 1;
}
 
void backtrack(int k)
{
    if(k == n)
	afisare();
    else
        for(int i = 0; i < m; i++)
        {
            st[k] = i;
            if(valid(k))
		backtrack(k + 1);
        }
}
 
int main()
{
    cin >> n >> m;
    backtrack(1);
    return 0;
}