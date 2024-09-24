#include <bits/stdc++.h>

#define ll long long int

using namespace std;

const long long int MAX = 500;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
const int INF = 0x3f3f3f3f;

ll contarMatrizesQuadradas(vector<vector<int>> &matriz)
{
    ll soma = 0;
    int qColuna = matriz[0].size();
    int qLinha = matriz.size();

    vector<vector<int>> dp((qLinha), vector<int>(qColuna));

    for (ll i = 1; i < qLinha; i++)
    {
        dp[i][0] = matriz[i][0];
        soma += dp[i][0];
    }

    for (ll i = 0; i < qColuna; i++)
    {
        dp[0][i] = matriz[0][i];
        soma += dp[0][i];
    }

    for (ll i = 1; i < qLinha; i++)
    {
        for (ll j = 1; j < qColuna; j++)
        {
            if (matriz[i][j] != 0)
                dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j - 1], dp[i - 1][j]));
            soma += dp[i][j];
        }
    }
    return soma;
}
int main()
{
    _ ll N, P;
    cin >> N >> P;

    vector<vector<int>> matrizP(N, vector<int>(N, 1));
    vector<vector<int>> matrizB(N, vector<int>(N, 1));
    vector<vector<int>> matrizN(N, vector<int>(N, 1));

    for (int i = 0; i < P; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        matrizB[a][b] = 0;
        matrizN[a][b] = 0;
    }
    for (int c = 0; c < P; c++)
    {
        int i, j;
        cin >> i >> j;
        i--, j--;
        matrizP[i][j] = 0;
        matrizN[i][j] = 0;
    }

    ll p = contarMatrizesQuadradas(matrizP);
    ll b = contarMatrizesQuadradas(matrizB);
    ll n = contarMatrizesQuadradas(matrizN);

    cout << p - n << ' ' << b - n<<endl;

    return 0;
}