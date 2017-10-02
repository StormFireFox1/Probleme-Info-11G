#include<bits/stdc++.h>

using namespace std;
ifstream fin("subsecv.in");
ofstream fout("subsecv.out");
int n,m,i,j,s[10001],k,mn=2000000000,a,b;
//vector< pair <int,int> > vect;
int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>m;
        if(i==1)s[i]=m%n;
        else s[i]=(m+s[i-1])%n;
    }
    for(i=1;i<=n;i++)
    {
        j=i+1;
        if(s[i]==0)
        {
            fout<<1<<" "<<i;
            return 0;
        }
    }
    for(i=1;i<=n;i++)
    {
        j=i+1;
        while(s[j]!=s[i]&&j<=n)j++;
        if(s[j]==s[i])
        {
            fout<<i+1<<" "<<j;
            return 0;
        }
    }
    return 0;
}
