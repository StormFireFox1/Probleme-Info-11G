void aranjare(int v[], int n)
{
	int impar[10000], par[10000], i = 0, j = 0;
    for(int k = 0; k < n; k++)
    {
     	if(v[k] % 2 == 0)
        {
            par[i] = v[k];
            i++;
        }
        else
        {
         	impar[j] = v[k];
            j++;
        }
    }
    int bi = i, bj = j;
    i = 0;
    for(int x = 0; x < bj; x++)
    {
     	  v[x] = impar[i];
        i++;
    }
    j = 0;
    for(int x = 0; x < bi; x++)
    {
        v[i + x] = par[j];
        j++;
    }
}