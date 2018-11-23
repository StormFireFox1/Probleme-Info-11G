#include <fstream>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

int v[101], n;

void s1(int v[], int n, int &m, int &poz) {
	m = -1;
	for (int i = 1; i <= n; i++) {
		if (m < v[i]) {
			m = v[i];
			poz = i;
		}
	}
}

void s2(int v[], int n) {
	int aux = v[1];
	for (int i = 1; i < n; i++) {
		v[i] = v[i + 1];
	}
	v[n] = aux;
}

int main() {
	fin >> n;
	for (int i = 1; i <= n; i++) {
		fin >> v[i];
	}
	int m = 0, poz = 0;
	s1(v, n, m, poz);
	while (v[n] != m) {
		s2(v, n);
	}
	for (int i = 1; i <= n; i++) {
		fout << v[i] << " ";
	}
	return 0;
}
