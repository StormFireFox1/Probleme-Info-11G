#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("traseucal.in");
ofstream fout("traseucal.out");

int n, m, a[101][101], ok = 1, b[101][101];
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

void afisare()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            fout << b[i][j] << " ";
        }
	fout << '\n';
    }
}
void bk(int x, int y, int p)
{
    if(ok == 0)
	return;
    if(a[x][y] == -1)
    {
        b[x][y] = p;
        afisare();
        ok = 0;
        return;
    }
    if(b[x][y] != 0 || x > n || x < 1 || y > m || y < 1)
	return;
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
    int i, j;
    fin >> n >> m;
    for(i = 1; i <= n; i++)
    {
        for(j = 0; j < m; j++)
        {
            fin >> a[i][j];
        }
    }
    a[n][m] = -1;
    bk(1, 1, 1);
    if(ok == 1)
    {
        for(i = 1; i <= n; i++)
    	{
            for(j = 1; j <= m; j++)
       	    {
      	        fout << b[i][j] << " ";
      	    }
      	    fout << '\n';
    	}
    }
    return 0;
}