/* siruri
   Problema clasica de backtracking. Conditia de verificare este asemenea problemei.
*/

#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("siruri.in");
ofstream fout("siruri.out");

int n,k,m, v[17];

void afis()
{
    int i;
    for(i = 1; i <= m; i++)
        fout << v[i] << ' ';
    fout << '\n';
}

int valid(int k)
{
    if(k > 1 && v[k] - v[k - 1] > 2)
        return 0;
    return 1;
}

void bk(int k)
{
    int a;
    if(k == m + 1)
        afis();
    else
    {
        if(k == 1)
            a = 1;
        else
            a = v[k - 1] + 1;
        for(int j = a; j <= n - m + k; j++)
    	{
        	v[k] = j;
        	if(valid(k))
                bk(k + 1);
    	}
    }
}
int main()
{
    fin >> n >> m;
    bk(1);
    return 0;
}