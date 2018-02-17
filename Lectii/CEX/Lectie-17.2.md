# Păduri de mulțimi disjuncte

Pădurile pot suporta 2 feluri de operații:
1. Unim 2 set-uri X, Y
2. spunem că X și Y fac parte din același set

1 ... N: inițial p(i) = părintele lui i

p(i) = 1 oricare i care face parte din [1, N]

v(i) = Setul valorilor din componenta lui i

```
Root(i): (funcție care află părintele unei componente)
    cât timp p(i) != i
        i <- p(i)
        

Root(x) == Root(y)
    nu facem nimic
Dacă nu
    p(Root(y)) = Root(x)
    mutăm toate elementele din v(root(y)) în v(root(x))
```

**Complexitate: O(n^2)**

Pentru a optimiza un pic, putem folosi 2 euristici:

### Compresia căii

```
Root(i):
    dacă p(i) = i
        return
    altfel
        return p(i) <- Root(p(i))
```

### Înălțime (rank)

```
Union(x, y):
    xRoot <- Root(x)
    yRoot <- Root(y)
    dacă xRoot != yRoot
        dacă rankX < rankY
            p(xRoot) <- yRoot
    altfel
        dacă rankY < rankX
            p(yRoot) <- xRoot
        altfel dacă rankX == rankY
            p(xRoot) <- yRoot
            rankYRoot <- rankYRoot + 1
```

N valori întregi pozitive  -> A

i - 1 ... N

Să zicem care e prima poziție la stânga pentru care A[j] < A[i], j < i

Adaugi în stivă numărul cel mai mic. Apoi, la următorul, scoți numerele mai mari decât cel pe care vrei
să inserezi în stivă, după aceea îl bagi și scoți afară pe ce poziție se află numărul din stânga (sub
cel de acum în stivă).

_[Skyline de pe Varena](http://varena.ro/problema/skyline)_

---

## Range minimum query

_[infoarena](http://infoarena.ro/problema/rmq)_

Dinamică.

```
t[i][j] = min(Aj, Aj+1, ... , Aj+2^i-1)

t[0][i] = A[i]

Query(x, y):
    l <- log2(y - x + 1)
    min(t[l][x], t[l][y - 2^l + 1]
```

Păduri.

```
stk <- {0}
pentru i <- 1, N
    cât timp stk nu e vidă && A[stk.top()] > A[i]
        A[i] <- stk.top(), i
    stk.push_back(i)
    pentru fiecare capăt stânga în list[i]
        rq <- Root(Stânga)
```