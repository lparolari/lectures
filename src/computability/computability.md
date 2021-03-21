# Computabilità

Come abbiamo già accennato precedentemente, non tutto è calcolabile.
Ma prima, quando possiamo dire che una funzione è calcolabile?

Ricordiamo cos'è un algoritmo. \
Un algoritmo è una sequenza finita di passi da seguire (in modo meccanico,
senza intelligenza!) per realizzare un certo obiettivo.

Esempi:

- dato $n \in \mathbb{N}$ dire se è primo
- trovare l'n-esimo numero primo
- calcolare la radice quadrata
- mcd, MCM
- ...

Dunque pissiamo pensare un algoritmo come un procedimento per
trasformare input in output. Quindi un algoritmo è una black box.
\[SCHEMA\]. Se l'algoritmo è deterministico, esso è individuato da una
funzione dell'input: valori di input -> valori di output (come una
tabella, analogia con funzione di transizione). Quindi, si dice che
l'algoritmo calcola questa funzione e che questa è (effettivamente)
calcolabile/computabile.

Ovvero, una funzione è calcolabile se **esiste** un algoritmo che la
calcola. \
Nota: basta l'esistenza dell'algoritmo! Non serve conoscerlo!

Da questa definizione sono chiaramente calcolabili

- MCD, mcm;
- $f(n)$ che restituisce 1 se $n$ è primo, 0 altrimenti;
- calcolo della $n$-esima cifra di $\pi$ tramite algoritmi che
  convergono a $\pi$.

E' calcolabile invece la funzione che restitusice 1 se in $\pi$ ci
sono esattamente $n$ 5 consecutivi?

No! Posso dire sì, se a un certo punto dello sviluppo li trovo, ma non
posso mai dire no: se non li trovo devo andare avanti a cercare, non
posso fermarmi e dire che non si troveranno mai.

Qualcosa del tipo: "calcola le cifre nell'espansione di $\pi$ e se ci
sono $n$ 5 allora restitusci 1 altrimenti 0" non è una procedura
effettiva.

Questo non significa che la funzione non sia calcolabile, ma al
momento la procedura per questo calcolo non è nota.

Un esempio più sottile è la funzione $g(n)$ che restituisce 1 se
esiste una sequenza di almeno $n$ 5 consecutivi in $\pi$, 0
altrimenti. \
Q: è calcolabile? \
R: Sì!

Possiamo dimostrarlo definendo un intero
$k = \text{sup} \{ n | \text{esistono n "5" consecutivi in } \pi \}$.
Nota: l'operatore $\text{sup}$ restituisce il bound superiore
all'insieme, ovvero un numero che limita superiormente l'insieme. In
questo caso restituisce il massimo dell'insieme se questo è finito,
altrimenti $\infty$ se questo è infinito. Definito così $k$, due
possibilità

- $k$ finito -> ci basta verificare che $k$ sia più grande (o uguale)
  ad $n$.
- $k$ infinito -> possiamo dire che una seq di lunghezza almeno $n$
  esiste sempre: ne troviamo molte (infinite!)

In entrambi i casi la funzione è calcolabile. Primo caso, dato $n$,
guardo se $n \leq k$, se se restituisco 1, se no 0. Secondo caso,
ignoro $n$ e restituisco $1$. \[ES. IMPLEMENTAZIONE AL VOLO\].

In questo pare esserci un problema: **non conosciamo** $k$! In altre
parole, degli algoritmi menzionati, non sappiamo quale sia quello
giusto, ma pare essercene uno.

NOTA: affinchè una funzione sia calcolabile basta che un algoritmo
esista, non serve conoscerlo.

Questo discorso ci permette ora di pensare al computer solo come un
mero esecutore: di fatto possiamo discostarci da tutto ciò e basarci
solo su modelli teorici. Vogliamo svincolarci dalla macchina fisica e
fare ragionamenti teorici per capire limiti e potenzialità
dell'informatica in termini di computabilità.

## MdT

TODO
