#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>

int main()
{
    char s1[101];
    int i = 0;
    std::cin.get(s1, 101);
    while (s1[i])
    {
        if (strchr(" ;.,'?1234567890", s1[i]) == 0)
            std::cout << s1[i];
        i++;
    }
    return 0;
}
