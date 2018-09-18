/* cifregen4
   Problema clasica de backtracking. Foarte simplu, conditia de verificare e in problema. In rest la fel.
*/

#include <iostream>
#include <cmath>
 
using namespace std;
 
int n, st[20], m;
 
void afisare()
{
    for(int i = 1; i <= n; i++)
	cout << st[i];
    cout << '\n';
}
 
int valid(int k)
{
    if(st[1] == 0)
	return 0;
    else
        for(int i = 1; i < k; i++)
            if(abs((float)(st[i] - st[i + 1])) < 2)
		return 0;
    return 1;
}
 
void backtrack(int k)
{
    if(k == n + 1)
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