# Linguaggi Formali

Contesto:

- nascita anni 30 teoria
- disciplina definita pienamente se teoria evienzia limiti e
  potenzialità

QUIZ: realizzazione mediante dispositivi elettronici è l'unico modo di
fare informatica? \
R: No! è stata solo fortuna dovuta al periodo e allo studio dell'elettronica
anni 40/50

Siamo indipendenti da una macchina fisica! Macchine attuali basate su
architettura Von-Neumann / Turing.

Esempi di strumenti di calcolo

- DNA compuiting (molecole)
- Quantum Computing (particell)
- Lambda Calcolo (mero calcolo simbolico)

QUIZ: possiamo calcolare tutto? \
R: Sì? No? Proviamo a pensare alla cosa più semplice: un algoritmo trasforma
un input in output. Facciamo in modo che I e O siano naturali (cosa più
semplice) e algoritmo è una seq finita di passi.

Allora possiamo enumerare tutti i programmi, ad esempio:

- programma vuoto ha indice 0
- programma che somma 1 all'input ha indice 1
- programma che moltiplica per 5 ha indice 2
- e così via... (gli indici dipendono dalla codifica).

Fissiamo un programma $P_n$ che fa qualunque cosa vogliamo, tanto li
possiamo elencare tutti.

Costruiamo ora il seguente problema

_input_: $n$ \
determina il programma $P_n$ \
calcola $P_n(n)$ \
_output_: $P_n(n) + 1$

Se possiamo codificare questo programma allora esso assumerà un
indice, supponiamo l'indice sia _m_. 94? 663251002? Non ci interessa!

Chiamiamo $h = P_m$

Ma allora avremmo

$$h(m) = P_m(m) + 1 =  h(m) + 1$$

Assurdo!

R: No! Non possiamo calcolare tutto.

Da qui abbiamo diverse categorie di linguaggi formali, più o meno
espressivi. La prima e l'unica che vediamo sono gli automi a stati
finiti.

## Automi a stati finiti

Primo linguaggio formale, quanto è espressivo?

Un modello matematico avente input / (eventualmente) output a valori
discreti e che si può trovare solo in certi stati (finiti). L'essere
in uno stato gli permette di avere memoria di quello che è successo.

Esempio di automa: ascensore, dove input è seq di tasti premuti mentre
lo stato è il piano in cui si trova.

### Tab di transizone

Comportamento di un automa si definisce mediante una tabella detta
matrice/tab. di transizione

|     | a   | b   |
| --- | --- | --- |
| q0  |     |     |
| q1  |     |     |
| q2  |     |     |

dove sulle righe abbiamo gli stati e sulle colonne i simboli
dell'alfabeto che vogliamo leggere. Le celle possono contenere altri
stati ed indicano come transire da uno stato ad uno stato se letto un
particolare simbolo.

Esempio: (q1 stato finale)

|        | a   | b   |
| ------ | --- | --- |
| q0     | q1  | q2  |
| **q1** | q1  | q0  |
| q2     | q1  | q0  |

Rappresentiamo la tabella tramite un grafo.

GRAFO

### Def matematica

Matematicamente possiamo dire un automa deterministico a stati finiti
(DFA) è una quintupla $M = \langle Q, \Sigma, \delta, q_0, F \rangle$
dove

- Q insieme finito di stati
- $\Sigma$ alfabeto (di input)
- $\delta : Q \times \Sigma \rightarrow Q$ funzione di transizione
- $q_0$: stato iniziale
- $F \subseteq Q$ insieme stati finali

**Notazione**: p, q, r denotano stati; P, Q, R, S denotano insiemi di
stati; a, b denotano simboli di $\Sigma$; x, y, z, u, v, w denotano
stringhe.

Da $\delta$ si ottiene facilmente la funzione
$\hat\delta : Q \times \Sigma^* \rightarrow Q$ come

$$\hat\delta(q, \epsilon) = q$$
$$\hat\delta(q, wa) = \delta ( \hat\delta ( q, w ), a)$$

Quindi, una stringa $x$ è accettata da un DFA se
$\hat\delta(q_0, x) \in F$. Il linguaggio accettato da $M$, denotato
come $L(M)$ è l'insieme delle stringhe accettate, ovvero:
$$L(M) = \{ x \in \Sigma^* : \hat\delta(q_0, x) \in F \}.$$

Quanto è espressivo un automa? ==> Linguaggi regolari.

_Esercizio_: costruire un automa che non accetta nessuna stringa

_Esercizio_: costruire un automa che accetta tutte le stringhe

_Esercizio_: Tradurre la seg. tabella di transizione in grafo con
$F = \{ q1 \}$.

|     | 0   | 1   |
| --- | --- | --- |
| q0  | q1  | q2  |
| q1  | q1  | q1  |
| q2  | q1  | q0  |
