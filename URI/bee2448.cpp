#include <iostream>
#include <vector>
using namespace std;
int main()
{
    unsigned int quantCasas;
    cin >> quantCasas;
    unsigned int quantEntregas;
    cin >> quantEntregas;

    vector<long int> casas;
    for (unsigned int i = 0; i < quantCasas; i++)
    {
        long int num;
        cin >> num;
        casas.push_back(num);
    }

    vector<long int> entregas;
    for (unsigned int j = 0; j < quantEntregas; j++)
    {
        long int num;
        cin >> num;
        entregas.push_back(num);
    }

    long int posInicial = 0;
    long int valorCasa;
    long long int tempoFinal = 0;
    for (unsigned int aux = 0; aux < quantEntregas; aux++)
    { // Percorrendo as entregas
        valorCasa = entregas[aux];
        for (long int i = 0; i < quantCasas; i++)
        { // Percorrer casas
            if (valorCasa == casas[i])
            { // Encontrar a posicao da casa
                tempoFinal += abs(i - posInicial);
                posInicial = i;
                break;
            }
        }
    }
    cout << tempoFinal << endl;

    return 0;
}