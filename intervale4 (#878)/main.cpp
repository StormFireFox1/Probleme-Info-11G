#include <bits/stdc++.h>

using namespace std;
ifstream fin("intervale4.in");
ofstream fout("intervale4.out");
int n,m,B,E,b[100001],e[100001],s[100001],d[100001],vf,c,i,j;
bool intersect(int a, int b, int c, int d)
{
    if(b>=c&&a<=d)return true;
    if(d>=a&&c<=b)return true;
    if(c>=a&&d<=b)return true;
    if(a>=c&&b<=d)return true;
    return false;
}
int main()
{
   fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>s[i]>>d[i];
        b[++vf]=s[i];
        e[vf]=d[i];
        while(intersect(b[vf],e[vf],b[vf-1],e[vf-1])&&vf>1)
        {
            if(intersect(b[vf],e[vf],b[vf-1],e[vf-1]))
            {
                B=min(b[vf],b[vf-1]);
                E=max(e[vf],e[vf-1]);
                vf--;
                b[vf]=B;
                e[vf]=E;
            }

        }
    }
    fout<<vf;
    return 0;
}