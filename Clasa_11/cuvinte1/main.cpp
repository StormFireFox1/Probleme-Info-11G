#include <cstring>
#include <iostream>

using namespace std;


int main()
{
	char c[256], *p, con[] = "bcdfghjklmnpqrstvwxyz";
    cin.getline(c, 256);
    p = strtok(c, " ");
    int ok = 1;
    while(p)
    {
        ok = 1;
     	int slen = strlen(p);
        for(int j = 0; j < slen && ok == 1; j++)
        {
         	if(strchr(con, p[j]))
            {
             	ok = 0;
            }
        }
        if(ok == 1)
        {
        	cout << p << "\n";
        }
        p = strtok(NULL, " ");
    }
    return 0;
}
