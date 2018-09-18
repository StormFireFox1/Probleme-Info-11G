#include <iostream>

using namespace std;

int pivot(int v[], int li, int ls)
{
	int i = li, j = ls, di = 0, dj = 1, aux;
	while (i < j)
	{
		if (v[i] > v[j])
		{
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
			aux = di;
			di = dj;
			dj = aux;
		}
		i = i + di;
		j = j - dj;
	}
	return i;
}

void qs(int v[], int li, int ls)
{
	if (li < ls)
	{
		int poz = pivot(v, li, ls);
		qs(v, li, poz - 1);
		qs(v, poz + 1, ls);
	}
}

int main()
{
	int v[100001], n, i;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> v[i];
	qs(v, 0, n - 1);
	for (i = 0; i < n; i++)
		cout << v[i] << " ";
	return 0;
}