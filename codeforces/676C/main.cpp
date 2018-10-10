#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long long n, m;
string s;

long long checkLetters(char x) {
    long long i, j = 0, count = 0, sol = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == x) {
            count++;
        }

        while (count > m) {
            if (s[j++] == x) {
                count--;
            }
        }

        sol = max(sol, i - j + 1);
    }
    return sol;
}

int main() {
    cin >> n >> m;
    cin >> s;
    cout << max(checkLetters('a'), checkLetters('b')) << "\n";
    return 0;
}