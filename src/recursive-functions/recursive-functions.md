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

Esempio: supponiamo di avere a che fare con un linguaggio
semplicissimo, che ci permette solo di esprimere il numero 0 e il
successore di un numero tramite una funzione.

$$zero = 0$$ \
$$s(n) = 1 + n $$

A questo punto, possiamo definirci i numeri naturali!

$$uno = s(zero)$$ \
$$due = s(uno)$$

e così via...

Assumendo ora di aver codificato i numeri naturali che ci servono, che
per comodità rimpiazziamo con il loro simbolo, riusciamo a codificare
operazione relativamente complesse come somme, moltiplicazioni, if e
altro?

Se ci pensiamo bene la somma di $n$ con $m$ non è altro che il
successore di $n$, $m$ volte!

$$\text{somma}(n, 0) = n$$ \
$$\text{somma}(n, m) = s(\text{somma}(n, m - 1)) = 1 + \text{somma}(n, m - 1)$$

Ma ciò vale anche per la moltiplicazione! La moltiplicazione $n$ per
$m$ non è altro che la somma di $n$ $m$ volte, ovvero

$$\text{molt}(n, 0) = 0$$ \
$$\text{molt}(n, m) = \text{somma}(n, \text{molt}(n, m - 1))$$

Q: Vantaggi/svantaggi della ricorsione? \
R: Semplifica molto la scrittura di alcuni problemi ma complica notevolmente
quella di altri! In più a volte risulta meno efficiente e più complicata
da capire.

EX: Proviamo ad implementare la sequenza di fibonacci.
$$\text{fib}(0) = \text{fib}(1) = 1$$ \
$$\text{fib}(n + 1) ) = \text{fib}(n) + \text{fib}(n - 1)$$

EX: Implementazione dell'algoritmo di bubble sort per ordinamento di
array. Il bubble sort ordina una sequenza scambiando il valore delle
due posizioni se esse non rispettano l'ordinamento.

```cpp
#include <iostream>

void stampa(int X[], int n) {
  for (int i = 0; i < n; i++) {
    std::cout << X[i] << " ";
  }
  std::cout << std::endl;
}

void swap(int X[], int i, int j) {
  int tmp = X[i];
  X[i] = X[j];
  X[j] = tmp;
}

void bubble_sort(int X[], int n) {
  if (n == 1) return;

  for (int i = 0; i < n - 1; i++) {
    if (X[i] > X[i + 1])
      swap(X, i, i+1);
  }

  bubble_sort(X, n - 1);
}

int main() {
    int A[] = {1,3,4,2};

    stampa(A, 4);
    bubble_sort(A, 4);
    stampa(A, 4);

    return 0;
}
```

EX: Torri di Hanoi.

```cpp
#include <iostream>

// n dischi, sorgente, destinazione, piolo temporaneo
// nota: il disco n è il più grosso, 1 è il più piccolo
void hanoi(int n, char A, char B, char C) {
  if (n <= 0) return;

  hanoi(n - 1, A, C, B);
  std::cout << "Muovo " << n << " dal piolo " << A << " al piolo " << B << std::endl;
  hanoi(n - 1, C, B, A);
}

int main() {
    hanoi(3, 'a', 'b', 'c');

    return 0;
}
```
