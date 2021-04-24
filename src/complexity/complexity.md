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

TODO
