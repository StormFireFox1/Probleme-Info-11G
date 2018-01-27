#include <iostream>

using namespace std;

int v[1000];

int verif(int x)
{
	int c = 0;
	while (x)
	{
		x = x / 10;
		c++;
	}
	if (c % 2 == 0)
		return 1;
	return 0;
}

int rezolvare(int in, int sf)
{
	int a, b;
	if (in == sf)
	{
		if (verif(v[in]))
			return 1;
		return 0;
	} else
	{
		a = rezolvare(in, (in + sf) / 2);
		b = rezolvare((in + sf) / 2 + 1, sf);
		if (a == b)
			return a;
		return 0;
	}
}

int main()
{
	int n, i;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> v[i];
	if (rezolvare(0, n - 1))
		cout << "DA";
	else
		cout << "NU";
	return 0;
}