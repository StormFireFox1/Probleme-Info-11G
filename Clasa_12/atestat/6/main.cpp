#include <fstream>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

int v[100001], n;

int s1(int x, int y)
{
	return (x >= y ? x : y); // Asta este forma ternara, este o metoda speciala de a scrie un "if" statement
							 //
							 // Forma generala:
							 // (conditie) ? valoarea pentru "true" : valoarea pentru false
							 //
							 // In cazul acesta, se verifica daca x mai mare ca y, daca da, se returneaza
							 // x, daca nu, se returneaza y.
}

void s2(int v[], int &n, int k, int x)
{
	for (int i = n + 1; i >= k; i--) {
		v[i] = v[i - 1];
	}
	v[k] = x;
	n++;
}

int main()
{
	int max = 0;
	fin >> n;
	for (int i = 0; i < n; i++) {
		fin >> v[i];
	}
	for (int i = 0; i < n; i += 2) {
		max = s1(max, v[i]);
		s2(v, n, i + 1, max);
	}
	for (int i = 0; i < n; i++) {
		fout << v[i] << ' ';
	}
	return 0;
}
