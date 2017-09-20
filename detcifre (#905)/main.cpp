void detcifre(long long n, int &p, int &u)
{
	u = n % 10;
    while(n / 10 != 0)
    	n /= 10;
    p = n % 10;
}