#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct nod
{
	int inf;
	nod *st, *dr;
} *rad;

ifstream fin("bifrunze1.in");
ofstream fout("bifrunze1.out");

vector <int> list;

void creare(nod *&rad)
{
	int x;
	fin >> x;
	if (x == 0)rad = NULL;
	else
	{
		rad = new nod;
		rad->inf = x;
		creare(rad->st);
		creare(rad->dr);
	}
}

void bifrunze1(nod *rad)
{
	if (rad)
	{
		bifrunze1(rad->st);
		bifrunze1(rad->dr);
		if (rad->st->inf == 0 && rad->dr->inf == 0)
		{
			list.push_back(rad->inf);
		}
	}
}

int main()
{
	creare(rad);
	bifrunze1(rad);
	sort(list.begin(), list.end());
	for (int number : list)
	{
		fout << number << ' ';
	}
	return 0;
}