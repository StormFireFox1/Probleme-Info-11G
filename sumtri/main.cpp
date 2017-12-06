#include <fstream>

using namespace std;

int m[101][101];

int main()
{
    int n, i, j;
    ifstream fin("sumtri.in");
    ofstream fout("sumtri.out");
    fin >> n;
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= i; ++j)
        {
            fin >> m[i][j];
        }
    }
    for (i = n - 1; i >= 1; --i)
    {
        for (j = 1; j <= i; ++j)
        {
            if (m[i + 1][j] > m[i + 1][j + 1])
            {
                m[i][j] += m[i + 1][j];
            }
            else
            {
                m[i][j] += m[i + 1][j + 1];
            }
        }
    }
    fout << m[1][1];
    return 0;
}
