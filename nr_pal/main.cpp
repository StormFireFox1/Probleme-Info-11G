#include <fstream>

using namespace std;

ifstream fin("nr_pal.in");
ofstream fout("nr_pal.out");

/* "nr_pal"
 *
 * Se dau n întrebări de forma: "Câte palindroame există în intervalul [a, b]?", unde a și b sunt numere naturale date, cu a ≤ b. 
 * 
 * Nu se poate face verificarea unul câte unul, deoarece sunt posibil 1,000,000,000 de cifre, deci dă un TLE foarte mare.
 * Se rezolva reducând complexitatea la O(log2(n) * log(n)).
 * 
 * Fie k un număr palindrom cu n cifre, atunci se poate forma un alt număr palindrom de 2n cifre sau de 2n - 1 cifre.
 * ex: 135 -> 13531 sau 135531 
 * 
 * Deci, pentru fiecare număr palindrom inițial, avem încă 2 numere palindroame.
 * Folosind o căutare binară, putem reduce căutarea numerelor palindroame la timp logaritmic.
 * După aceea, se face cu sume parțiale.
 */

int palimpar(int n) {
    int r = n / 10;
    do {
        r = r * 10 + n % 10;
        n /= 10;
    } while (n != 0);
    return r;
}

int palpar(int n) {
    int r = n;
    do {
        r = r * 10 + n % 10;
        n /= 10;
    } while (n != 0);
    return r;
}

int cautbin1(int x) {
    int pas = 1 << 16;
    int r = 0;
    while (pas != 0) {
        if (palimpar(r + pas) <= x) {
            r += pas;
        }
        pas /= 2;
    }
    return r;
}

int cautbin2(int x) {
    int pas = 1 << 13;
    int r = 0;
    while (pas != 0) {
        if (palpar(r + pas) <= x) {
            r += pas;
        }
        pas /= 2;
    }
    return r;
}

int main() {
    int a, b, n;
    fin >> n;
    for (int i = 1; i <= n; i++) {
        fin >> a >> b;
        if (a == 0) {
            fout << cautbin1(b) + cautbin2(b) - cautbin1(0) - cautbin2(0) + 1 << '\n';
        } else {
            fout << cautbin1(b) + cautbin2(b) - cautbin1(a - 1) - cautbin2(a - 1) << '\n';
        }
    }
    return 0;
}