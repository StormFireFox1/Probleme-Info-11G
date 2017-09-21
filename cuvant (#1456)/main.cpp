#include <iostream>
#include <cstring>

using namespace std;

int main()
{
 	char c[1001];
    int ok = 1, ok2 = 0;
    cin.getline(c, 1001);
    for(int i = 0; i < strlen(c); i++)
    {
     	if(strchr("aeou", c[i])) ok = 0;
        if(strchr("bcdfghjklmnpqrstvwxyz", c[i])) ok2 = 1;
    }
    if(ok2 == 0)
        ok = 0;
    if(ok == 0)
    {
     	cout << "NU";
    }
    else
    {
     	cout << "DA";
    }
    return 0;
}
