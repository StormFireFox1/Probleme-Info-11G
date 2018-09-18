#include <bits/stdc++.h>
using namespace std;

ifstream fin("countprimsub.in");
ofstream fout("countprimsub.out");

int nd[1005], n, k, nr[1005], val[1005], dr[1005], st[1005], r[1005];

bool prim(int x)
{
    if(x < 2) return false;

    for(int i = 2; i * i <= x; i++)
        if(x % i == 0) return false;

    return true;
}

void dfs(int nod)
{

    if(prim(val[nod])) nr[nod] ++;

    if (st[nod] != 0)
    {
        dfs(st[nod]);
        nr[nod] += nr[st[nod]];
    }
    
    if (dr[nod] != 0)
    {
        dfs(dr[nod]);
        nr[nod] += nr[dr[nod]];
    }
}

int main()
{
    int i, j,rad;

    fin >> n;

    for (i = 1; i <= n; i++)
    {
        fin >> val[i] >> st[i] >> dr[i];

        r[st[i]]++;
        r[dr[i]]++;
    }

    fin >> k;

    for(i = 1; i <= k; i++)
        fin >> nd[i];

    for(i = 1; i <= n; i++)
        if(r[i] == 0) rad = i;

    dfs(rad);

    for(i = 1; i <= k; i++)
    {
        fout << nr[nd[i]] << '\n';
    }


    return 0;
}
