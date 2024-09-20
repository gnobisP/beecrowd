#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

const int MAX = 2005;

vector<vector<int>> G(MAX);
vector<int> dist(MAX, -1);

void add_aresta(int a, int b)
{
    G[a].push_back(b);
}

int bfs(int ori, int dest)
{
    queue<int> q;
    q.push(ori);
    dist[ori] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : G[u])
        {

            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
                if (v == dest)
                    return dist[v];
            }
        }
    }
    return -1;
}

int main()
{_
    int N; cin >> N;
    cin.ignore();

    map<string, int> palavras;
    set<string> cont_ind;
    string linha;
    int index = 0;
    for (int i = 0; i < N; i++)
    {
        getline(cin, linha);
        stringstream ss(linha);

        string palavra1, palavra2;
        ss >> palavra1 >> palavra2;

        cont_ind.insert(palavra1);
        cont_ind.insert(palavra2);

        if (palavras.find(palavra1) == palavras.end())
        {
            palavras[palavra1] = index;
            index++;
        }

        if (palavras.find(palavra2) == palavras.end())
        {
            palavras[palavra2] = index;
            index++;
        }

        int a, b;
        a = palavras[palavra1];
        b = palavras[palavra2];
        add_aresta(a, b);
    }

    int anterior = -1;

    for (auto s : cont_ind)
    {
        int atual = palavras[s];
        if (anterior != -1)
        {
            G[anterior].push_back(atual);
            G[atual].push_back(anterior);
        }
        anterior = atual;
    }

    string busca1, busca2;
    cin.ignore();
    cin >> busca1 >> busca2;
    int chave1 = palavras[busca1], chave2 = palavras[busca2];

    int ans = bfs(chave1, chave2);
    cout << ans << endl;

    return 0;
}
