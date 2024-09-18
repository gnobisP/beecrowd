#include <bits/stdc++.h>

#define ll long long int

using namespace std;
#define dgb(x) cout << #x << " = " << x << endl // facilita MUITO o debug
const long long int MAX = 500000;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

int main()
{_
    int quantCartas, quantRest;
    cin >> quantCartas >> quantRest;
    vector<pair<int, int>> restricoes;
    vector<int> numeros;
    for (int i = 1; i <= quantCartas; i++)
    {
        numeros.push_back(i);
    }
    int quantRemovidos = 0;

    for (int i = 0; i < quantRest; i++)
    {
        int upa1, upa2;
        cin >> upa1 >> upa2;
        if (upa1 < upa2)
            swap(upa1, upa2);
        pair<int, int> aux(upa1, upa2);
        restricoes.push_back(aux);
    }
    sort(restricoes.begin(), restricoes.end(), greater<pair<int, int>>());

    for (auto [a, b] : restricoes)
    {
        if (numeros[a - 1] != -1 and numeros[b - 1] != -1)
        {
            numeros[b - 1] = -1;
            quantRemovidos++;
        }
    }
    cout << quantCartas - quantRemovidos << endl;
    bool primeiro = true;
    for (auto a : numeros)
    {
        if (a != -1)
        {
            if (!primeiro)
                cout << ' ';
            
            cout << a;
            primeiro = false;
        }
    }

    cout << endl;
    return 0;
}