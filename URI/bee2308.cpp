#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Edge;
typedef vector<vector<Edge>> Graph;

const int INF = 0x3f3f3f3f;

#define f first
#define s second

int dijkstra(Graph &g, int begin)
{
    priority_queue<Edge> pq;
    pq.push({-0, begin});

    vector<int> dist(g.size(), INF);

    while (!pq.empty())
    {
        int w = -pq.top().f;
        int u = pq.top().s;
        pq.pop();

        if (u == begin and w != 0)
            return w;

        if (dist[u] <= w)
            continue;
        dist[u] = w;

        for (auto [v, n_w] : g[u])
        {
            if (dist[v] > w + n_w)
            {
                pq.push({-(w + n_w), v});
            }
            else if (v == begin)
            {
                pq.push({-(w + n_w), v});
            }
        }
    }

    return INF;
}

void add_edge(Graph &g, int a, int b, int w)
{
    g[a].push_back({b, w});
}

int main()
{
    int S, C;
    cin >> S >> C;
    Graph g(S + 1);
    vector<int> tS(1);

    for (int i = 0; i < S; i++)
    {
        int a;
        cin >> a;
        tS.push_back(a);
    }

    for (int i = 0; i < C; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        add_edge(g, a, b, w + tS[a]);
    }
    int ans = INF;
    for (int i = 1; i <= S; i++)
    {
        ans = min(ans, dijkstra(g, i));
    }
    cout << ans << endl;

    return 0;
}