#include<iostream>
#include <fstream>

using namespace std;

ifstream fin("partitiimultime.in");
ofstream fout("partitiimultime.out");

int sol[20], n, maxim[20];

void afisare()
{
	int i, j;
	
	for (i=1; i<=maxim[n]; i++)
	{
	
		for (j=1; j<=n; j++)
			if (sol[j] == i)
				  fout<<j;
		
		fout << '*';
	}
	fout <<'\n';
}

void back(int k)
{
	int i;
	if (k-1==n) afisare();
	
	else for (i=1; i<=maxim[k-1] + 1; i++)
		{
			sol[k] = i;
			maxim[k] = max(maxim[k-1],i);
			back(k + 1);
		}
}

int main()
{
	fin>>n;
	
	back(1);
	
	return 0 ;
}