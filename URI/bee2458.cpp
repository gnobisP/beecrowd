#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
const int MAX = 500;
vector<string> tabuleiro(MAX);
vector<vector<bool>> visitados(MAX, vector<bool>(MAX, false));
vector<vector<bool>> invalidos(MAX, vector<bool>(MAX, false));
int descobreCaminho(int tamanho)
{
    long long int caminhos = 0;
    bool cont = false;
    int i, j;
    int cop_i = 0;
    int cop_j = 0;

    long long int quant = 0;
    for (i = 0; i < tamanho; i++) // descobre próximo caminho
    {
        cont = false;
        for (j = 0; j < tamanho; j++)
        {
            if (visitados[i][j] == false)
            {
                cop_i = i;
                cop_j = j;
                quant = 0;
                queue<pair<int, int>> filaInvalido;
                while (1) // percorre os caminhos
                {
                    if (visitados[cop_i][cop_j] == true)
                    {                                           // ponto já visitado
                        if (!(invalidos[cop_i][cop_j] == true)) // ponto Valido
                            caminhos += quant;
                        break;
                    }

                    visitados[cop_i][cop_j] = true;
                    int i_a = cop_i;
                    int j_a = cop_j;
                    switch (tabuleiro[cop_i][cop_j])
                    {
                    case 'A':
                        cop_i--;
                        break;
                    case 'V':
                        cop_i++;
                        break;
                    case '>':
                        cop_j++;
                        break;
                    case '<':
                        cop_j--;
                        break;
                    }
                    pair<int, int> pontoInvalido = {i_a, j_a};
                    filaInvalido.push(pontoInvalido);
                    if ((!(cop_i >= 0 && cop_i < tamanho && cop_j >= 0 && cop_j < tamanho)) or invalidos[cop_i][cop_j] == true)
                    {
                        while (!filaInvalido.empty())
                        { // descarregar fila
                            pair<int, int> c = filaInvalido.front();
                            invalidos[c.first][c.second] = true;
                            filaInvalido.pop();
                        }
                        break;
                    }
                    quant++;
                }
            }
        }
    }
    return caminhos;
}

int main()
{
    int tam;
    cin >> tam;

    for (int i = 0; i < tam; i++)
    {
        getline(cin >> ws, tabuleiro[i]);
    }

    for (int i = 0; i < tam; i++)
    {
        vector<bool> aux(tam, false);
        visitados.push_back(aux);
    }
    int posValidas = descobreCaminho(tam);
    cout << posValidas << endl;

    return 0;
}