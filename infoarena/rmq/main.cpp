#include <fstream>

#define NMAX 1000001
#define LMAX 18

using namespace std;

ifstream fin("rmq.in");
ofstream fout("rmq.out");

int n, m;
int v[NMAX];
int lg[NMAX];
int rmq[LMAX][NMAX];

/** RMQ
 * 
 *  O explicatie foarte buna se poate gasi chiar pe infoarena: https://infoarena.ro/problema/rmq
 * 
 *  Eu personal am inteles de pe acest site: https://www.topcoder.com/community/competitive-programming/tutorials/range-minimum-query-and-lowest-common-ancestor/#Range_Minimum_Query_(RMQ)
 */
int main() {
    int i, j;
    
    fin >> n >> m;

    for (i = 1; i <= n; i++) {
        fin >> rmq[0][i];
    }

    lg[1] = 0;
    for (i = 2; i <= n; i++) {
        lg[i] = lg[i / 2] + 1;
    }

    for (i = 1; (1 << i) <= n; i++) {
        for (j = (1 << i); j <= n; j++) {
            int l = 1 << (i - 1);
            rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j - l]);
        }
    }

    int x, y;
    for (i = 1; i <= m; i++) {
        fin >> x >> y;

        int diferenta = y - x + 1;
        int l = lg[diferenta];
        fout << min(rmq[l][y], rmq[l][x + (1 << l) - 1]) << "\n";
    }

    return 0;
}