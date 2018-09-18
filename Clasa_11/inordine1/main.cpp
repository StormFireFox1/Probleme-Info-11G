#include <fstream>

using namespace std;

struct nod
{
	int inf;
	nod *st, *dr;
} *rad;

ifstream cin("inordine1.in");
ofstream cout("inordine1.out");

void creare(nod *&rad)
{
	int x;
	cin >> x;
	if (x == 0)rad = NULL;
	else
	{
		rad = new nod;
		rad->inf = x;
		creare(rad->st);
		creare(rad->dr);
	}
}

void inordine(nod *rad)
{
	if (rad)
	{
		inordine(rad->st);
		cout << rad->inf << ' ';
		inordine(rad->dr);
	}
}

int main()
{
	creare(rad);
	inordine(rad);
	return 0;
}