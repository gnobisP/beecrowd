#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; // Lista de adjacência
vector<int> inDegree;     // Grau de entrada de cada vértice
vector<int> topsort;      // Ordenação topológica dos vértices

bool TopologicalSort(vector<int> &resposta, int N)
{
    priority_queue<int, vector<int>, greater<int>> S;
    for (int v = 0; v < N; v++)
    {
        if (inDegree[v] == 0)
            S.push(v);
    }
    int t = 0;
    while (!S.empty())
    {
        int v = S.top();
        S.pop();
        topsort[v] = t;
        resposta[t++] = v;
        for (int w : adj[v])
        {
            inDegree[w]--;
            if (inDegree[w] == 0)
                S.push(w);
        }
    }
    return t == N;
}

int main()
{
    int N, M;
    cin >> N >> M;

    adj.resize(N); 
    inDegree.assign(N, 0);
    topsort.assign(N, 0);

    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        inDegree[B]++;
    }

    vector<int> resposta(N);
    bool aux = TopologicalSort(resposta, N);
    if (!aux)
        cout << '*' << endl;
    else
        for (int i = 0; i < N; i++)
            cout << resposta[i] << endl;

    return 0;
}
