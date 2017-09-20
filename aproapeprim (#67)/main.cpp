#include <cmath>

using namespace std;
int a_prim(int n)
{
    int i, j, ok = 0, c;
    for(i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            ok = 0;
            for(j = 2; j <= sqrt(i); j++)
            {
                if(i % j == 0)
                {
                    ok = 1;
                }
            }
            if(ok == 0)
            {
                c = n / i;
                for(j = 2; j <= sqrt(c); j++)
                {
                    if(c % j == 0)
                    {
                        ok = 1;
                    }
                }
                if(ok == 0 && c != i)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}