#include <fstream>
#include <vector>
#include <algorithm>
#define NMAX 5001
#define INF 1000000000

using namespace std;

ifstream fin("tricolor.in");
ofstream fout("tricolor.out");

int T,              // numarul de teste din fisierul de intrare
    N,              // numarul de elemente in v
    sol,            // rezultatul pentru fiecare test
    nr[NMAX],       // numar de noduri descendenti al fiecarui nod in parte
    dp[NMAX][NMAX]; // dinamica pe arbore. In general, dp[i][j] = numarul de noduri albe conectate din arbore cu radacina i si j descendenti

vector<int> v[NMAX];

void dfs(int nod, int parinte)
{
    int i,
        j,
        sum = 0,
        partSum = 0,
        k = 0;
    for (auto vecin : v[nod])
    {
        if (vecin == parinte) {
            continue;
        }
	
        dfs(vecin, nod);
        nr[nod] += nr[vecin];

        for (i = k; i >= 0; i--) {
            for (j = 0; j <= nr[vecin]; j++) {
                dp[nod][i + j] = max(dp[nod][i + j], dp[nod][i] + dp[vecin][j] + i * j);
            }
        }

	    k += nr[vecin];
        partSum = 0;
        
        for (i = 0; i <= nr[vecin]; i++) {
            partSum = max(partSum, dp[vecin][i] + i);	
        }

        sum += partSum;	
    }
	
    if (v[nod].size() == 1)
        nr[nod] = 1;
	
    dp[nod][1] = sum;
}

int main()
{
  fin >> T;	
  for(int x = 1; x <= T; x++) {
    fin >> N;
    for(int i = 1; i < N; i++) {
      int x, y;
      fin >> x >> y;
	
      v[x].push_back(y);
      v[y].push_back(x);
    }
    dfs(1, 0);
    sol = 0;
	
    for(int i = 0; i <= N; i++) {
      sol = max(sol, dp[1][i]);
    }

    fout << sol << "\n";	
    for(int i = 1; i <= N; i++)
      v[i].clear();

  }

  return 0;	
}