#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

int v[1001], n = 1;

bool s1(int x)
{
	if (x == 3)
		return true;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

void s2(int v[], int n)
{
	sort(v, v + n - 1);
}

int main()
{
	bool thereArePrime = 0;
	while (fin >> v[n]) {
		n++;		
	}
	n--;
	s2(v, n);
	for (int i = 1; i <= n; i++) {
		if (s1(v[i])) {
			thereArePrime = 1;
			fout << v[i] << " ";
			break;
		}
	}

	for (int i = n; i >= 1; i--) {
		if (s1(v[i])) {
			thereArePrime = 1;
			fout << v[i] << " ";
			break;
		}
	}

	if (!thereArePrime) {
		fout << "NU EXISTA";
	}

	return 0;
}
