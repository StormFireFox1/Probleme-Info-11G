#include <iostream>

using namespace std;

int v[201];

int ePrim(int a)
{
	int d;
	for (d = 2; d * d <= a; d++)
		if (a % d == 0)
			return 0;
	return 1;
}

int ex(int i, int j)
{
	if (i == j)
	{
		if (ePrim(v[i]) == 0)
			return 0;
		return 1;
	}
	int a = ex(i, (i + j) / 2);
	int b = ex((i + j) / 2 + 1, j);
	if (a || b)
		return 1;
	return 0;
}

int main()
{
	int n, i;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> v[i];
	if (ex(0, n - 1) == 0)
		cout << "NU";
	else
		cout << "DA";
	return 0;
}