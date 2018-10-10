#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n = 0;
    cin >> n;

    int v[500100];
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }

    if (sum % 3 != 0) { // nu este divizibil cu 3, deci nu se pot face 3 parti
        cout << "0" << "\n";
    } else {
        long long buffer = 0;
        long long sumaParte = sum / 3;
        int pozitie[500100];

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                pozitie[0] = 0;
            } else {
                pozitie[i] = pozitie[i - 1];
            }
            buffer += v[i];
            if (buffer == sumaParte) {
                pozitie[i]++;
            }
        }   

        buffer = 0;
        long long sol = 0;

        for (int i = n - 1; i >= 2; i--) {
            buffer += v[i];
            if (buffer == sumaParte) {
                sol += pozitie[i - 2];
            }
        }

        cout << sol << "\n";
    }
    return 0;
}