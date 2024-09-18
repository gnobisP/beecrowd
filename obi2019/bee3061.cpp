#include <bits/stdc++.h>

#define ll long long int

using namespace std;
#define dgb(x) cout << #x << " = " << x << endl // facilita MUITO o debug
const long long int MAX = 50000;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> matriz;
    for (int i = 0; i < N; i++)
    { // linhas
        vector<int> aux;
        for (int j = 0; j < M; j++)
        {
            int n_aux;
            cin >> n_aux;
            aux.push_back(n_aux);
        }
        matriz.push_back(aux);
    }
    queue<pair<int, int>> fila;
    int quantidade = 0;
    for (int linha = 0; linha < N; linha++)
    {
        for (int coluna = 0; coluna < M; coluna++)
        {
            if (matriz[linha][coluna] == 1)
            {
                fila.push(make_pair(linha, coluna));
                matriz[linha][coluna]=0;
                while (!fila.empty())
                {
                    pair<int, int> atual = fila.front();
                    fila.pop();
                    int i = atual.first;
                    int j = atual.second;
                    
                    if ((j + 1 < M) and matriz[i][j + 1] == 1)
                    {
                        fila.push(make_pair(i, j + 1));
                        matriz[i][j+1]=0;
                    }
                    if ((j - 1 >= 0) and matriz[i][j - 1] == 1)
                    {
                        fila.push(make_pair(i, j - 1));
                        matriz[i][j-1]=0;
                    }
                    if ((i + 1 < N) and matriz[i + 1][j] == 1)
                    {
                        fila.push(make_pair(i + 1, j));
                        matriz[i+1][j]=0;
                    }
                    if ((i - 1 >= 0) and matriz[i - 1][j] == 1)
                    {
                        fila.push(make_pair(i - 1, j));
                        matriz[i-1][j]=0;
                    }
                }
                quantidade++;
            }
        }
        
    }
    cout<<quantidade<<endl;
    return 0;
}