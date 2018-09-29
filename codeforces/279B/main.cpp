#include <iostream>
#include <algorithm>

using namespace std;

/* Books
 *
 * Problema cu subsceventa "2-pointers".
 * 
 * In esenta, cand construim vectorul de carti, noi il parcurgem cu doi vectori astfel incat sa gasim subsecventa de suma maxim a acestuia.
 * Motivul pentru care este eficient este pentru ca este O(n) amortizat, deoarece j nu va fi niciodata mai mare decat i cand iteram peste vector.
 */

int v[100000];

int main() {
    int n, t;
    cin >> n >> t;
    int i = 0, j = 0;
    int lmax = 0;
    int s = 0;
    for (i = 0; i < n; i++) {
        cin >> v[i];
        s += v[i];
        while (j <= i && s > t) { // secventa de la j la i NU e buna
            s -= v[j];
            j++;
        }
        if (i - j + 1 > lmax) {
            lmax = i - j + 1;
        }
    }
    cout << lmax;
    return 0;
}