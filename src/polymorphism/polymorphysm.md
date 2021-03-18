# Polimorfismo

Tra i principali vantaggi dichiarati dal paradigma di programmazione
OOP abbiamo il polimorfismo.

**Def.** Il termine
[polimorfismo](<https://it.wikipedia.org/wiki/Polimorfismo_(informatica)>)
viene usato in senso generico per riferirsi a espressioni che possono
rappresentare valori di diversi tipi.

Essendo un concetto molto genenerale, sono state create due macro
categorie di polimorfismo: statico e dinamico. Come indicato dal nome,
il polimorfismo statico entra in gioco a tempo di compilazione ed è
gestito interamente in questa fase, mentre il polimorfismo dinamico
viene gestito dal runtime a tempo di esecuzione. Prima di vedere
vantaggi e svantaggi dei due e confrontarli, diamo un'occhiata a cosa
sono.

## Polimorfismo dinamico

Una particolare specializzazione del polimorfismo dinamico è
l'ereditarietà (l'unica che vediamo).

**Def.**
L'[ereditarietà](<https://it.wikipedia.org/wiki/Ereditariet%C3%A0_(informatica)>)
è un meccanismo che, in fase di dichiarazione di una classe, ci
consente di specificare solo le differenza rispeto a una classe già
esistente, detta superclasse. Tutti gli altri
comportamenti/caratteristiche saranno gli stessi della superclasse.
\[libro pag. 208\]

**Esempio.** Supponiamo voler modellare gli animali come classi e
fissiamo un comportamento generale per tutti gli animali, racchiuso
nella classe `Animali`.

```cpp
class Animale {
    public:
        void dormi() { cout << "sto dormendo" << endl; }
        void verso() { cout << "** nessun verso ** " << endl; }
};
```

Ovvero, vorremmo che tutti gli animali della nostra applicazione siano
in grado di fare il loro verso.

Ora aggiungiamo un cane che implementa a suo modo il metodo `verso`

```cpp
class Cane : public Animale {
    public:
         void verso() {
            cout << "Bau" << endl;
         }
};
```

e vediamo il risultato dell'esecuzione del main

```cpp
Cane c;
c.verso();

Cane* c = new Cane;
c->verso();

// Un cane è un animale, quindi...
Animale a = new Cane;
a->verso();
```

```
Bau
Bau
** nessun verso **
```

Un comportamento strano: ci aspetteremmo che `a->verso()` stampi a
video "Bau". Questo succede perché dobbiamo indicare al compilatore
che deve cercare la definizione del metodo invocato **a runtime**! Lo
possiamo fare con la keywork `virtual` da usare nella definizione del
metodo.

Modifichiamo quindi la classe `Animale`.

```cpp
class Animale {
    public:
        virtual void verso() { cout << "** nessun verso ** " << endl; }
};
```

Ora, rieseguendo il main otteniamo

```
Bau
Bau
Bau
```

Questo codice però ha un problema: ci permette di istanziare oggetti
che sono semplicemente animali. Per la nostra applicazione, questo non
è un comportamento voluto: non sappiamo dire che verso fa un animale
generico!

In C++ è possibile indicare che un metodo di una classe non ha
implementazione impostandolo a $0$.

```cpp
class Animale {
    public:
        virtual void verso() = 0;
};
```

Così facendo si indica al linguaggio che il metodo `verso` della
classe `Animale` **non** ha implementazione e deve essere quindi
implementato da chi eredita la classe `Animale`. Di conseguenza

```cpp
Animale a1;
```

oppure

```
Animale a2 = new Animale;
```

diventa un errore a tempo di compilazione.

Una classe diventa astratta **astratta**, ovvero rappresenta solamente
un'interfaccia, una definizione, un contratto che indica come sono
fatti degli animali, quando ha almeno un metodo virtuale.

Una classe è **astratta pura** quando tutti i suoi metodi sono
virtuali.

### Risoluzione delle chiamate (cenni)

Il polimorfismo dinamico è effettuato a runtime proprio perché le
chimate ai metodi virtuali possono essere risolte solo a tempo di
esecuzione. La scelta di quale metodo eseguire è effettuata per ogni
chiamata in base al tipo dell'oggetto che si sta analizzando.

## Polimorfismo statico

Fonte:
[\[1\]](https://medium.com/@kateolenya/static-polymorphism-in-c-9e1ae27a945b)

In relazione al polimorfismo dinamico, il polimorfismo statico risolve
i tipi a tempo di compilazione. Esso sfrutta pesantemente
l'overloading degli operatori/funzioni dato che il compilatore sa
distinguere quale funzione chiamare in base al tipo e numero di
parametri passati alla funzione.

L'idea dell'overloading delle funzioni è comoda se i vari overload
delle funzioni si trovano a dover fare cose diverse, ma se invece
vogliamo effettuare esattamente la stessa cosa su tipi diversi ciò è
scomodo: dovremmo scrivere tante funzioni uguali con il tipo dei
parametri diverso.

Il C++ risolve questo problema con i **template**. I template sono
degli "stampini" di funzioni che servono a produrre funzioni (vero e
proprio codice) specializzato su un certo tipo.

### Template di funzione

**Esempio.** Definiamo una funzione `mia_somma` che implementa la
somma tra due input e la stampa dopo averla calcolata.

```cpp
template <typename T>
void mia_somma (T a, T b) {
    cout << "Risultato = " << (a + b) << endl;
}
```

`mia_somma` è una funzione templatica, ovvero abbiamo specificato un
parametro di tipo (il tipo `T`) che verrà rimpiazzato dal compilatore
qualora ce ne sia bisogno.

```cpp
int main () {
    int   p = 1;
    int   i = 2;
    float n = 10.1;
    float e = 11.2;

    mia_somma<int>(p, i);    // tipo specificato manualmente
    mia_somma(n, e);         // tipo dedotto dal compilatore
    mia_somma(p, e);         // errore a compile-time, perchè?

    return 0;
}
```

La terza chiamata genera un errore a tempo di compilazione perché `p`
ed `e` sono di tipi diveri. Dalla definizione di `mia_somma` vediamo
che, pur non avendo specificato il tipo (`T` è generico), i parametri
`a` e `b` devono avere lo stesso `T`!

Q: cosa è successo di particolare nelle chiamate 1 e 2? \
R: sono state generate due funzioni uguali `mia_somma` dove `T` è stato
sostituito una volta con `int` e un'altra volta con `float`.

### Template di classe

**Esempio.** Classe `Pila`.
