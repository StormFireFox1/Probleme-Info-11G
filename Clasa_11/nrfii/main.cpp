#include <fstream>

using namespace std;

ifstream fin("nrfii.in");
ofstream fout("nrfii.out");

int nrFii[101], maxim;

int main()
{
    int n;
	fin >> n;
    int x;
    for(int i = 1; i <= n; i++)
    {
    	fin >> x;
        nrFii[x]++;
    }
    for(int i = 1; i <= n; i++)
    {
        if (maxim < nrFii[i])
        {
         	maxim = nrFii[i];   
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if (nrFii[i] == maxim)
        {
         	fout << i << ' ';   
        }
    }
    return 0;
}