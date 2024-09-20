#include <bits/stdc++.h>

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

using namespace std;
int v, m;
const int INF = 0x3f3f3f3f;
#define ll long long

int main()
{
    vector<ll> num;
    ll N;
    cin >> N;
    for (ll i = 0; i < N; i++)
    {
        ll a;
        cin >> a;
        num.push_back(a);
    }

    ll soma = 0;
    vector<ll> modulos(8,0);
    modulos[0] = 1;
    ll ans=0;
    for (ll i = 0; i < N; i++)
    {
        soma += num[i];
        soma %= 8;
        ans += modulos[soma];
        modulos[soma]++;

    }
    cout << ans << endl;
    return 0;
}