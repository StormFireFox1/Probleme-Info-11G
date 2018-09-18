#include <bits/stdc++.h>
using namespace std;

ifstream fin("bifrunze.in");
ofstream fout("bifrunze.out");

int x, st[1001], dr[1001];

int main() {
   int n, i;
   
   fin >> n;
   
   for(i = 1; i <= n; i++)
     fin >> x >> st[i] >> dr[i];
     
    for(i = 1; i <= n; i++)
      {
        if(st[i] == 0 && dr[i] == 0) fout << i << ' ';
      }
  return 0;    
}