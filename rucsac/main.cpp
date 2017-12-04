/* Rucsac
Rucsac este o problema clasica de tip Greedy, dar cu ideea ca se sorteaza nu dupa greutate sau valoare, ci dupa un raport dintre ele, deoarece noua
ne trebuie cat mai multa valoare din cat mai putina greutate.

Sursa initiala facuta de @alexmihax
*/


#include <iostream>

using namespace std;

int main()
{
	int n, g[1001], v[1001], i, d = 1;
	float gmax, x[1001], aux, sum = 0;
	cin >> n >> gmax;
	for (i = 1; i <= n; i++) // citire
	{
		cin >> g[i] >> v[i],
		x[i] = (float)v[i] / g[i];
	}
	while (d) //Bubble Sort pe 3 vectori
	{
		d = 0;
		for (i = 1; i<n; i++)
		{
			if (x[i]<x[i + 1])
			{
				aux = x[i];
				x[i] = x[i + 1];  //interschimbare raport
				x[i + 1] = aux;

				aux = g[i];
				g[i] = g[i + 1];  //interschimbare greutate
				g[i + 1] = aux;

				aux = v[i];
				v[i] = v[i + 1];  //interschimbare valoare
				v[i + 1] = aux;

				d++;
			}
		}
	}

	for (i = 1; i <= n && gmax > 0; i++) 
	{
		if (gmax >= g[i])
		{
			sum += v[i];
			gmax -= g[i];
		}
		else
		{
			sum += (float)gmax * v[i] / g[i];
			gmax = 0;
		}
	}
	cout << sum;
	return 0;
}