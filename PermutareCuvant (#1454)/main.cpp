#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <fstream>

int main()
{
    char s1[21];
    std::ifstream in_file ("permutarecuvant.in");
    std::ofstream out_file ("permutarecuvant.out");
    in_file.get(s1, 21);
    for (int i = 0 ; i < strlen(s1) ; ++i)
    {
        for (int j = i ; j < strlen(s1) + i ; ++j)
        {
            out_file << s1[j % strlen(s1)];
        }
        out_file << ' ';
    }
    return 0;
}
