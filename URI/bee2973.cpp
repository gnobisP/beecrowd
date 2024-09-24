#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<int> pipocas;

bool possivel(long long int valor, int N, int C, int T)
{
    long long int resta = T * valor;
    int comp = 1;
    for (int i = 0; i < N; i++) // Verificar qual a quantidade de competidores eh necessário para comer a pipoca especifica.
    {
        if (resta >= pipocas[i])
        {
            resta -= pipocas[i];
        }
        else
        {
            comp++;
            resta = T * valor;
            i--;
        }
        if (comp > C)
            return false;
    }
    return true;
}

int main()
{
    int n, c, t;
    cin >> n >> c >> t;
    for (ll i = 0; i < n; i++)
    {

        int a;
        cin >> a;
        pipocas.push_back(a);
    }

    ll l = 0, r = 1e9+1;
    while (l < r)
    {
        ll m = (l + r) / 2;
        if (!possivel(m, n, c, t))
            l = m + 1;
        else
            r = m;
    }
    cout << l << endl;

    return 0;
}
