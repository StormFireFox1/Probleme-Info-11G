#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

ifstream fin("binefrunze1.in");
ofstream fout("binefrunze1.out");

int st[5001], dr[5001], v[5001], nr, s[5001];

int dfs()
{
  int x;

  fin >> x;

  if(x == 0) return 0;

  v[++nr] = x;
  int aux = nr;

  st[aux] = dfs();
  dr[aux] = dfs();

  return aux;
}

int main()
{
    int r, k = 0;

    r  = dfs();

    for(int i = 1; i <= nr; i++)
    {
      if(st[i] || dr[i]) s[++k] = v[i];
    }

    sort(s + 1, s + k + 1);

    for(int i = k; i > 0; i--)
        fout << s[i] << ' ';

    return 0;
}
