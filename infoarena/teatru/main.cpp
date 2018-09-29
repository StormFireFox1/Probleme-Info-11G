#include <fstream>
#include <string>

#define C_MAX 26

using namespace std;

string stagiune;
int frecventaCostume[C_MAX];

/* Teatru
 * 
 * Problema cu subsecvente "2 pointers".
 * 
 * In esenta, este comparabila cu problema 279B de pe CodeForces, doar ca in cazul acesta avem alte conditii de invalidare a subsecventei.
 * In acest caz, nu vrem ca secventa sa aibe mai mult decat *c* costume diferite.
 */

ifstream fin("teatru.in");
ofstream fout("teatru.out");

int main()
{
    int nrZile, nrCostume;
    fin >> nrZile >> nrCostume;
    fin >> stagiune;
    int i = 0, j = 0;
    int nrCostumeDiferite = 0;
    int lmax = 0;
    int inceputSubsecventa = 0;
    for (i = 0; i < nrZile; i++)
    {
        frecventaCostume[stagiune[i] - 'A']++;
        if (frecventaCostume[stagiune[i] - 'A'] == 1)
        {
            nrCostumeDiferite++;
        }
        while (j <= i && nrCostumeDiferite > nrCostume)
        {
            frecventaCostume[stagiune[j] - 'A']--;
            if (frecventaCostume[stagiune[j] - 'A'] == 0)
            {
                nrCostumeDiferite--;
            }
            j++;
        }
        if (i - j + 1 > lmax)
        {
            lmax = i - j + 1;
            inceputSubsecventa = j;
        }
    }
    fout << lmax << "\n";
    for (i = inceputSubsecventa; i < inceputSubsecventa + lmax; i++)
    {
        fout << stagiune[i];
    }
    return 0;
}