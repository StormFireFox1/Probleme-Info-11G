#include <iostream>

using namespace std;

int v[1000];

int rezolvare(int in, int sf)
{
	int a, b;
	if (in == sf)
	{
		if (v[in] % 2 == 0)
			return 0;
		return 1;
	}
	else
	{
		a = rezolvare(in, (in + sf) / 2);
		b = rezolvare((in + sf) / 2 + 1, sf);
		if (a + b != 0)
			return 1;
		return 0;
	}
}

int main()
{
	int n, i;
	bool x;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> v[i];
	x = rezolvare(0, n - 1);
	if (x == 0)
		cout << "DA";
	else
		cout << "NU";
	return 0;
}