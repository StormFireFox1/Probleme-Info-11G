#include <iostream>

using namespace std;
int n, m, x, y, c, gradExterior[101], gradInterior[101], v[101], nr = 1;

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y;
		gradExterior[x]++;
		gradInterior[y]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (gradExterior[i] == gradInterior[i])
		{
			c++;
			v[c] = i;
		}
	}
	cout << c << endl;
	for (int i = 1; i <= c; i++)
		cout << v[i] << ' ';

	return 0;
}
