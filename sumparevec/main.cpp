#include <iostream>

using namespace std;

int v[1001];

int suma(int i, int j)
{
	int a, b;
	if (i == j)
	{
		if (v[i] % 2 == 1)
			return 0;
		return v[i];
	} else
	{
		a = suma(i, (i + j) / 2);
		b = suma((i + j) / 2 + 1, j);
		if (a % 2 == 0 && b % 2 == 0)
			return a + b;
		if (a % 2 == 0)
			return a;
		if (b % 2 == 0)
			return b;
		return 0;
	}
}

int main()
{
	int n, i;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> v[i];
	cout << suma(0, n - 1);
	return 0;
}