#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int ok1=0,  ok2=0,i, len;
    char sir[1001];
    cin>>sir;
    len=strlen(sir);
    for(i=0;i<len;i++)
    {
     	if(strchr("aeou",sir[i]))ok1++;
        if(sir[i]=='i') ok2++;
    }

    if(ok1!=0)cout<<"NU";
           else if(ok2==len) cout<<"NU";
           else cout<<"DA";
           return 0;
}