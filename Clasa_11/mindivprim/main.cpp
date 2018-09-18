int minDivPrim(int n)
{
    int div=2,c=0,p=1;
    while(n!=1)
    {
        c=0;
        if(n%div==0)
        {
               while(n%div==0)
               {
                   n/=div;
                   c++;
               }
        }
        if(c!=0) p*=div;
        if(div==2) div++;
        else div+=2;
    }
    return p;
}

