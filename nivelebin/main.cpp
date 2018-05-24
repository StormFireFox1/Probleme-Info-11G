#include <fstream>

using namespace std;

ifstream fin("nivelebin.in");
ofstream fout("nivelebin.out");

struct nod
{
	int inf;
	nod *st, *dr;
} *rad;

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

int main()
{

}