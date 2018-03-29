#include <iostream>


using namespace std;

int n, m, x, y;
int a[101][101], st[4];

void afis()
{
    for (int i = 1; i <= 3; i++) 
    {
     	cout << st[i] << " ";   
    }
    cout << '\n';
}

int valid(int k)
{
 	if (k != 1 && a[st[k-1]][st[k]] == 0) return 0;
    if (k == 3 && a[st[3]][st[1]] == 0) return 0;
    return 1;
}

void bkt(int k)
{
 	if (k == 4)
        afis();
    else
    {
    	for(int i = 1; i <= n; i++)
        {
         	st[k] = i;
            if(valid(k) == 1)
                bkt(k+1);
        }
    }
}

int main()
{
 	cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
     	cin >> x >> y;
        a[x][y] = 1;
    }
    bkt(1);
    return 0;
}