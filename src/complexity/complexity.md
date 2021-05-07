# Complessità Compitazionale

## Qualità

Q: Più algoritmi che realizzano la stessa soluzione, ma come si fa a
capire quando uno è meglio dell'altro? Quali proprietà di efficienza
vogliamo? \
A: Correttezza (assumiamo vera), tempo e spazio!

**Spazio**: quanta memoria occupa il mio programma? Data la crescente
disponibilità di memoria nelle macchine non ci occupiamo di questo
aspetto, anche se intere discipline (Big Data Computing) studiano come
gestire anche questo aspetto.

**Tempo**: quanto tempo impiega l'esecuzione del processo legato
all'algoritmo?

## Costo

Q: Come posso esprire il costo di un algoritmo? \
A: In secondi...

Misura di tempo apparentemente corretta, ma dipende dalle condizioni
in cui viene eseguito il test.

Q: Riuscite ad immaginare quando il costo (misurato in secondi)
dell'algoritmo si abbassa o alza a parità di codice? \
A:

- velocità di esecuzione della macchina,
- velocità (e ottimizzazione) dell'interprete/compilatore,
- dimensione e disposizione dei dati

Quindi, quando un confronto è valido? E' valido solo se il test viene
eseguito sulla stessa macchina, con lo stesso compilatore e con dati
diversi e disposti in modo diverso.

Q: Ma allora si potrebbe avere che un algoritmo su un PC è più veloce
e su un altro invece no. Ha senso?

ESEMPIO (bench.cpp)

Prendiamo in esempio questo algoritmo che effettua l'ordinamento
crescente.

```
void ordina(std::vector<int> &A)
{
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = i; j < A.size(); j++)
        {
            if (A[i] > A[j])
            {
                int tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        }
    }
}
```

Q: Il tempo di esecuzione cambia in base al fatto che l'input sia un
array già ordinato o meno? \
A: Sì! Il nel caso già ordinato non deve fare nessuno scambio.

Q: E se diamo in input un array ordinato in modo decrescente? \
A: Caso peggiore per questo algoritmo!

**Conclusione**

Bisogna cambiare il modo di misurare il costo di un algoritmo: al
posto che misurare il tempo, misuriamo il numero di operazioni di un
algoritmo. Quanti passi di computazione deve fare l'algoritmo per
arrivare ad una soluzione?

### Regole di valutazione

Introduciamo alcune regole di valutazione.

#### Istruzioni semplici

Q: il seg. algoritmo quanto tempo impeiga ad essere eseguito?

```cpp
std::cout << "Quanto sono veloce?" << std::endl;
```

A: 1

Possiamo assegnare costo 1 alle istruzioni semplici come questa.

#### While

Q: e per il costrutto `while` o `do while` come ci comportiamo?

```cpp
while (i < 10) {
  std::cout << i << std::endl;
  i++;
}
```

A: costo pari alla somma del test e del corpo del ciclo. In
particolare, il test ha costo pari a 1, mentre il corpo ha costo pari
alla somma delle istruzioni. Quindi con _K_ numero di iterazioni
abbiamo
$$C_{\text{Tot}} = C_{\text{Test}} * K + C_{\text{Corpo}} * K$$

#### For

Q: e per il `for`? \
A: vale lo stesso discorso del while, con la differenza che abbiamo un
costo supplementare all'inizio del ciclo per inizializzare la variabile
e poi ad ogni ciclo abbiamo da fare il test ($K + 1$ volte) e incrementare
la variabile, quindi $$C = 1 + C_{\text{Test}} * (K + 1) + C_{\text{Incremento}} * K + C_{\text{Corpo}} * K$$

#### If

Q: per l'`if`? \
A: dipende... quale branch viene eseguita? Quella dell'then o dell'else?
$$C = 1 + \text{max} (C_{\text{Then}}, C_{\text{Else}})$$

#### Sottoprogramma

Q: una chiamata a funzione o procedura? \
A: 1 per la chiamata + costo dell'esecuzione del sottoprogramma, ovvero
$$C = 1 + C_{\text{Sottoprogramma}}$$

#### Istruzione composta

Q: `istr1; istr2` ? \
A: $$\Sigma C_{\text{Istr}_i}$$

### Costo dominante

In questo sistema di valutazione possiamo escludere tutti i problemi
legati alla macchina, al compilatore e ai dati. Da questo possiamo
dedurre che

> Il tempo di esecuizione di un algoritmo è _proporzionale_ al suo
> costo

## Complessità computazionale

Numero di operazioni di un algoritmo è legato alla dimensione dei dati
di input. Se così non fosse il costo dell'algoritmo sarebbe una
costante.

Possiamo allora definire il costo di un algoritmo in funziuone
dell'input (in particolare, della dimensione dell'input) $T(N)$.
Questa funzione viene denominata "complessità dell'algoritmo", essa
indica la relazione tra il numero di operazioni di un programma e la
dimensione $N$ dei dati di input.

E' facile quindi capire che a parità $N$, un algoritmo che impiega
meno operazioni per risolvere un problema è migliore di un altro.

ESEMPIO: algoritmo che somma gli elementi di un array.

```cpp
#include <iostream>
#include <vector>

int main() {
    // assumiamo che questi siano gli input dell'algoritmo
    // e che ci possano essere dati anche da fuori

    int N = 10;
    std::vector<int> A = { 15, 2, 4, 56, 3, 11, 12, 90, 56, 45 };

    int somma = 0;

    for (int i = 0; i < N; i++) {
        somma += A[i];
    }

    std::cout << somma << std::endl;
}
```

Ora calcoliamo la sua $T(N)$.

$T(N) = 1 + 1 + N + N + N + 1 = 3 + 3N$

Quindi otteniamo una retta con una certa pendenza.

Andando ad approssimare possiamo dire che l'algoritmo opera in $O(N)$,
ovvero l'ordine del polinomio che rappresenta la sua complessità non
supera mai $N$! Questo vale anche nel caso di costanti: $3N > N$, ma
la notazione $O$ nasconde queste costanti.

ESEMPIO.

- algoritmo che calcola $x^5$
- algoritmo che calcola $x^n$
- algoritmo che calcola $x^n$ ma con il metodo dei resti

## Classe di complessità

Siano $f(n)$ e $g(n)$ due funzioni. Si dice che $f(n)$ è di ordine di
grandezza $g(n)$ e si scrive $O(g(n))$, se esiste una costante $C > 0$
tale che $\forall x \in \mathbb{N} : f(x) < C * g(x)$.

E possiamo quindi affermare che un algoritmo con costo $T(N)$ ha
complessità proporzionale a $N^2$, ovvero $O(N^2)$.

Classi di complessità:

- Costante $O(1)$. Stesso num di operazioni indipendentemente
  dall'input;

- Logaritmica $O(\log N)$. Esempio: ricerca binaria;

- Sublineare $O(n^c)$ con $0 < c < 1$. Esempio: Ricerca in un albero
  con k figli.

- Lineare $O(N)$. Esempio: ricerca sequenziale, lettura, stampa,
  verifica di numero primo, ...;

- Linearitmico $O(N \log N)$. Esempio: ordinamento comparativo;

- Polinomiale $O(N^K). Esempio: prodotto matriciale;

- Esponenziale $(2^N). Esempio: generare tutte le possibili stringhe
  di un alfabeto;
