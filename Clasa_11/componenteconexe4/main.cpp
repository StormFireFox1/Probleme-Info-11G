#include <iostream>

using namespace std;

int n, m, p, t[1000001], h[1000001], x1[1000001], y1[1000001];

int rad(int x)
{
	if (t[x] == 0)
		return x;
	t[x] = rad(t[x]);
	return t[x];
}

void uniune(int x, int y)
{
	int rx = rad(x);
	int ry = rad(y);
	if (rx == ry)
	{
		return;
	}
	if (h[rx] < h[ry])
		t[rx] = ry;
	else
	{
		t[ry] = rx;
		if (h[ry] == h[rx])
			++h[ry];
	}
}

int main()
{
	int nr, j, rez[1000001];
	cin >> n >> m;
	nr = n;
	for (int i = m; i > 0; i--)
	{
		cin >> x1[i] >> y1[i];
	}
	for (int i = 1; i <= m; i++)
	{
		rez[i] = nr;
		if (rad(x1[i]) != rad(y1[i]))
			nr--;
		uniune(x1[i], y1[i]);
	}
	for (int i = m; i > 0; i--)
	{
		cout << rez[i] << '\n';
	}
	return 0;
}
