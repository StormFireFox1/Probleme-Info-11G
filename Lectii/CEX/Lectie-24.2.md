##Puteri3 (infoarena)

**_1^k + 2^k + ... + n^k_**

**a^k** = nr de șiruri de lungime **k** dintr-un alfabet de cardinal **a**

**Dp**(**i**, **j**) = numărul de șiruri de lungime **i** cu **j** caractere distincte

Dp(i, j) = j * Dp(i - 1, j) + Dp(i - 1, j - 1)

***Combinari de n luate cate k = (N, K)***

N^k = (N, 1) * Dp(k, 1) + (N, 2) * Dp(k, 2) + (N, 3) * Dp(k, 3) + ... + (N, K) * Dp(k, k)

Sum[j = 1, k] (Dp(k, j) * (N + 1, j + 1) * j!) = numărul de caractere distincte din șir

---

##Numar random:

```cpp
inline int RandomInt(int l, int r) {
    return l + (static_cast<long long>(rand()) * RAND_MAX + rand()) % (r - l + 1));
}
```

##Numerele cu precizie fixă:

```cpp
fout.precision(15);
fout.setf(ios::fixed, ios::floatfield);

fprintf(fout, "%.15f\n", number);
```

[PowerPoint-ul conține restul de informații din primele 2 ore]

#Grafuri

Grafuri sunt o metodă de reprezentare a unor date ce pot fi reprezentate prin noduri și muchii.

Sunt 4 algoritmi de căutare a căii prin grafuri:

- Djikistra (de la un nod fixat la restul de noduri)
- Floyd-Warshall / Roy-Warshall / Roy-Floyd (de la orice nod la oricare alt nod)
- Bellman - Kalebo (de la oricare nod la un nod fixat)
- Danzig (de la un nod fixat la un alt nod fixat)

