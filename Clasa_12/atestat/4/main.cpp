#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("date.in");

int s1(int k) {
    int max = -1;
    while (k != 0) {
        if (k % 10 > max) {
            max = k % 10;
        }
        k /= 10;
    }
    return max;
}

int s2(int k, int c) {
    int newNumberInverse = 0;
    while (k != 0) {
        if (k % 10 == c) {
            continue;
        } else {
            newNumberInverse = newNumberInverse * 10 + k % 10;
        }
        k /= 10;
    }
    int newNumber = 0;
    while (newNumberInverse != 0) {
        newNumber = newNumber * 10 + newNumberInverse % 10;
        newNumberInverse /= 10;
    }
    return newNumber;
}

int main() {
    int x;
    while (fin >> x) {
        // code here
        int out = 0;
        while (x != 0) {
            int c = s1(x);
            out = out * 10 + c;
            x = s2(x, c);
        }
        cout << out << " ";
    }
    return 0;
}