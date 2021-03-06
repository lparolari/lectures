# Funzioni Ricorsive

In matematica è molto comune definire funzioni in maniera ricorsiva.
Per capire meglio il concetto di ricorsione vediamo un esempio. Si
supponga di voler contare il numero di strette di mano tra persone ad
una festa tenendo conto del fatto che ogni persona stringe la mano a
tutte le altre persone.

Su una festa con quattro invitati `A`, `B`, `C` e `D` abbiamo che

- `A` stringe la mano a `B`, `C`, `D` (tutti gli altri tranne,
  ovviamente, se stesso)
- `B` stringe la mano a `C` e `D` (tutti gli altri tranne `A`, a cui
  l'ha già srtetta, e se stesso)
- `C` stringe la mano a `D`
- `D` è apposto, abbiamo già contato le sue strette di mano

In totale abbiamo quindi $3 + 2 + 1 = 6$ strette di mano.

Q: Come definiamo formalmente il problema? \
R: Semplice, con la ricorsione:

$$f(1) = 0$$ \
$$f(n) = n - 1 + f(n - 1)$$

dove la prima definizione indica il caso base: se l'invitato è solo
uno chiaramente le strette di mano sono nessuna. La seconda invece
dice che le strette di mano in una festa di $n$ persone sono $n - 1$
(ovvero il primo la stringe a tutti tranne a se stesso) più il numero
di strette di mano degli altri $n-1$ invitati.

Vediamone la codifica in un programma.

```cpp
int f(int n) {
    if (n == 1) return 0;
    return n - 1 + f(n - 1);
}
```

Di fatto la codifica in un linguaggio di programmazione che supporta
le funzioni ricorsive è quasi 1 a 1.

Q: Quindi, cos'è una funzione ricorsiva? \
R: E' solo una funzione che richiama se stessa direttamente o indirettamente.

Le funzioni ricorsive hanno un sacco di applicazioni interessanti
dovute principalmente al fatto che alcuni problemi sono di loro natura
ricorsivi e scriverne un'implementazione iterativa è semplicemente più
complicato.

Ad esempio, tra i problemi ricorsivi facilmente codificabili abbiamo

- la sequenza di Fibonacci
- l'attraversamento DFS di un albero / grafo
- torri di Hanoi
- ...

Q: Possiamo scrivere tutto in maniera ricorsiva? \
R: Sì! Ci sono dei linguaggi (funzionali) che non hanno nemmeno i costrutti
iterativi come il while o for.

Esempio: la moltiplicazione $n$ per $m$ non è altro che la somma di
$n$ $m$ volte, ovvero

$$\text{molt}(n, 0) = 0$$ \
$$\text{molt}(n, m) = n + \text{molt}(n, m - 1)$$

La cui codifica è immediata:

```cpp
int molt(n, m) {
    if (m == 0) return 0;
    return n + molt(n, m - 1);
}
```

Ma ciò vale anche per la somma! Che cos'è la somma tra $n$ ed $m$ se
non l'aggiunta di un'unità $m$ volte ad $n$!

$$\text{somma}(n, 0) = n$$ \
$$\text{somma}(n, m) = 1 + \text{somma}(n, m - 1)$$

EX: Proviamo ad implementare la sequenza di fibonacci.
$$\text{fib}(0) = \text{fib}(1) = 1$$ \
$$\text{fib}(n + 1) ) = \text{fib}(n) + \text{fib}(n - 1)$$

Q: Vantaggi/svantaggi della ricorsione? \
R: Semplifica molto la scrittura di alcuni problemi ma complica notevolmente
quella di altri! In più a volte risulta meno efficiente e più complicata
da capire.
