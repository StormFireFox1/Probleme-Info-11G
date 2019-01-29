#include <iostream>
#include <fstream>
#include <vector>	
#include <queue>
#define N 50001
#define M 100001

using namespace std;

ifstream fin("sortaret.in");	
ofstream fout("sortaret.out");

int pred[N],       // lista de predecesori, fiecare nod ține aici tatăl său
    stopol[N],     // lista simplă înlănțuită pentru sortare topologică
    nr;            // numărul de elemente din lista "stopol"
vector <int> a[N]; // lista de adiacență, fiecare nod ține în acest vector succesorii săi
bool viz[N];       // vectorul de vizitare al fiecărui nod

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