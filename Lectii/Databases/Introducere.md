# Baze de date
## Introducere

Bazele de date sunt un domeniu al informaticii.
Toate acestea sunt mentinute de catre un **S**istem de **G**estionare a **B**azelor de **D**ate (SGBD sau DBMS in engleză).
Limbajul prin care se comunică cu bazele de date se numește SQL (**S**tructured **Q**uery **L**anguage).

Access, Oracle sunt două SGBD-uri.

Bazele de date se găsesc cel mai des în bussines-uri, cu scopul de a își menține date despre contabilitate, clienți, user experience, etc.
Pentru a avea o bază de date, avem nevoie de informație. Această informație se poate culege din documentele firmei.
Datele pot fi grupate în **entități** cu **atribute** și **relații**. De obicei datele sunt reprezentate în mod grafic, prin E.R.D (**E**ntity **R**elationship **D**iagram).

### Exemple de date

```
[elev]────<studiază>───[curs]
│                      │
├─── {clasa}           ├───{nume}
├─── {nume}            └───{nivel}
└─── {prenume}
```

`[ ... ]` - entitate (substantiv)
`{ ... }` - atribut (substantiv sau adjectiv)
`< ... >` - relație (verb)

Atributele pot fi opționale (notat cu un cerc °) sau obligatorii (notate cu o steluță *).

## ID

Un set de date se numește *instanță*. Orice *instanță* trebuie să aibe un identificator (un ID), notat în diagramă cu `#`. De obicei un ID este un atribut.

### Exemple de ID

```
┌────────────┐
│   Abonat   │
│            │
│  # nume    │
│  # prenume │
│  # telefon │
│  * dataInc │
│  * tip     │
│  . . . . . │
└────────────┘
```

