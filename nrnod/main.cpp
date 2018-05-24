#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("nrnod.in");
ofstream fout("nrnod.out");

int st[5001], dr[5001], v[5001], nr;

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

int main() {
  
  int i, rad, k = 0;

  rad = dfs();

  for(i = 1; i <= nr; i++)
  {
    if(st[i] == 0 && dr[i] != 0) k++;

    if(st[i] != 0 && dr[i] == 0) k++;
  }

  fout << k;
 
 return 0; 
}