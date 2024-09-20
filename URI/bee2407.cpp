#include <bits/stdc++.h>

using namespace std;

#define ll long long
const long long MAX = 1005;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

int main()
{
    int N;
    cin >> N;
    ll maior = -1;
    vector<vector<ll>> g(MAX, vector<ll>(MAX));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ll a;
            cin >> a;
            g[i][j] = a;
            maior = max(maior, a);
        }
    }

    ll soma1 = 0;
    ll soma2 = 0;
    ll soma3 = 0;

    for (int i = 0; i < N; i++)
    {
        soma1 += g[i][0];
        soma2 += g[0][i];
        soma3 += g[i][i];
    }
    if (soma1 == soma2 and soma2 == soma3 and maior == N*N)
        cout << soma3 << endl;
    else
        cout << 0 << endl;
    return 0;
}
