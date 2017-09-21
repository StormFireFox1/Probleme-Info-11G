#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>

int main()
{
    char s1[101];
    char s2[201];
    int j = 0;
    std::cin.get(s1, 101);
    for (int i = 0 ; i < strlen (s1) ; ++i)
    {
        s2[j] = s1[i];
        j++;
        if (s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u')
        {
            s2[j] = s1[i];
            j++;
        }
    }
    s2[j] = 0;
    std::cout << s2;
    return 0;
}
