#include <bits/stdc++.h>

#define ll long long int

using namespace std;
#define dgb(x) cout << #x << " = " << x << endl // facilita MUITO o debug
const long long int MAX = 500;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

vector<vector<int>> conexoesTerminais;
int profundidade = 0;

void bfs(int inicio, int fim) {
    queue<int> fila;
    fila.push(inicio);
    vector<bool> visitados(MAX*2 + 1, false);

    while (!fila.empty()) {
        int tamanho_fila = fila.size(); 
        for (int i = 0; i < tamanho_fila; i++) {
            int atual = fila.front();
            fila.pop();

            if (atual == fim) {
                return;
            }

            for (auto n : conexoesTerminais[atual]) {
                if (!visitados[n]) {
                    fila.push(n);
                    visitados[n] = true; 
                }
            }
        }
        profundidade++; 
    }
}

int main()
{_
    int quantLinhas, quantTerminais, inicio, fim;
    cin >> quantTerminais >> quantLinhas >> inicio >> fim;
    conexoesTerminais.resize(1+quantTerminais+quantLinhas);

    for (int i = 1; i <= quantLinhas; i++)
    {
        int aux;
        cin >> aux;
        for (int j = 0; j < aux; j++)
        {
            int aux1;cin >> aux1;
            conexoesTerminais[aux1].push_back(i+quantTerminais);
            conexoesTerminais[i+quantTerminais].push_back(aux1);
        }
    }

    bfs(inicio , fim);
    cout << profundidade/2 << endl;

    return 0;
}