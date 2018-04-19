#include <fstream>

using namespace std;

ifstream fin("frunze.in");
ofstream fout("frunze.out");

int n, CT[101], x, radacina, vf;

int main()
{
	fin >> n;
	for (int i = 1; i <= n; i++)
	{
		fin >> x;
		if (x == 0)
			radacina = i;
		CT[x] = 1;
	}
	fout << radacina << endl;
	for (int i = 1; i <= n; i++)
		if (CT[i] == 0)
			vf++;
	fout << vf << endl;
	for (int i = 1; i <= n; i++)
		if (CT[i] == 0)
			fout << i << ' ';
	return 0;
}
