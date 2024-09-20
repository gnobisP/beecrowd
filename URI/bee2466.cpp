#include <iostream>
using namespace std;

int main()
{
    int quantidade;
    cin >> quantidade;
    int *vetor = new int[quantidade];

    for (int i = 0; i < quantidade; i++){//Receber os dados inicias
        cin >> vetor[i];
    }
    int *vetorAux = new int[quantidade];
    for (int i = 1; i < quantidade; i++){//Criar cada linha
        for (int j = 0; j < quantidade-i; j++){//Criar a proxima linha
            if(vetor[j] == vetor[j+1]){
                vetorAux[j] = 1;
            }else{
                vetorAux[j] = -1;
            }
        }
        for (int j = 0; j < quantidade-i; j++){//Substituir a linha antiga pela nova
            vetor[j] = vetorAux[j];
        }
    }
    
    if(vetor[0] == -1){
        cout << "branca";
    }else{
        cout << "preta";
    }
    cout << endl;
    return 0;
}