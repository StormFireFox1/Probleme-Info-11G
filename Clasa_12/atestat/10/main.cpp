#include <fstream>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

void s1(int a[][31], int &n)
{
	fin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			fin >> a[i][j];
		}
	}
}

int s2(int a[][31], int L)
{
	int s = 0;
	int j = 1;
	for (int i = L; i >= 1; i--) {
		s += a[i][j];
		j++;
	}
	return s;
}

int main()
{
	int n;
	int a[31][31];
	int max = 0;
	s1(a, n);
	for (int i = 1; i <= n; ++i) {
		if (max < s2(a, i))
			max = s2(a, i);
	}
	fout << max;
	return 0;

}
