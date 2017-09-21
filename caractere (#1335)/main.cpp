#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>

int main()
{
    char s1[255];
    char s2[255];
    std::cin.get(s1, 255);
    std::cin.get();
    std::cin.get(s2, 255);
    for (int i = 0 ; i < strlen(s1) ; ++i)
    {
        if(strchr(s2, s1[i]))
            std::cout << s1[i];
    }
    return 0;
}
