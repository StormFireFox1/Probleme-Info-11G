#include <iostream>

using namespace std;
int n, v[100001], k;

int main()
{
    int i, j;
    cin >> n >> k;
    v[1] = 1;
    for (i = 1; i <= n; i++) {
        if (i <= k) {
            for (j = 1; j <= i - 1; j++) {
                v[i] += v[j];
                v[i] = v[i] % 9001;
            }
        } else {
            for (j = i - k; j <= i - 1; j++) {
                v[i] += v[j];
                v[i] = v[i] % 9001;
            }
        }
    }
    cout << v[n] % 9001;
    return 0;
}