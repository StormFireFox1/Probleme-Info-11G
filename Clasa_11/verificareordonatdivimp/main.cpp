#include <iostream>

using namespace std;

int v[500];

bool verificare(int in, int sf)
{
	if (in == sf)
		return true;
	bool a = verificare(in, (in + sf) / 2);
	bool b = verificare((in + sf) / 2 + 1, sf);
	return (a && b && v[(in + sf) / 2] <= v[(in + sf) / 2 + 1]);
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> v[i];

	if (verificare(0, n - 1))
		cout << "DA";
	else
		cout << "NU";
	return 0;
}