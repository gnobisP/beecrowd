#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int cr[] = {0, 0, 1, 1, 2, 2, 3, 4, 5, 6};
int cl[] = {1, 4, 2, 5, 3, 6, 7, 5, 6, 7};

struct VectorHasher
{
    int operator()(const vector<int> &V) const
    {
        int hash = V.size();
        for (auto &i : V)
        {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

int shortestPath(vector<int> &ci, vector<int> &cf)
{
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;
    unordered_map<vector<int>, int, VectorHasher> distancia;
    pq.push(make_pair(0, ci));
    distancia[ci] = 0;

    while (!pq.empty())
    {
        pair<int, vector<int>> u = pq.top();
        pq.pop();

        if (u.second == cf)
            return u.first;

        for (int i = 0; i < 10; i++)
        {
            int NCusto = u.first + u.second[cr[i]] + u.second[cl[i]];
            vector<int> NEstado = u.second;
            swap(NEstado[cr[i]], NEstado[cl[i]]);
            if (!distancia.count(NEstado) || NCusto < distancia[NEstado])
            {
                pq.push({NCusto, NEstado});
                distancia[NEstado] = NCusto;
                
            }
        }
    }
    return INF;
}
int main()
{
    vector<int> inicial;
    vector<int> fim;
    int a;

    for (int i = 0; i < 8; i++)
    {
        cin >> a;
        inicial.push_back(a);
    }

    for (int i = 0; i < 8; i++)
    {
        cin >> a;
        fim.push_back(a);
    }
    cout<<shortestPath(inicial, fim)<<endl;
    return 0;
}