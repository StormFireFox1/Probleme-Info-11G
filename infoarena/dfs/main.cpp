#include <fstream>
#include <vector>

using namespace std;

ifstream fin("dfs.in");
ofstream fout("dfs.out");

/* DFS
 *
 * Aceasta este parcurgerea DFS simpla. Problema in sine numără numărul de componente conexe.
 * 
 * Găsiți detalii pe Wikipedia și TopCoder. https://www.topcoder.com/community/competitive-programming/tutorials/introduction-to-graphs-and-their-data-structures-section-2/ 
 */

int n,                      // numărul de noduri
    m,                      // numărul de muchii
    nrComponente = 0,       // numărul de componente conexe
    vizitat[100001];        // vectorul de vizitare (vizitat[x] = numarul componentei conexe din care face parte)
vector<int> vecini[100001]; // vectorul de vecini. vecini[x] = vecinii nodului x

void dfs(int nod) {
    vizitat[nod] = nrComponente;
    for(int i = 0; i < vecini[nod].size(); i++) {
        if(vizitat[vecini[nod][i]] == 0) {
            dfs(vecini[nod][i]);
        }
    }
}

int main() {
    int x, y;
    fin >> n >> m;
    for(int i = 1; i <= m; i++) {
        fin >> x >> y;
        vecini[x].push_back(y);
        vecini[y].push_back(x);
    }
    for(int i = 1; i <= n; i++) {
        if (vizitat[i] == 0 ) {
            nrComponente++;
            dfs(i);
        }
    }
    fout << nrComponente;
    return 0;
}