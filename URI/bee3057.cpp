#include <bits/stdc++.h>

#define ll int

using namespace std;
#define dgb(x) cout << #x << " = " << x << endl // facilita MUITO o debug
const long long int MAX = 100000;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

vector<ll> visitados(MAX + 1, -1);
vector<vector<ll>> implicacoes(MAX + 1);
vector<vector<ll>> conexoes(MAX + 1);
vector<ll> dependencia(MAX + 1, 0);
unordered_set<ll> premissa;

void dfs(ll inicio) {
    queue<ll> fila;
    fila.push(inicio);

    while (!fila.empty()) {
        ll atual = fila.front();
        fila.pop();

        conexoes[inicio].push_back(atual); 
        for (ll p : implicacoes[atual]) {
            if (visitados[p] != inicio) {
                fila.push(p);
                visitados[p] = inicio; 
            }
        }
    }
}

vector<ll> intersectiom(vector<ll> vetor1, vector<ll> vetor2)
{
    sort(vetor1.begin(), vetor1.end());
    sort(vetor2.begin(), vetor2.end());
    vector<ll> resposta;
    int anterior1 = -1, anterior2 = -1;
    int aux1 = 0, aux2 = 0;

    while (aux1 < vetor1.size() && aux2 < vetor2.size())
    {
        if (anterior1 == vetor1[aux1])
        {
            aux1++;
            continue;
        }

        if (anterior2 == vetor2[aux2])
        {
            aux2++;
            continue;
        }

        if (vetor1[aux1] == vetor2[aux2])
        {
            resposta.push_back(vetor1[aux1]);
            anterior1 = vetor1[aux1];
            anterior2 = vetor2[aux2];
        }

        if (vetor1[aux1] < vetor2[aux2])
        {
            anterior1 = vetor1[aux1];
            aux1++;
        }
        else
        {
            anterior2 = vetor2[aux2];
            aux2++;
        }
    }

    return resposta;
}

template <typename T>
void removerRepetidos(vector<T> &vetor)
{
    sort(vetor.begin(), vetor.end());
    // auto iterador = unique(vetor.begin(), vetor.end());
    // vetor.resize(distance(vetor.begin(), iterador));
}

int main()
{
    _
        ll L,
        I, V;
    cin >> L >> I >> V;

    // Inicializar premissa
    for (ll i = 1; i <= L; i++)
        premissa.insert(i);

    // Leitura dependencia
    for (ll i = 0; i < I; i++)
    {
        ll aux, aux1;
        cin >> aux >> aux1;
        implicacoes[aux].push_back(aux1);
        dependencia[aux1]++;
        premissa.erase(aux1);
    }

    // Leitura Verdadeiros
    vector<ll> verdadeiro;
    for (ll i = 0; i < V; i++)
    {
        ll aux;
        cin >> aux;
        verdadeiro.push_back(aux);
    }

    for (ll n : premissa)
    {
        if (visitados[n] == -1)
        {
            dfs(n);
            
        }
    }

    unordered_set<ll> resposta;

    for (ll v : verdadeiro)
    {
        bool first = true;
        vector<ll> vetor1;

        for (auto aux : premissa)
        {
            if (find(conexoes[aux].begin(), conexoes[aux].end(), v) != conexoes[aux].end())
            {
                if (first == true)

                    vetor1 = conexoes[aux];
                else
                    vetor1 = intersectiom(vetor1, conexoes[aux]);

                first = false;
            }
        }

        for (ll con : vetor1)
            resposta.insert(con);
    }

    vector<int> respAux(resposta.begin(), resposta.end());
    sort(respAux.begin(), respAux.end());

    bool primeiraVez = true;
    for (auto n : respAux)
    {
        if(primeiraVez)
         cout<<n;
        else
         cout << ' ' << n;
        primeiraVez = false;
    }
    cout << endl;
    return 0;
}