#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("traseucalmax.in");
ofstream fout("traseucalmax.out");

int n, m, a[101][101], ok = 1, b[101][101], c[101][101], mx;
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
void inreg()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            c[i][j] = b[i][j];
        }
    }
}
void bk(int x, int y, int p)
{
    if(a[x][y] == 1 || x > n || x < 1 || y > m || y < 1)
	return;
    if(x == n && y == m)
    {
        b[x][y] = p;
        if(mx < p)
        {
            mx = p;
            inreg();
        }
        return;
    }
    a[x][y] = 1;
    b[x][y] = p;
    for(int i = 0; i < 8; i++)
    {
       bk(x + dx[i], y + dy[i], p + 1);
    }
    a[x][y] = 0;
    b[x][y] = 0;
}
int main()
{
    int i , j;
    fin >> n >> m;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            fin >> a[i][j];
        }
    }
    bk(1, 1, 1);
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            fout << c[i][j] << " ";
        }
        fout << '\n';
    }
    return 0;
}