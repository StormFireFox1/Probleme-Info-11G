#include <fstream>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

int v[100001];

void s1(int v[], int &n, int i) 
{
	for (int j = i; j < n; j++) {
		v[j] = v[j + 1];
	}
	n--;
}

int s2(int k) 
{
	if (k % 2 == 0) {
		return 2;
	}
	for(int i = 3; i * i <= k; i += 2) {
		if (k % i == 0) {
			return i;
		}
	}
	return k;
}

int main() 
{
	int n;
	fin >> n;
	for (int i = 1; i <= n; i++) {
		fin >> v[i];
	}
	for (int i = 1; i < n; i++) {
		if (s2(v[i]) == v[i] && s2(v[i + 1]) == v[i + 1]) {
			s1(v, n, i + 1);
			i--;
		}
	}
	for (int i = 1; i <= n; i++) {
		fout << v[i] << ' ';
	}
	return 0;
}
