#include <iostream>
using namespace std;

int main()
{
    int linha;
    int coluna;
    cin >> linha;
    cin >> coluna;

    long int **matriz = new long int *[linha];
    for (int i = 0; i < linha; i++)
    {
        matriz[i] = new long int[coluna];
        for (int j = 0; j < coluna; j++)
        {
            cin >> matriz[i][j];
        }
    }
    int *posicaoColZero = new int[linha];
    for (int i = 0; i < linha; i++)
    {
        posicaoColZero[i] = -2;
    }
    // Encontrar posicao zero a esquerda
    for (int i = 0; i < linha; i++)
    { // Percorrer cada linha c -> b
        for (int j = 0; j < coluna; j++)
        {
            if (matriz[i][j] == 0)
            {
                for (int k = j + 1; k < coluna; k++)
                { // Encontra o última zero a esquerda

                    if (matriz[i][k] != 0)
                    {
                        posicaoColZero[i] = k - 1;
                        break;
                    }
                    if (k == coluna - 1)
                        posicaoColZero[i] = coluna-1;
                }
                break;
            }else
                break;
        }
    }
   
    int aux = posicaoColZero[0];
    int i;
    for (i = 1; i < linha; i++)
    {
        if (posicaoColZero[i] < aux + 1)
        { // Caso não seja escada
            if (posicaoColZero[i] != coluna-1)
            {
                cout << 'N' << endl;
                break;
            }
        }
        aux = posicaoColZero[i];
    }
    if (i == linha)
        cout << 'S' << endl;
    return 0;
}