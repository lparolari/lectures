#include <iostream>
#include <string>

using namespace std;

struct contatto
{
    string nome;
    string numero;
    int preferenza;
};

void ricerca(contatto rubrica[], string nome, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (rubrica[i].nome == nome)
        {
            cout << rubrica[i].nome << " " << rubrica[i].numero << endl;
            break;
        }
    }
}

void inserisci(contatto rubrica[])
{
    int n;
    cin >> n;

    if (n > 100)
        return 1;

    for (int i = 0; i < n; i++)
    {
        cout << "Inserire nome numero e preferenza: " string nome;
        cin >> nome;

        rubrica[i].nome = nome;

        // cin >> rubrica[i].nome;
        cin >> rubrica[i].numero;
        // ...
    }
}

int main()
{
    // software gestione rubrica telefonica

    // contatto -> nome, numero

    contatto rubrica[100];

    contatto pippo = {"Pippo", "1234567", 1};
    contatto pluto = {"Pluto", "557789", 2};

    rubrica[0] = pippo;
    rubrica[1] = pluto;

    string nome = "Pluto";

    ricerca(rubrica, nome, 2);

    return 0;
}
