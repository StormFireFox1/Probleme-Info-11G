#include <iostream>
#include <fstream>

using namespace std;

ifstream cin("matrice_div_et_imp.in");
ofstream cout("matrice_div_et_imp.out");

int a[513][513];

void rezolvare(int lss, int css, int ldj, int cdj, int dim)
{
	if (dim == 2)
	{
		cout << a[lss][css] << " " << a[ldj][cdj] << " " << a[lss][cdj] << " " << a[ldj][css] << " ";
	}
	else
	{
		rezolvare(lss, css, lss + dim / 2 - 1, css + dim / 2 - 1, dim / 2);
		rezolvare(lss + dim / 2, css + dim / 2, lss + dim / 2 + 1, css + dim / 2 + 1, dim / 2);
		rezolvare(lss, css + dim / 2, lss + dim / 2 - 1, css + dim / 2 + 1, dim / 2);
		rezolvare(lss + dim / 2, css, lss + dim / 2 + 1, css + dim / 2 - 1, dim / 2);
	}
}

int main()
{
	int n, i, j, dim = 1;
	cin >> n;
	for (i = 0; i < n; i++)
		dim = dim * 2;
	for (i = 0; i < dim; i++)
		for (j = 0; j < dim; j++)
			cin >> a[i][j];
	if (dim == 1)
		cout << a[i - 1][0];
	else
		rezolvare(0, 0, 1, 1, dim);
	return 0;
}