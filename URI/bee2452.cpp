#include <iostream>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    long long int quant;
    cin >> quant;
    int quantGotas;
    cin >> quantGotas;

    queue<int> fila;
    set<int> temporario;
    vector<bool> fita(quant, false);

        for (int i = 0; i < quantGotas; i++)
    {
        long long int num;
        cin >> num;
        num--;
        temporario.insert(num);
        fita[num] = true;
    }
    vector<bool> visitados(quant, false);

    long long int dias = 0;

    while (!temporario.empty())
    {
        bool modificou = false;
        for (auto c : temporario)
        { // descarregar c em temporario
            fila.push(c);
        }
        temporario.clear();

        while (!fila.empty())
        {
            int atual;
            atual = fila.front();
            fila.pop();

            visitados[atual] = true;
            
            if (atual + 1 < quant && visitados[atual + 1] == false)
            {
                temporario.insert(atual + 1);
                if(fita[atual+1] == false)
                    modificou = true;
                fita[atual+1] = true;
            }

            if (atual > 0 && visitados[atual - 1] == false)
            {
                temporario.insert(atual - 1);
                if(fita[atual-1] == false)
                    modificou = true;
                fita[atual-1] = true;
            }
            
        }
        if (modificou)
            dias++;
    }
    cout << dias << endl;

    return 0;
}