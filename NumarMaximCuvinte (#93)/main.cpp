#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <fstream>

int word_count(char *str)
{
    char *p;
    char cpy[255];
    strcpy(cpy, str);
    int _count = 0;
    p = strtok(str, " .,!?;");
    while (p)
    {
        _count++;
        p = strtok(NULL, " .,!?;");
    }
    strcpy(str, cpy);
    return (_count);
}

int main()
{
    std::ifstream in_file ("cuvmax.in");
    std::ofstream out_file ("cuvmax.out");
    int n;
    char **mat;
    char str[255];
    int _count = 0;

    in_file >> n;
    in_file.get();

    mat = new char*[n + 1];
    for (int i = 0 ; i < n ; ++i)
    {
        mat[i] = new char[255];
        in_file.getline(mat[i], 255);
    }

    for (int i = 0 ; i < n ; ++i)
    {
        int words = word_count(mat[i]);
        if (words > _count)
        {
            _count = words;
            strcpy(str, mat[i]);
        }
    }
    out_file << str;
    return 0;
}
