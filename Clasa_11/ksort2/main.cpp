#include <iostream>

using namespace std;

void intercl(int v[], int li, int mij, int ls)
{
	int aux[200001], i, j, k;
	i = li;
	j = mij + 1;
	k = li;
	while (i <= mij && j <= ls)
	{
		if (v[i] < v[j])
			aux[k++] = v[i++];
		else
			aux[k++] = v[j++];
	}
	while (i <= mij)
		aux[k++] = v[i++];
	for (i = li; i < k; i++)
		v[i] = aux[i];
}

void intercl1(int v[], int li, int mij, int ls)
{
	int aux[200001], i, j, k;
	i = li;
	j = mij + 1;
	k = li;
	while (i <= mij && j <= ls)
	{
		if (v[i] > v[j])
			aux[k++] = v[i++];
		else
			aux[k++] = v[j++];
	}
	while (i <= mij)
		aux[k++] = v[i++];
	for (i = li; i < k; i++)
		v[i] = aux[i];
}

void ms(int v[], int li, int ls)
{
	int aux;
	if (ls - li <= 1)
	{
		if (v[li] > v[ls])
		{
			aux = v[li];
			v[li] = v[ls];
			v[ls] = aux;
		}
	}
	else
	{
		int mij = (li + ls) / 2;
		ms(v, li, mij);
		ms(v, mij + 1, ls);
		intercl(v, li, mij, ls);
	}
}

void ms1(int v[], int li, int ls)
{
	int aux;
	if (ls - li <= 1)
	{
		if (v[li] < v[ls])
		{
			aux = v[li];
			v[li] = v[ls];
			v[ls] = aux;
		}
	}
	else
	{
		int mij = (li + ls) / 2;
		ms1(v, li, mij);
		ms1(v, mij + 1, ls);
		intercl1(v, li, mij, ls);
	}
}

int main()
{
	int n, i, v[200001], k;
	cin >> n >> k;
	for (i = 0; i < n; i++)
		cin >> v[i];
	ms(v, 0, k - 1);
	ms1(v, k, n - 1);
	for (i = 0; i < n; i++)
		cout << v[i] << " ";
	return 0;
}