# Approssimazione Pi Greco

Scrivere un algoritmo per approssimare il pi-greco.

Q: Qualcuno ha un'idea di come approcciare il problema? \
Q: Dove troviamo il pi-greco? \
R: nel calcolo dell'area del cerchio!

Q: Formula dell'area del cerchio? \
R: $A = \pi r^2$

Dobbiamo ricavare il $\pi$. Usiamo l'artimetica.

$$A = \pi r^2 \Leftrightarrow \pi = \frac{A}{r^2}$$

A questo punto per ottenere $\pi$ ci basta conoscere $A$ e $r$. Per
quanto riguarda $r$ la possiamo fissare noi a piacere, mentre $A$
dobbiamo calcolarcela, e chiaramente non possiamo ricorrere alle
formule matematiche, che usano il $\pi$, perché è la nostra incognita!

Q: Qualcuno ha qualche idea? \

Proviamo a ragionare su cosa è un'area. Supponiamo di guardare un
cerchio su un'immagine composta di pixel, e quindi **discreta**.

![cerchio](./img/circle-large.png)

Q: Qual è l'area di questo cerchio? (vedere l'immagine 16x16).

Se dovessimo dire qual è l'area del cerchio basterebbe semplicemente
contare il numero di pixel al suo interno.

Estendiamo questo concetto!

Utilizziamo il teorema di euclide. Tramite il teorema di euclide
riusciamo a dire se, dato un punto con coordinate $a$ e $b$, esso sta
o meno sulla circoferenza del cerchio con raggio $r$:

$$r^2 = a^2 + b^2.$$

Ma, possiamo fare di più! Possiamo anche riuscire a dire se un punto
sta dentro alla circonferenza:

$$r^2 \leq a^2 + b^2.$$

A questo punto abbiamo un vincolo che, dato un punto, ci dice se esso
fa parte del cerchio: ci basta contare questi punti (come fossero
pixel) per ottenrere l'area del cerchio!

Q: Ma quali punti dobbiamo verificare? Quanti punti ci sono su un
piano cartesiano?

Basta verificare quelli nel quadrato che comprende il cerchio: ovvero
i punti con coordinate $a$ e $b$ tali che $a, b \in [ -r, +r ]$.
