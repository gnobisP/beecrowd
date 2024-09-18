#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#define dgb(x) cout << #x << " = " << x << endl //facilita MUITO o debug
const long long int MAX = 50000;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

vector<ll> numeros;

ll prefixEMap(ll desejado) {
    unordered_map<ll, ll> quantSomaPrefixo;
    quantSomaPrefixo[0] = 1;

    ll quantidade = 0;
    ll soma = 0;

    for (ll n : numeros) {
        soma += n;
        ll complemento = soma - desejado;

        if (quantSomaPrefixo.find(complemento) != quantSomaPrefixo.end())
            quantidade += quantSomaPrefixo[complemento];
        
        quantSomaPrefixo[soma]++;
    }
    return quantidade;
}

int main()
{_

    ll quantidade; ll desejado;
    cin >> quantidade >> desejado;

    ll aux;
    for (ll i = 0; i < quantidade; i++)
    {
        cin >> aux;
        numeros.push_back(aux);
    }

    ll result = prefixEMap(desejado);
    cout << result << endl;

    return 0;
}