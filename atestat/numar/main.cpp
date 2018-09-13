#include <fstream>
#include <iostream>

using namespace std;

ifstream in("numar.in");

void s1(int &a, int &b) {
    b = b * 10 + a % 10;
    a = a / 10;
}

int s2(int a) {
    int a1 = 0;
    while (a > 0) {
        if ((a % 10) % 2 == 1)
            a1 = a1 * 10 + a % 10;
        a = a / 10;
    }
    while (a1 > 0) {
        s1(a1, a);
    }
    return a;
}

int main() {
    int n, cn, cn2;
    in >> n;
    cn = s2(n);
    cn2 = cn;
    n = cn;
    while (cn > 0) {
        s1(cn, n);
    }
    n == cn2 ? cout << "DA" : cout << "NU";
    return 0;
}