#include <fstream>
 
using namespace std;
 
ifstream fin("subsecv.in");
ofstream fout("subsecv.out");
 
const int inf = 10001;
 
int main()
{
    int n, i, j, v[inf];
    fin >> n;
    for(i = 0; i < n; i++)
    {
		fin >> v[i];
    }
    for(i = 0; i < n; i++)
    {
     	for(j = i; j < n; j++)
        {
         	long long sum = 0;
            for(int x = i; x <= j; x++)
            {
                sum += v[x];
            }
            if(sum % n == 0)
            {
             	fout << i + 1 << ' ' << j + 1;
                return 0;
            }
        }
    }
    return 0;
}