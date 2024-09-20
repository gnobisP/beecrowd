#include <bits/stdc++.h>

#define ll long long int

using namespace std;

const long long int MAX = 50000;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

int main()
{
    _ int quant, times;
    cin >> quant >> times;
    vector<pair<ll, string>> jogadores;
    for (int i = 0; i < quant; i++)
    {
        ll nivel;
        string nome;
        cin >> nome >> nivel;
        jogadores.push_back(make_pair(nivel, nome));
    }
    sort(jogadores.begin(), jogadores.end(),greater<pair<ll,string>>());
    for (int aux = 0; aux < times; aux++)
    {
        cout<<"Time "<<aux+1<<endl;
        vector<string> nomes;
        for (int i = aux; i < quant; i += times)
        {
            nomes.push_back(jogadores[i].second);

        }
        sort(nomes.begin(),nomes.end());
        for(string s:nomes)
            cout<<s<<endl;
        cout<<endl;
    }
    return 0;
}