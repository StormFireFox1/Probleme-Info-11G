#include <bits/stdc++.h>
using namespace std;
ifstream fin("knivel1.in");
ofstream fout("knivel1.out");

int nivele[1001], s[1001], d[1001], p[1001], n, v[1001], nr;

void nivel(int k, int niv)
{
  if(k)
  {
    nivele[k] = niv;

    nivel(s[k], niv + 1);
    nivel(d[k], niv + 1);
  }
}

int dfs()
{
  int x;

  fin >> x;

  if(x == 0) return 0;

  v[++nr] = x;
  int aux = nr;

  s[aux] = dfs();
  d[aux] = dfs();

  return aux;
}

int main()
{
    int i, r, k, sum = 0;

    r = dfs();

    fin >> k;

    nivel(r, 0);

    for(i = 1; i <= nr; i++)
    {
      if(nivele[i] == k) sum += v[i];
    }

    fout << sum;

    return 0;
}
