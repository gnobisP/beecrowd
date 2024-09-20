#include <bits/stdc++.h>

using namespace std;

#define dgb(x) cout << #x << " = " << x << endl;

const int INF = 0x3f3f3f3f;
const long long int MAX = 2002;

int main()
{
    int N, M;
    int L, C;
    cin >> N >> M;
    
    cin >> L >> C;
    vector<vector<int>> matriz(MAX, vector<int>(MAX, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int aux;
            if (j == 0)
                cin >> matriz[i][j];
            else
            {
                cin >> aux;
                matriz[i][j] = matriz[i][j - 1] + aux;
            }
        }
    }

    int maiorSoma = -1;
    for (int i = 0; i <= N - L; i+=L)
    {
        for (int j = 0; j <= M - C; j+=C)
        {
            int aux = 0;
            for (int k = i; k < i + L; k++)
            {
                aux += matriz[k][j + C - 1];
                if (j > 0)
                {
                    aux -= matriz[k][j - 1];
                }
            }
            maiorSoma = max(maiorSoma, aux);

        }
    }
    cout << maiorSoma << endl;

    return 0;
}