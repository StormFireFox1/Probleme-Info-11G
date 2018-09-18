#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("countsub.in");
ofstream fout("countsub.out");

const int M = 1001;

int nd[M], val[M], st[M], dr[M], nr[M], r[M];

void dfs(int nod)
{
  nr[nod] ++;

  if(st[nod])
  {
    dfs(st[nod]);
    nr[nod] += nr[st[nod]];
  }

  if(dr[nod])
  {
    dfs(dr[nod]);
    nr[nod] += nr[dr[nod]];
  }
}
int main() {
    
   int i, n, k, rad;

   fin >> n;

   for(i = 1; i <= n; i++)
   {
       fin >> val[i] >> st[i] >> dr[i];

       r[st[i]]++;
       r[dr[i]]++;
   }
   

    fin >> k;

    for(i = 1; i <= k; i++)
      fin >> nd[i];

    for(i = 1; i <= n; i++)
      if(r[i] == 0) rad = i;

    dfs(rad);

    for(i = 1; i <= k; i++)
      fout << nr[nd[i]] << '\n';
    

}