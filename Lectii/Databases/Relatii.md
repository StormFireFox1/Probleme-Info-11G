## Relații

Relațiile sunt folosite pentru a lega două entități împreună.

Relațiile au anumite caracteristici:
- nume (de obicei un verb)
- opționalitatea - poate / trebuie
- cardinalitatea / gradul: 1-1, 1-n, n-n


### Exemple de relații
```

┌────────────┐                          ┌─────────────┐
|            |\ joacă           joacă   |             |
│   Echipă   ├─ ─ ─ ─ ─ ─ ─ ─ ──────────┤   Jucător   │
│            │/ poate          trebuie  |             │
└────────────┘                          └─────────────┘

┌───────────┐                                              ┌─────────────┐
|           |\ joacă        ┌───────────┐          joacă  /|             |
│   Actor   ├─ ─ ─ ─ ─ ─ ─ ─┤   Scenă   ├─ ─ ─ ─ ──────────┤    Piesă    │
│           │/ poate        └───────────┘         trebuie \|             │
└───────────┘                                              └─────────────┘

```

### Exerciții relații

Subiecte Atestat, exercitiul 1.
a) 
```
┌─────────────────┐     ┌──────────────────┐                 ┌──────────────────┐
│      Clasă      │     │     Profesor     │                /│     Încadrare    │
│                 │     │                  ├─────── ─ ─ ─ ─ ─┤                  │
│  # nivel        │     │  * nume          │                \│  * Număr ore     │
│  # literă       │     │  * disciplina    │                 │  * disciplină    │
│  # specializare │     │  # ID            │                 └──────────────────┘
│  * sală         │     │  * disciplina II │  
└─────────────────┘     └──────────────────┘  

```