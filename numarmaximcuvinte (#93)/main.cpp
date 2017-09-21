#include <cstring>
#include <fstream>

using namespace std;

ifstream fin("cuvmax.in");
ofstream fout("cuvmax.out");

int nrcuvinte(char c[])
{
    char *p = strtok(c, " ");
    int sol = 0;
    while(p)
    {
        sol++;
        p = strtok(NULL, " ");
    }
    return sol;
}

int main()
{
	char c[256], maxim[256], ctemp[256];
	int n, maxi = 0, l;
	fin >> n;
    fin.get();
    while(n)
    {
        fin.getline(c, 256);
        strcpy(ctemp, c);
        l = nrcuvinte(ctemp);
        if(l > maxi)
        {
            strcpy(maxim, c);
            maxi = l;
        }
        n--;
    }
    fout << maxim;
    return 0;
}
