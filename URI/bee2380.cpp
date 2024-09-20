#include <bits/stdc++.h>

#define ll long long int

using namespace std;

const long long int MAX = 100000;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

vector<ll> bancos(MAX + 1);
vector<ll> sz(MAX + 1, 1);


int find(int p)
{ // O(a(N)) amortizado
    return bancos[p] = (bancos[p] == p ? p : find(bancos[p]));
}

void uni(int p, int q)
{ // O(a(N)) amortizado
    p = find(p), q = find(q);
    if (p == q)
        return;
    if (sz[p] > sz[q])
        swap(p, q);
    bancos[p] = q, sz[q] += sz[p];
}
int main()
{
    _ ll qBanco, operacoes;
    cin >> qBanco >> operacoes;
    for (ll i = 1; i <= qBanco; i++)
    {
        bancos[i] = i;
    }
    for (ll i = 0; i < operacoes; i++)
    {
        char c;
        ll banc1, banc2;
        cin >> c >> banc1 >> banc2;
        if (c == 'C')
        {
            if (find(banc1) != find(banc2))
                cout << 'N' << endl;
            else
                cout << 'S' << endl;
        }
        else
        {
            uni(banc1, banc2);
        }
    }
    return 0;
}