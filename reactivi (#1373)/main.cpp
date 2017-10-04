/* Reactivi

   Reactivi este o problema clasica de Greedy. Diferenta este ca in aceasta problema, se sorteaza un pair, putin mai complex. Aceasta sursa este
   un loc excelent pentru a afla niste lucruri basic despre declarari de tip vector <pair <int, int> >.

   Sursa originala de @StormFireFox1 si @sabinanton
*/

#include <fstream>
#include "stdafx.h"
#include <vector> //necesar pentru vector <pair <int, int> >
#include <algorithm> //pentru sort


using namespace std;

ifstream fin("reactivi.in"); // deschidere fisiere citire
ofstream fout("reactivi.out");

long long n, m, i, j, p, a, c = 1;
vector <pair<int, int> > v;
int main()
{
	fin >> n;
	for (i = 1; i <= n; i++)
	{
		fin >> m >> p;
		v.push_back(make_pair(p, m)); //se pune al doilea element primul in pair datorita faptului ca se sorteaza mai usor asa
	}
	sort(v.begin(), v.end());
	a = v[0].first;
	for (i = 0; i<n; i++)
	{
		if (a < v[i + 1].second) //daca al doilea element are intervalul de temperatura de sus in afara intervalului de temperatura primului element....
		{
			c++; // ...fa alt frigider...
			a = v[i + 1].first; // ...si pune acest interval in el
		}
	}
	fout << c; // PROFIT!
	return 0;
}
