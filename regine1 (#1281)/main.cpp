/* regine1
   O problema efectiva de backtracking. Ideea in mod principal a problemei este ca nu se citeste ca o matrice! Nici nu se
   memoreaza una. De fapt, in problema, se retine doar pozitia reginei pe un rand al matricei.
   
   v[i] = j;
   unde i este randul din "matrice", iar j este pozitia reginei pe rand.
   Dupa aceea, metoda de validare este interesanta. Daca:
   |v[i] - v[k]| = |i - k|
   atunci doua regine se pot ataca una pe cealalta.
   exemplu: daca regina 1 se afla pe pozitia 1,1 iar regina 2 se afla pe pozitia 3,3, atunci:
   |v[1] - v[3]| = |1 - 3|
   |1 - 3| = |1 - 3| Adevarat

   Se implementeaza aceasta conditie de verificare. De asemenea, trebuie verificat si daca nu am pus o regina pe rand deja.
   O alta problema este ca algoritmul fara pointer la afisare va provoca probleme la afisare (va arata TOATE mesele posibile)
   Noua ne trebuie doar una, deci vom afisa DOAR una.
   
   Daca nu s-a inteles, dati mesaj si explic.

   -Matei Gardus
*/

#include <iostream>
#include <cmath>

using namespace std;

int v[11], k, n, t;

void afis(int &t)
{
    int i, j;
    for(i = 1; i <= n; i++)
    {
	for(j = 1; j <= n; j++)
        {
	    if(v[i] == j)
		cout << "* ";
            else
		cout << "- ";
        }
	cout << endl;
    }
    t++;
}
int valid(int k)
{
    int i;
    for(i = 1; i < k; i++)
    {
	if(v[i] == v[k])
	    return 0;
        if(abs(v[i] - v[k]) == abs(i - k)) //conditia de verificare pentru atacul reginelor
	    return 0;
    }
    return 1;
}
void backtrack(int k)
{
    if(k == n + 1 && t == 0)
    {
	afis(t);
    }
    else
    {
        for(int i = 1; i <= n; i++)
        {
	    v[k] = i;
            if(valid(k))
		backtrack(k + 1);
        }
    }
}
int main()
{
    cin>>n;
    backtrack(1);
    return 0;
}
