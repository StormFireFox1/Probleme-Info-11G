#include <fstream>

using namespace std;

int main()
{
    ifstream fin("spectacole.in");
    ofstream fout("spectacole.out");
    
    int n, x[101], y[101], flag = 1, k = 0, current;
    fin >> n;
    for(int i = 1; i <= n; i++)
    {
     	fin >> x[i];
        fin >> y[i];
    }
    while(flag)
    {
     	flag = 0;
        for(int i = 1; i < n; ++i)
        {
         	if(y[i] > y[i + 1])
            {
             	int aux = y[i];
                y[i] = y[i + 1];
                y[i + 1] = aux;
                aux = x[i];
                x[i] = x[i + 1];
                x[i + 1] = aux;
                flag = 1;
            }
        }
    }
    flag = 1;
    current = y[1];
    for(int i = 2; i <= n; ++i)
    {
     	if(x[i] >= current)
        {
         	flag++;
            current = y[i];
        }
    }
    fout << flag;
    return 0;
}