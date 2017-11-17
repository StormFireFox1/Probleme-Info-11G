#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("hercule.in");
ofstream fout("hercule.out");

int n, m, a[101][101], mx, b[101][101], c[101][101], is, js, s;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
void bk(int x, int y, int p)
{
     if(x <= n && x > 0 && y <= m && y > 0)
     {
         if(p > a[x][y] || b[x][y] != 0)
	     return;
         if(x == n && y == m)
         {
             s++;
             return;
         }
         b[x][y]=p;
         for(int i = 0; i < 4; i++)
         {
             bk(x + dx[i], y + dy[i], p + 1);
         }
 
         b[x][y]=0;
     }
     return;
}
int main()
{
    int i,j;
    fin >> n >> m;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
           fin >> a[i][j];
        }
    }
    bk(1, 1, 1);
    fout << s;
    return 0;
}