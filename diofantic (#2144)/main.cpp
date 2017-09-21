#include <algorithm>
#include <cmath>

int cautbin(int s[], int n, int x)
{
    int sol = 1, n2;
	for(n2 = 1; n2 * 2 <= n; n2*=2)
   	{
	}
    for(int i = n2; i > 0; i/=2)
    {
        if(sol + i <= n && s[sol + i] <= x)
        {
            sol += i;
        }
    }
    if(x == s[sol])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int diofantic(int n, int s[], int a, int b, int c)
{
    sort(s + 1, s + n + 1);
    int i, expr, rad, k = 0;
    for(i = 1; i <= n && c - a * s[i] * s[i] >= 0; i++)
    {
		expr = c - a * s[i] * s[i];
		if(expr % b == 0)
		{
			expr /= b;
			rad = sqrt(expr);
			if(rad * rad == expr)
			{
				if(cautbin(s, n, rad))
				{
					k++;
				}
			}
		}
    }
	if(a == b)
	{
		k *= 2;
		return k;
	}
	else
	{
		for(i = 1; i <= n && c - a * s[i] * s[i] >= 0; i++)
		{
			expr = c - b * s[i] * s[i];
			if(expr % b == 0)
			{
				expr /= b;
				rad = sqrt(expr);
				if(rad * rad == expr)
				{
					if(cautbin(s, n, rad))
					{
						k++;
					}
				}
			}
		}
		return k;
	}
}