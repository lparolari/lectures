Implementiamo una serie di operazioni su array, e vogliamo farlo scrivendo meno codice possibile.

Supponiamo di avere un array `A` di `4` elementi.

```
A = [1, 2, 3, 4, ]
```

Vogliamo calcolare `2*A`, ovvero un array `B` contenente il doppio
dei di ogni elemento.

    B = [2, 4, 6, 8, ]

Va bene, possiamo scrivere una semplice funzione che, per ogni elmento `a` di `A`, inserisce nell'array `B` il doppio di `a`, ovvero `2*a`

```cpp
vector<int> doppio(vector<int> A) {
    vector<int> B;

    for (auto a: A) {
        B.push_back(a * 2);
    }

    return B;
}
```

Vogliamo ora calcolare anche `3*A`.
Okay, questo è relativamente semplice e lo possiamo fare modificando la funzione precedente che abbiamo appena scritto aggiungendo un parametro.

```cpp
vector<int> moltiplica(vector<int> A, int m) {
    vector<int> B;

    for (auto a: A) {
        B.push_back(a * m);
    }

    return B;
}
```

E se ora volessimo calcolare invece `3+A`, ovvero un array `C` come il seguente contenente non più il tripo degli elementi di `A` ma gli elementi più 3?

    C = [5, 7, 9, 11, ]

Mmmh... dovremmo scrivere un'altra funzione?
Okay, facciamolo.

```cpp
vector<int> somma(vector<int> A, int x) {
    vector<int> B;

    for (auto a: A) {
        B.push_back(a * m);
    }

    return B;
}
```

A questo punto abbiamo `moltiplica` e `somma`, che adempiono a funzioni diverse ma abbastanza parametrizzate da coprire tutti i casi di loro competenza.

E se a questo punto volessimo calcolare la funzione potenza di 2 dell'array `A`?

Dovremmo scrivere un'altra funzione... Che noia! 

Facciamolo, ma parametrizziamola subito di modo da non dover poi scrivere altre funzioni!

```cpp
#include <cmath>

vector<int> pow2(vector<int> A, int x) {
    vector<int> B;

    for (auto a: A) {
        B.push_back(std::pow(a, x));
    }

    return B;
}
```

Riguardiamo ora tutte le funzioni implementate. Cosa cambia tra queste?

Quasi nulla! Più del 90% del codice scritto è lo stesso per tutte e tre le funzioni, cambia solo l'operazione da fare su ogni elemento.

Ma... e se prendessimo in input proprio la funzione da applicare ai valori?

```cpp
vector<int> trasforma(vector<int> A, ??? func) {
    vector<int> B;

    for (auto a: A) {
        B.push_back(func(a));
    }

    return B;
}
```

Ci manca qualcosa. Innanzitutto qual è il tipo di una funzione? Una funzione è identificata dal tipo di ritorno e dal tipo e numero dei suoi parametri. Wait, ma le funzioni sono codice. Come facciamo a passare del codice in input ad una funzione?  

Mmmh, passiamo il nome no? Ah! Un puntatore!

Proviamo

```cpp
vector<int> trasforma(vector<int> A, int (*func)(int)) {
    vector<int> B;

    for (auto a: A) {
        B.push_back(func(a));
    }

    return B;
}
```

Okay, ma come chiamiamo `trasforma`?

```cpp
vector<int> A = {1, 2, 3, 4};
vector<int> B;

B = trasforma(A, ???)
```

Dobbiamo passare una funzione che prende un `int` e restituisce un `int`.

```cpp
int doub(int x) {
    return x * 2;
}

B = trasforma(A, doub)
```

Cosa abbiamo guadagnato?

Abbiamo generalizzato l'algoritmo per scorrere l'array, indipendentemente dal fatto che questo sia veramente un array o meno. Trasformiamo collezioni! L'utente ora può preoccuparsi solo di costruire la funzione che lavora sul singolo elemento!

```cpp
#include <cmath>

int pow2(int x) {
    return std::pow(x, 2);
}

B = trasforma(A, doub)
```
