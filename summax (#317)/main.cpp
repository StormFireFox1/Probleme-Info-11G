#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("summax.in");
ofstream fout("summax.out");

int sol[20], mat[20][20], maxim=0, n;
bool c[21];

    void afisare()
    {
        int i, sum=0;
        for(i=1; i<=n; i++)
            sum+=mat[i][sol[i]];
        maxim=max(maxim, sum);
    }

    void back(int p)
    {
        int i;
        if(p-1==n)
        {
            afisare();
            return;
        }

        for(i=1; i<=n; i++)
        {

            if(!c[i])
            {
                c[i]=true;
                sol[p]=i;
                back(p+1);
                c[i]=false;
            }
        }
    }

int main() {

      fin>>n;
      int i, j;
      for(i=1; i<=n; i++)
      {
          for(j=1; j<=n; j++)
          {
              fin>>mat[i][j];
          }
      }
      back(1);
      fout<<maxim;

      return 0;
}