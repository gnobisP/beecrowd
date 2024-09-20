#include <bits/stdc++.h>

#define ll long long int

using namespace std;

const long long int MAX = 50000;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
const int INF = 0x3f3f3f3f;

vector<vector<int>> floydWarshall(const vector<vector<int>> &cidades)
{
    vector<vector<int>> resultado = cidades;
    for (int k = 0; k < resultado[0].size(); k++)
    {
        for (int i = 0; i < resultado[0].size(); i++)
        {
            for (int j = 0; j < resultado[0].size(); j++)
            {

                if (resultado[i][j] > (resultado[i][k] + resultado[k][j]) && (resultado[k][j] != INF && resultado[i][k] != INF))
                    resultado[i][j] = resultado[i][k] + resultado[k][j];
            }
        }
    }
    return resultado;
}
int calculaMenorLinha(const vector<vector<int>> &matriz)
{
   int menor = INF;

	for(int i = 0; i < matriz.size(); i++){
		int maior = -1;
		for(int j = 0; j < matriz.size(); j++){
			maior = max(maior, matriz[j][i]);
		}
		if(maior < menor){
			menor = maior;
		}
	}
    return menor;
}

int main()
{_ 
    int N, M; cin >> N >> M;
    vector<vector<int>> cidades(N, vector<int>(N, INF));
    for(int i=0;i<N;i++){
        cidades[i][i]=0;
    }
    for (int i = 0; i < M; i++)
    {
        int U, V, W;
        cin >> U >> V >> W;
        cidades[U][V] = min(cidades[U][V], W);
        cidades[V][U] = min(cidades[V][U], W);
    }

    vector<vector<int>> matrizD1 = floydWarshall(cidades);
    int resposta = calculaMenorLinha(matrizD1);
    cout << resposta << endl;
    return 0;
}