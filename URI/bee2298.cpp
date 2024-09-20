#include <bits/stdc++.h>
using namespace std;
int main()
{
    int aux;
    cin >> aux;
    for (int i = 0; i < aux; i++)
    {
        cout<<"Teste "<<i+1<<endl;
        int pontuacao = 0;
        vector<int> cartas;
        for (int i = 0; i < 5; i++)
        {
            int c;
            cin >> c;
            cartas.push_back(c);
        }
        sort(cartas.begin(), cartas.end());

        // verificar sequencia
        int primeira = cartas[0];
        bool sequencia = true;
        for (int i = 1; i < 5; i++)
        {
            if (cartas[i] - primeira != i)
                sequencia = false;
        }
        if (sequencia)
        {
            pontuacao += 200 + primeira;
            cout << pontuacao << endl<<endl;
            continue;
        }

        // Verifica quadra
        if (cartas[1] == cartas[2] and (cartas[0] == cartas[3] or cartas[1] == cartas[4]))
        {
            pontuacao += 180 + cartas[1];
            cout << pontuacao << endl<<endl;
            continue;
        }

        // verificar trio
        int aux1 = cartas[2];
        int repetidos = 0;
        for (int i = 0; i < 5; i++)
        {
            if (cartas[i] == aux1)
                repetidos++;
        }
        if (repetidos == 3)
        {
            bool par = false;
            // procura par
            if (cartas[1] == cartas[2])
            {
                if (cartas[3] == cartas[4])
                    par = true;
            }
            else
            {
                if (cartas[0] == cartas[1])
                    par = true;
            }
            if (par)
            {
                pontuacao += cartas[2] + 160;
                cout << pontuacao << endl<<endl;
            }
            else
            {
                pontuacao += cartas[2] + 140;
                cout << pontuacao << endl<<endl;
            }
            continue;
        }

        // buscando pares
        vector<vector<int>> grafo(5);
        for (int i = 0; i < 5; i++)
        {
            grafo[i].push_back(cartas[i]);
        }
        int quantPares = 0;
        int valorPar1 = -1;
        int valorPar2 = -1;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (cartas[i] == cartas[j] and i != j)
                {
                    if (valorPar1 == -1)
                        valorPar1 = cartas[j];
                    else
                    {
                        if (cartas[j] != valorPar1)
                            valorPar2 = cartas[j];
                    }
                    grafo[i].push_back(cartas[j]);
                    quantPares++;
                }
            }
        }
        if (quantPares == 4)
        {
            pontuacao += max(valorPar1, valorPar2) * 3 + 2 * min(valorPar1, valorPar2) + 20;
            cout << pontuacao << endl<<endl;
        }
        else
        {
            pontuacao += max(valorPar1, valorPar2);
            if (pontuacao == -1)
                cout << 0 << endl<<endl;
            else
                cout << pontuacao << endl<<endl;
        }
    }
    return 0;
}