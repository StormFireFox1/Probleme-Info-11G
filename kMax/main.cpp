#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
 	int n, v[1000], k;
    long long sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
     	cin >> v[i];
    }
    cin >> k;
    sort(v, v + n);
    for(int i = 0; i < k; i++)
    {
         v[i] = -v[i];
    }
    for(int i = 0; i < n; i++)
    {
     	 sum += v[i];  
    }
    cout << sum;
    return 0;
}