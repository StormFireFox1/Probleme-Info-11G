#include <iostream>

using namespace std;

int v[1001], x[1001];

void verif(int li, int ls, int ls2)
{
	if (li == ls)
	{
		int semafor = 0;
		for (int i = 0; i < ls2; i++)
		if (x[li] == v[i])
			semafor = 1;
		if (semafor)
			cout << "1" << " ";
		else
			cout << "0" << " ";
	}
	else
	{
		int mij = (li + ls) / 2;
		verif(li, mij, ls2);
		verif(mij + 1, ls, ls2);
	}
}

int main()
{
	int n, i, m;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> v[i];
	cin >> m;
	for (i = 0; i < m; i++)
		cin >> x[i];
	verif(0, m - 1, n - 1);
	return 0;
}