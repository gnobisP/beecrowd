#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int quant;
    cin >> quant;
    int nivel;
    cin >> nivel;
    vector<int> vetor;

    int numero;
    while (cin >> numero)
    {
        vetor.push_back(numero);
    }

    int aux = 0;
    int movimentos = 0;
    int controle;
    while (1){
        if (aux == quant)
            break;
        controle =  nivel - vetor[aux];
        vetor[aux] += controle;
        vetor[aux + 1] += controle;
        movimentos += abs(controle);
        aux++;
    }
    cout << movimentos << endl;

    return 0;
}