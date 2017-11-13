#include <iostream>

using namespace std;

int n, m, a[101][101], ok = 1, b[101][101], c[101][101], mx, is, js;
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
void inreg()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
           cout << b[i][j] << " ";
        }
	cout << '\n';
    }
}
void bk(int x, int y, int p)
{
    if(ok == 0 || b[x][y] != 0 || x > n || x < 1 || y > m || y < 1)
	return;
    if(p == n * m)
    {
        b[x][y] = p;
        inreg();
        ok = 0;
        return;
    }
    b[x][y] = p;
    for(int i = 0; i < 8; i++)
    {
       if(b[x + dx[i]][y + dy[i]] == 0)
		bk(x + dx[i],y + dy[i],p + 1);
    }
    b[x][y]=0;
}
int main()
{
    int i,j;
    cin >> n >> m >> is >> js;
    bk(is, js, 1);
    return 0;
}