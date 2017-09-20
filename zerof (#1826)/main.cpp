int zerof(int n)
{
    if(n == 0)
        return 0;
 	int k = 0;
    for(int i = 1; i <= n; i++)
    {
      if(i % 3125 == 0)
      {
       	k++;   
      }
      if(i % 625 == 0)
      {
       	k++;   
      }
      if(i % 125 == 0)
      {
        k++; 
      }
      if(i % 25 == 0)
      {
        k++; 
      }
      if(i % 5 == 0)
      {
        k++;
      }
    }
    return k;
}