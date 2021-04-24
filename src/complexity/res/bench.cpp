#include <iostream>
#include <chrono>
#include <vector>
#include <string>

// Dimensione dell'array
const int DIM = 50000;

// Ordina un array dato
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

// Crea un vettore ordinato partendo da 0 fino a DIM - 1
std::vector<int> crea_ordinato_asc()
{
    std::vector<int> A;
    A.reserve(DIM);

    for (int i = 0; i < DIM; i++)
    {
        A.push_back(i);
    }

    return A;
}

// Crea un vettore ordinato partendo da DIM - 1 fino a 0
std::vector<int> crea_ordinato_desc()
{
    std::vector<int> A;
    A.reserve(DIM);

    for (int i = DIM - 1; i >= 0; i--)
    {
        A.push_back(i);
    }

    return A;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "[ERR] "
                  << "Specificare il parametro di direzione" << std::endl;
        return 1;
    }

    std::string dir = argv[1];

    if (!(dir == "ASC" || dir == "DESC"))
    {
        std::cerr << "[ERR] "
                  << "Specificare direzione ASC o DESC" << std::endl;
        return 1;
    }

    // Creazione del vettore esclusa dal cronometro.
    std::vector<int> A;

    if (dir == "DESC")
    {
        A = crea_ordinato_desc();
        std::clog << "[LOG] "
                  << "Creato vettore ordinato dal più grande al più piccolo" << std::endl;
    }
    else
    {
        A = crea_ordinato_asc();
        std::clog << "[LOG] "
                  << "Creato vettore ordinato dal più piccolo al più grande" << std::endl;
    }

    // Prendo il tempo prima della chiamata alla funzione di ordinamento
    // Start è di tipo `std::chrono::_V2::system_clock::time_point`, che
    auto start = std::chrono::high_resolution_clock::now();

    // Ordino array
    ordina(A);

    // Prendo il tempo dopo l'esecuzione dell'ordinamento
    auto stop = std::chrono::high_resolution_clock::now();

    // Calcolo la differenza tra stop e start e la converto in millisecondi
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    // Stampo il tempo di esecuzione a video
    std::clog << "[LOG] "
              << "Impiegati " << duration.count() << " millisecondi" << std::endl;
    std::cout << duration.count() << std::endl;
}
