#include <fstream>
#define NMAX 100001
using namespace std;

ifstream fin("jocul.in");
ofstream fout("jocul.out");

/** "Jocul"
 * 
 *  Problema rucsac, cu o mică modificare.
 *  În esență, trebuie să facem un rucsac în care pur și simplu verificăm dacă se poate face un grup de lungime specifică,
 *  până în lungimea tuturor bețișoarelor / 2.
 */

int N,       // numărul de bețișoare
    lungime, // lungimea maximă posibilă cu toate bețișoarele
    isImpar,   // dacă numărul este par
    l[NMAX], // lungimea fiecărui bețișor
    p[NMAX]; // dinamica, dacă se poate face un grup de lungime i de bețișoare

int main() {
    fin >> N;
    for (int i = 1; i <= N; i++) {
        fin >> l[i];
        lungime += l[i];
    }
    if (lungime % 2 == 1) { // dacă lungimea maximă e impară, trebuie adăugat un 1 mai târziu, să compensăm că îl rotunjește C++
        isImpar = 1;
    }
    lungime /= 2;
    for (int i = 1; i <= lungime; i++) {
        p[i] = -1;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = lungime - l[i]; j >= 0; j--) {
            if (p[j] != -1) {
                p[j + l[i]] = 1;
            }
        }
    }

    for (int i = lungime; i > 0; i--) {
        if (p[i] == 1) {
            fout << i << " " << 2 * lungime - i + isImpar;
            break;
        }
    }
    return 0;
}