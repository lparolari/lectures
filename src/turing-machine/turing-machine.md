# Turing Machine

## MdT

Macchina di Turing rappresenta l'idea di poter svolgere calcoli come
quelli su carta servendosi di carta bianca per scrivere risultati
parziali. Turin pensa questa macchina come un oggetto che scrive su un
nastro (1D) potenzialmente infinito. Il nastro è composto da celle che
rappresentano la quantità di memoria unitaria. Il corpo della macchina
(controllo) è realizzato mediante DFA che modella la necessità di
avere potenza limitata nelle istruzioni eseguite. Tutto il sistema
prende il nome di MdT.

Un simbolo che si può scrivere sul nastro è $, che rappr. l'assenza di
simboli (spazio bianco). I simboli possono essere scritti dalla
testina uno alla volta.

La struttura a stati finiti della testina modella una memoria a breve
termine, mentre il nastro modella una memoria a lungo termine
(permanente).

Il comportamento di una MdT è descrivibile mediate tabella (matrice
funzionale), dove sulle righe abbiamo gli stati del controllo, mentre
sulle colonne abbiamo i simboli dell'alfabeto.

Un'azione della MdT, dati un simbolo $s_j$ ed uno stato $q_i$ consiste
nel

- portarsi in uno stato interno $q_r$,
- scrivere il simbolo $s_k$,
- spostare il nastro a destra R o a sinistra L

Nel caso $s_i = s_k$ la macchina lascia inalterato il simbolo sul
nastro. Se la coppia $\langle s_j, q_i \rangle$ è vuota, la macchina
si derma (stuck, incastrata).

DEF (MdT): Una macchina di turing consiste di

- $\Sigma = \{ s_0, \ldots, s_n \}$ un alfabeto con almeno due simboli
  $s_0 =\$$ e $s_1 = 0$;

- $Q = \{ q_0, \ldots, q_m \}$ un insieme finito di stati tra i quali
  vi è lo stato iniziale $q_0$;

- un insieme finito non vuoto di istruzioni (o quintuple):
  $q \quad s \quad q' \quad s' \quad R$ (oppure $L$).

Possiamo immaginare quindi $\delta$ come una funzione di transizione
$\delta: Q \times \Sigma \rightarrow Q \times \Sigma \times \{ L, R \}$.

DEF (Descrizione istantanea (ID)): Una ID è una quadrupla

$$\langle q, v, s, w \rangle$$

Dove $u, w \in \Sigma^*$ rappr. i caratteri significativi (limitati da
$) rispettivamente a destra e sinistra della testina. $s$ è il simbolo
sotto la testina e $q$ è lo stato del controllo.

DEF (Successore): Il successore $\vdash$ è una mappa tra descrizioni
istantanee definita come

- spostamento a sinistra:
  $\langle q, v, r, sw \rangle \vdash \langle q', vr', s, w \rangle$ e
  $\langle q, v, r, \epsilon \rangle \vdash \langle q', vr', \$, \epsilon \rangle$
  se $q\ r\ q'\ r'\ R$ è un'istruzione di P (descrizione tramite delta
  della macchina)

- spostamento a destra: analogo al precedente

DEF (Computazione): Un a computazione è una sequenza finita di ID
$\alpha_0, \ldots, \alpha_n$ tale che

- $\alpha_0 = \langle q_0, v, s, w$

- $\alpha_i \vdash \alpha_{i+1}$ per ogni $i \in \{ 0, \ldots, n-1 \}$

TEOREMA (Determinismo). Se $\alpha \vdash \beta$ e
$\alpha \vdash \gamma$ con $\alpha, \beta, \gamma \in \text{ID}$,
allora $\beta = \gamma$.

ESEMPIO (Incremento stringa in binario).

ESEMPIO (Copia stringa unaria).

ESEMPIO (Incremeneto in base 10). $S = \{ 0, \ldots, 9 \}$ e
$Q = \{ q_0, q_1 \}$

ESERCIZI (Dovier pag. 104)

- successore di un num decimale

- decidere quale stringa unaria è più lunga tra le due a lato della
  testina (NB: le str possono essere uguali)

- somma binaria tra due stringhe (in binario) non nulle di 0 e 1 poste
  a sx della testina e intramezzate da $

- spostare la testina a destra di $n$ posizioni rispetto a quella di
  partenza dove $n$ è letto tramite input binario

- num occorrenze di 1 in una data seq. binaria

- ordinare con ripetizioni una stringa di input di 0 e 1

## Funzioni calcolabili da MdT

DEF (Turin-calcolabilità): Una funzione
$f :  \mathds{N}^n \righarrow \mathds{N}$ è Turing-calcolabile se
esiste MdT tale che partendo dalla configurazione iniziale termina in
una configurazione finale (specifica input output) se
$f(x_1, \ldots, f_n)$ è definita, non termina altrimenti.

ESEMPIO

- $\lambda x . x$

- $\lambda x . 0$

- $\lambda x . x + 1$
