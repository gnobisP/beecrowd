#include <iostream>
using namespace std;

int main()
{
    int quantNotas;
    cin >> quantNotas;

    int *notas = new int[quantNotas];
    int *repeticao = new int[quantNotas];

    for (int i = 0; i < quantNotas; i++){
        cin >> notas[i];  // recebe notas
        repeticao[i] = 0; // zera repeticao
    }

    int maiorQuantRepeticao = 0;
    for (int i = 0; i < quantNotas; i++){ // conta repeticoes e encontra o maior valor
        for (int j = 0; j < quantNotas; j++){
            if (notas[i] == notas[j]){
                repeticao[i]++;
                if (maiorQuantRepeticao < repeticao[i])
                    maiorQuantRepeticao = repeticao[i];
            }
        }
    }

    int notaMaisRepetida = -1;
    for (int i = 0; i < quantNotas; i++){//achar nota mais repetidas
        if (maiorQuantRepeticao == repeticao[i] && notaMaisRepetida < notas[i])
            notaMaisRepetida = notas[i];
    }

    cout<<notaMaisRepetida<<endl;
    
    return 0;
}