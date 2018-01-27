#include <iostream>

using namespace std;

int v[1000];

int verif(int x)
{
	int d;
	for (d = 2; d * d <= x; d++)
		if (x % d == 0)
			return 0;
	return 1;
}

int rezolvare(int in, int sf)
{
	int a, b;
	if (in == sf)
	{
		if (verif(v[in]))
			return v[in];
		return 0;
	} else
	{
		a = rezolvare(in, (in + sf) / 2);
		b = rezolvare((in + sf) / 2 + 1, sf);
		if (a > b)
			return a;
		return b;
	}
}

int main()
{
	int n, i;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> v[i];
	cout << rezolvare(0, n - 1);
	return 0;
}