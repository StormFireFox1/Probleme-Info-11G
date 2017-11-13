#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("soarece.in");
ofstream fout("soarece.out");

int n, m, a[101][101], is, js, ib, jb, s;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bk(int x, int y)
{
    if(x == ib && y == jb)
    {
        s++;
	return;
    }
    if(a[x][y] == 1 || x > n || x < 1 || y > m || y < 1)
	return;
     a[x][y] = 1;
    for(int i = 0; i < 4; i++)
    {
       bk(x + dx[i], y + dy[i]);
    }
    a[x][y] = 0;
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
    fin >> is >> js >> ib >> jb;
    bk(is, js);
    fout << s;
    return 0;
}