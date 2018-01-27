#include <iostream>

using namespace std;

int v[1001];

int cmmdc(int x, int y)
{
	int r;
	while (y)
	{
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}

int rezolvare(int li, int ls)
{
	if (li == ls)
		return v[li];
	else
	{
		int a = rezolvare(li, (li + ls) / 2);
		int b = rezolvare((li + ls) / 2 + 1, ls);
		return cmmdc(a, b);
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