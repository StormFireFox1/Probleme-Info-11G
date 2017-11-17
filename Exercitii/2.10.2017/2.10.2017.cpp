/* Sursa exercitii probleme 2.10.2017 (ora info)

Probleme:

1. Fie doi vectori a si b cu n si m elemente. Sa se calculeze suma (i = 1; i <= n), (j = 1; j <= m) din a[i] * b[j] astfel
incat suma sa fie maxima.
2. Se dau doi vectori, a si b, a cu n elemente si b cu m elemente. Cei doi vectori pot fi prelucrati.
Se cere sa se faca numarul minim de interschimbari intre un element din a si un element din b astfel incat orice element din a sa fie mai mic sau egal decat orice element din b.

Pentru a apela probleme, inseareaza mai intai numarul problemei si apoi datele. Sursele pentru fiecare problema sunt in functii.

*/

#include <iostream>
#include <algorithm>

using namespace std;


long long problema1(int a[], int b[], int n, int m)
{
	long long s = 0;
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	int i = n, j = m;
	while (i >= 1 && a[i] > 0)
	{
		s += a[i] * b[j];
		i--;
		s--;
	}
	i = 1;
	j = 1;
	while (i <= 1 && a[j] < 0)
	{
		s += a[i] * b[j];
		i++;
		j++;
	}
	return s;
}

void problema2(int a[], int b[], int n, int m)
{
	int aux;
	sort(a, a + n);
	sort(b, b + n);
	int i = n, j = 1;
	while (i >= 1 && a[i] > b[j])
	{
		aux = a[i];
		a[i] = b[j];
		b[j] = aux;
		i--;
		j++;
	}
}


int main()
{
	int a[5000], b[5000], m, n, nrp;
	cout << "NUMARUL PROBLEMEI:";
	cin >> nrp;
	if (nrp == 1)
	{
		cout << "RUNNING PROBLEMA 1";
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int j = 0; j < m; j++)
		{
			cin >> b[j];
		}
		cout << problema1(a, b, n, m);
		return 0;
	}
	else
	{
		cout << "RUNNING PROBLEMA 2";
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int j = 0; j < m; j++)
		{
			cin >> b[j];
		}
		problema2(a, b, n, m);

		return 0;
	}
}