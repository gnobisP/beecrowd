#include <bits/stdc++.h>

using namespace std;

int n, m; // número de vértices e de arestas do grafo

vector<int> id, sz;
vector<tuple<int, int, int>> g;     // Vetor para armazenar as arestas da AGM
vector<vector<pair<int, int>>> agm; // Vetor para armazenar a árvore geradora mínima

const int INF = 0x3f3f3f3f;

int find(int x)
{
    return id[x] = (id[x] == x ? x : find(id[x]));
}

void uni(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    if (sz[x] > sz[y])
        swap(x, y);
    id[x] = y;
    sz[y] += sz[x];
}

void AGMKruskal(int n, int m)
{
    id = vector<int>(n);
    sz = vector<int>(n, 1);
    g = vector<tuple<int, int, int>>();
    agm = vector<vector<pair<int, int>>>(n);

    iota(id.begin(), id.end(), 0);

    while (m--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        g.emplace_back(w, a, b);
    }
    sort(g.begin(), g.end());
    for (auto [w, a, b] : g)
    {
        if (find(a) != find(b))
        {
            uni(a, b);
            agm[a].push_back({b, w});
            agm[b].push_back({a, w});
        }
    }
}

int bfs()
{
    queue<int> q;
    q.push(0);
    vector<bool> vis(n, false);
    int ans = 0;

    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        vis[u] = true;

        for (auto [v, w] : agm[u])
        {
            if (vis[v] == false)
            {
                ans += w;
                q.push(v);
            }
        }
    }

    return ans;
}

int main()
{
    cin >> n >> m;
    AGMKruskal(n, m);

    int result = bfs();
    cout << result << endl;

    return 0;
}
