#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>

int cuvinte1(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u')
            return (0);
        i++;
    }
    return (1);
}

int main()
{
    char str[255], tok[] = ",.? ";
    char *p;
    std::cin.get(str, 255);
    p = strtok(str, tok);
    while (p)
    {
        if (cuvinte1(p))
            std::cout << p << '\n';
        p = strtok(NULL, tok);
    }
    return (0);
}
