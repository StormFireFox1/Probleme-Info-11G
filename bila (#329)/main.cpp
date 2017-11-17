#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("bila.in");
ofstream fout("bila.out");

int n, m, a[101][101], mx, b[101][101], c[101][101], is, js;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
void bk(int x, int y, int p)
{
     if(x <= n && x > 0 && y <= m && y > 0)
     {
         int ok = 0;
	 b[x][y] = p;
         if(x == n || y == m || x == 1 || y == 1)
         {
             if(mx < p)
             {
                 mx = p;
                 return;
             }
         }
         for(int i = 0; i < 4; i++)
         {
             if(b[x + dx[i]][y + dy[i]] == 0 && a[x][y] > a[x + dx[i]][y + dy[i]])
             {
                 bk(x + dx[i], y + dy[i], p + 1);
                 ok = 1;
             }
         }
 
         b[x][y] = 0;
     }
     return;
}
int main()
{
    int i, j;
    fin >> n >> m;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
           fin >> a[i][j];
        }
    }
    fin >> is >> js;
    bk(is, js, 1);
    fout << mx;
    return 0;
}