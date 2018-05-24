#include <fstream>

using namespace std;

struct nod
{
	int inf;
	nod *st, *dr;
} *rad;

ifstream fin("postordine1.in");
ofstream fout("postordine1.out");

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

void postordine(nod *rad)
{
	if (rad)
	{
		postordine(rad->st);
		postordine(rad->dr);
		fout << rad->inf << ' ';
	}
}

int main()
{
	creare(rad);
	postordine(rad);
	return 0;
}