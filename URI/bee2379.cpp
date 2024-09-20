#include <bits/stdc++.h>

#define ll long long int

using namespace std;

const long long int MAX = 100000;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);


int main(void)
{
    vector<pair<int, int>> indios;
    set<int> ocupadas;
    int quantT;
    cin >> quantT;
    int quantI;
    cin >> quantI;
    for (int i = 0; i < quantI; i++)
    {
        int V, D;
        cin >> V >> D;
        V--;
        indios.push_back(make_pair(V, D));
        ocupadas.insert(V);
    }
    ll distancia = 0x3f3f3f3f;
    for (auto c : ocupadas)
    {
        set<int> batidas;
        ll distanciaPrim = (indios[0].second * (c-indios[0].first) + quantT - 1) % quantT + 1;
        for (int i = 0; i < quantI; i++)
        {
            batidas.insert((indios[i].first + distanciaPrim * indios[i].second + quantT) % quantT);
        }
        if (batidas == ocupadas)
        {
            distancia = min(distancia, distanciaPrim);
        }
    }
    cout << distancia << endl;

    return 0;
}
