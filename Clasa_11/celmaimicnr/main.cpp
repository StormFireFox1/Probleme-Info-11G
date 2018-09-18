int cmmnr(int n)
{
	int v[10], i;
    for(i = 0; i <= 9; i++)
    {
     	v[i] = 0;  
    }
    while(n)
    {
        v[n % 10]++;
        n /= 10;
    }
    i = 1;
    while(i <= 9)
    {
      if(v[i] != 0)
        break;
      i++;
    }
    int sol = 0;
    sol = sol * 10 + i;
    v[i]--;
    while(v[0] != 0)
    {
        sol = sol * 10 + 0;
        v[0]--;
    }
    for(i; i <= 9; i++)
    {
        while(v[i] != 0)
        {
         	sol = sol * 10 + i;
            v[i]--;
        }
    }
    return sol;
}