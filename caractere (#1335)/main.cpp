#include <cstring>
#include <iostream>

using namespace std;


int main()
{
	char c[256], s[256];
    cin.getline(c, 256);
    cin.getline(s, 256);
    int l1 = strlen(c), l2 = strlen(s);
    for(int i = 0; i < l1; i++)
    {
     	for(int j = 0; j < l2; j++)
        {
         	if(c[i] == s[j])
            {
                cout << s[j];
                break;
            }
        }
    }
    return 0;
}
