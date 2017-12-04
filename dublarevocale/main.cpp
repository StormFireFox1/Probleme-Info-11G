#include <cstring>
#include <iostream>

using namespace std;


int main()
{
	char c[101], voc[] = "aeiou";
    cin.getline(c, 100);
    int l = strlen(c);
    for(int i = 0; i < l; i++)
    {
        cout << c[i];
        if(strchr(voc, c[i]))
        {
            cout << c[i];
        }
    }
    return 0;
}
