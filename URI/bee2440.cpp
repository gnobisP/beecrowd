#include <bits/stdc++.h>

using namespace std;
const int MAX = 100005;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

vector<vector<int>> adj(MAX);
vector<bool> vis(MAX, false);

void add_aresta(int a, int b)
{
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
}
void bfs(int s)
{
    int ans = 1;
    queue<int> q;

    q.push(s);
    vis[s] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto u : adj[v])
        {
            if (!vis[u])
            {
                q.push(u);
                vis[u] = true;
            }
        }
    }
    return;
}
int main()
{_ 
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        add_aresta(a, b);
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (vis[i] == false)
        {
            bfs(i);
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}