#include <iostream>

using namespace std;

int v[1000];

int rezolvare(int in, int sf)
{
	int a, b;
	if (in == sf)
		return v[in];
	else
	{
		a = rezolvare(in, (in + sf) / 2);
		b = rezolvare((in + sf) / 2 + 1, sf);
		if (a > b)
			return a;
		else
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