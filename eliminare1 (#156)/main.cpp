#include <cstring>
#include <iostream>

using namespace std;


int main()
{
	char c[256], s[256];
    cin.getline(c, 256);
    for(int i = 0; c[i]; i++)
    {
        if(strchr("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", c[i]))
            cout << c[i];
    }
    return 0;
}
