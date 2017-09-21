#include <iostream>
#include <fstream>
#include <cstring>

int main()
{
    char c[101];
    int flag = 1;
    int _count = 0;
    std::cin >> c;
    for (int i = 0 ; i < strlen(c) ; ++i)
    {
        if (c[i] == 'a' || c[i] == 'e' || c[i] == 'o' || c[i] == 'u')
        {
            flag = 0;
            break;
        }
        if (c[i] != 'a' && c[i] != 'e' && c[i] != 'i' && c[i] != 'o' && c[i] != 'u')
            _count++;
    }
    if (flag && _count)
    {
        std::cout << "DA";
    }
    else
        std::cout << "NU";
    return 0;
}
