#include <fstream>
#include <cstring>

#define LMAX 500000

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

int s1(char s[]) {
    char v[] = "aeiou";
    int nrConsoane = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (!strchr(v, s[i])) {
            nrConsoane++;
        }
    } 
    return nrConsoane;
}

void s2 (char s[]) {
    char v[] = "aeiou";
    for (int i = 0; i < strlen(s); i++) {
        if (!strchr(v, s[i])) {
            for (int j = strlen(s); j > i; j--) {
                s[j + 1] = s[j];
            }
            i++;
        }
    }
}

int main()
{
    char s[LMAX];
    fin.getline(s, LMAX);
    fout << s1(s);
    s2(s);
    fout << "\n" << s;
    return 0;
}