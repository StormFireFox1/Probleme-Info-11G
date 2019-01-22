#include <iostream>
#include <fstream>
#include <vector>	
#include <queue>

using namespace std;

ifstream fin("sortaret.in");	
ofstream fout("sortaret.out");
	
const int N = 50001, M = 100001;

vector <int> a[N];

int pred[N], stopol[N], nr;

bool viz[N];

void dfs(int x)
{	
    viz[x] = true;	
    for (auto y : a[x])
    {
        if(!viz[y])
        dfs(y);
    }
    stopol[++nr] = x;
}
	
int main()	
{
    int n, m;	
    fin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        fin >> x >> y;
        a[x].push_back(y);
    }
	
    for (int i = 1; i <= n; i++)
    {
        if (viz[i] == false)
        {
            dfs(i);
        }
    }
    for (int i = nr; i > 0; i--)
    {
        fout << stopol[i] << " ";
    }
    return 0;
}