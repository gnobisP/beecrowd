#include <bits/stdc++.h>

using namespace std;
const int MAX = 10005;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define ll long long
ll C, T;

bool possivel(ll r1, double r2)
{
    if (r1 >= r2)
        return false;
    return true;
}

ll buscaBinaria(ll x, ll y, vector<ll> &r)
{

    double raio = sqrt(x * x + y * y);
    int right = C, left = 0;
    while (right > left)
    {
        int middle = (right + left) / 2;
        if (possivel(r[middle], raio))
            left = middle + 1;
        else
            right = middle;
    }
    return C - left;
}
int main()
{
    cin >> C >> T;

    vector<ll> raios;

    for (ll i = 0; i < C; i++)
    {
        ll r;
        cin >> r;
        raios.push_back(r);
    }
    ll pont = 0;
    while (T--)
    {
        ll x, y; cin >> x >> y;
        pont += buscaBinaria(x, y, raios);
    }
    cout << pont << endl;

    return 0;
}