void dublare1(int &n)
{
 	int v[10], i, len = 0;
    for(i = 0; i < 9; i++)
        v[i] = -1;
    i = 0;
    int x = n;
    while(x)
    {
      x /= 10;
      len++;
    }
    for(int i = 0; i < len; i++)
    {
      v[i] = n % 10;
      n /= 10;
    }
    v[len] = v[len - 1];
    n = 0;
    for(i = len; i >= 0; i--)
      n = n * 10 + v[i];
}