#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

int v[1001], n = 1;

bool s1(int x)
{
	for (int i = 2; i * i <= n; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

void s2(int v[], int n)
{
	sort(v, v + n);
}

int main()
{
	while (fin >> v[n]) {
		n++;		
	}
	s2(v, n);
	for (int i = 1; i <= n; i++) {
		if (s1(v[i])) {
			fout << v[i] << " ";
			break;
		}
	}

	for (int i = n; i >= 1; i--) {
		if (s1(v[i])) {
			fout << v[i] << " ";
			break;
		}
	}

	return 0;
}
