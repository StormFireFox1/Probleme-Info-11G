#include <bits/stdc++.h>

using namespace std;
ifstream fin("intervale2.in");
ofstream fout("intervale2.out");
int n,m,i,j,mx=-10000000,mn=1000000,a,b;
int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a>>b;
        if(mx<a)mx=a;
        if(mn>b)mn=b;
    }
    if(mx<=mn)fout<<mx<<" "<<mn;
    else fout<<0;
    return 0;
}