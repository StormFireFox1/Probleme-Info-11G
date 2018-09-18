#include <iostream>

using namespace std;

int v[25000], y[200000];

int rezolvare(int x, int in, int sf)
{
	if (in > sf)
		return 0;
	int mij = (in + sf) / 2;
	if (x == v[mij])
		return 1;
	if (x < v[mij])
		return rezolvare(x, in, mij - 1);
	return rezolvare(x, mij + 1, sf);
}

int main()
{
	int n, i, m;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> v[i];
	cin >> m;
	for (i = 0; i < m; i++)
	{
		cin >> y[i];
		cout << rezolvare(y[i], 0, n - 1) << " ";
	}
	return 0;
}