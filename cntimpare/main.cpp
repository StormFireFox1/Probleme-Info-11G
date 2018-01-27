#include <iostream>

using namespace std;
int v[1001];

int imp(int li, int ls)
{
	int a, b;
	if (li == ls)
	{
		if (v[li] % 2 == 1)
			return 1;
		else
			return 0;
	}
	else
	{
		a = imp(li, (li + ls) / 2);
		b = imp((li + ls) / 2 + 1, ls);
		return a + b;
	}
}

int main()
{
	int n, i;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> v[i];
	cout << imp(0, n - 1);
	return 0;
}