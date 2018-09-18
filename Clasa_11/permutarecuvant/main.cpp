#include <cstring>
#include <fstream>

using namespace std;

ifstream fin("permutarecuvant.in");
ofstream fout("permutarecuvant.out");

int main()
{
	char c[256];
	fin.getline(c, 256);
	int l = strlen(c);
	int i = 1;
	fout << c << " ";
	while(i < l)
    {
        for(int j = i; j < l; j++)
        {
            fout << c[j];
        }
        for(int j = 0; j < i; j++)
        {
            fout << c[j];
        }
        fout << " ";
        i++;
    }
    return 0;
}
