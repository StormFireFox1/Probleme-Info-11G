#include <fstream>
#include <cstring>

#define LMAX 251

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

int frecventaCifre[10];
char numere[] = "0123456789";

void s1(char s[]) {
    fin.getline(s, LMAX);
}

bool s2(char c, char s[]) {
    for (int i = 0; i < strlen(s); i++) {
        if (c == s[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    char s[LMAX];
    s1(s);
    
}