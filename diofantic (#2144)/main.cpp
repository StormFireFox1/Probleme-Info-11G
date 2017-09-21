long long diofantic(int n, int s[], int a, int b, int c)
{
    int x=1, y=2, l=0, k=0;
    long long nr=0;
    for(x=1; x<n; x++)
    {
        if (s[x]>=0)
        {
            l=c-(long long)(a*s[x]*s[x]);
            for(y=x+1; y<=n; y++)
                if (s[x]!=s[y] && s[y]>=0)
                {
                    k=(long long)(b*s[y]*s[y]);
                    if(l==k) nr=nr+2;
                    else if(k>l)
                    {
                        n--;
                        y=n;
                    }
                }
                else s[y]=-1;
        }
    }
    return nr;
}