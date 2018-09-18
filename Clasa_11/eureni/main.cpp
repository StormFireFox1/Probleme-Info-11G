#include <fstream>

using namespace std;

ifstream fin("eureni.in");
ofstream fout("eureni.out");

int main()
{
 	int s, n, e, v[11], i, k = 0, x = 0;
    fin >> s >> n >> e;
    v[0] = 1;
    for(i = 1; i <= n; i++)
    {
     	v[i] = v[i - 1] * e;
    }
    i = n;
    while(s > 0)
    {
     	x = s / v[i];
        if(x > 0)
        {
            k += x;
         	fout << v[i] << ' ' << x << '\n';
            s -= v[i] * x;
        }
        i--;
    }
    fout << k;
    return 0;
}
