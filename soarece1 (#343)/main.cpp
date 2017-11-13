#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("soarece1.in");
ofstream fout("soarece1.out");

int n, m, a[101][101], is, js, ib, jb, ok = 1, s;
char c[100001];
pair <int,int> v[10001];
int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};

void bk(int x, int y, int p)
{
    if(ok == 0)return;
    if(a[x][y] == -1)
    {
        v[p].first = x;
        v[p].second = y;
        s++;
        ok = 0;
        return;
    }
    if(a[x][y] != 0 || x > n || x < 1 || y > m || y < 1)
	return;
     a[x][y] = 1;
     v[p].first = x;
     v[p].second = y;
    for(int i = 0; i < 4; i++)
    {
       bk(x + dx[i], y + dy[i], p + 1);
    }
    a[x][y] = 0;
}
int main()
{
    int i, j;
    fin >> n >> m;
    for(i = 1;i <= n; i++)
    {
        fin >> c;
        for(j = 0; j < m; j++)
        {
            if(c[j] == '_')
		a[i][j + 1] = 0;
            else if(c[j] == '#')
		a[i][j + 1] = 1;
            else if(c[j] == 'S')
	    {
		is = i;
		js = j + 1;
	    }
            else a[i][j + 1] = -1;
        }
    }
    bk(is, js, 1);
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            a[i][j] = 0;
        }
    }
    for(i=1; v[i].first != 0; i++)
    {
        if(ok == 0)
	    a[v[i].first][v[i].second] = i;
    }
    for(i = 1; i <= n; i++)
    {
        for(j = 1;j <= m; j++)
        {
            fout << a[i][j] << " ";
        }
        fout << '\n';
    }
    return 0;
}