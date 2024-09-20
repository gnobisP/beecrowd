#include <bits/stdc++.h>

using namespace std;
const int MAX = 10005;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);


vector<vector<int>> adj(MAX);
vector<bool> fim(MAX, false);

int N;
void add_aresta(int a, int b)
{
    a--;
    b--;
    adj[a].push_back(b);
}
int bfs(int s)
{
    int ans = 1;
    queue<int> q;
    vector<bool> vis(MAX, false);
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
                if (fim[u] == true)
                {
                    return N;
                }
                q.push(u);
                vis[u] = true;
                ans++;
            }
        }
    }
    return ans;
}
int main()
{
    _ 
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        add_aresta(a, b);
    }

    bfs(0);

    for (int i = 0; i < N; i++)
    {
        if (N != bfs(i))
        {
            cout << 'N' << endl;
            return 0;
        }
        fim[i] = true;
    }
    cout << 'S' << endl;
    return 0;
}