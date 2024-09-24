#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int INF = 0x3f3f3f3f;
const int MAX = 2000;

vector<vector<int>> G;
vector<bool> vis;
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int bfs(int N)
{
    int ans = 1;
    queue<int> q;
    q.push(N);
    vis[N] = true;
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        for (int u : G[a])
        {
            if (!vis[u])
            {
                q.push(u);
                vis[u] = true;
                ans++;
            }
        }
    }
    return ans;
}

void add_aresta(int v, int w, int p)
{
    v--;
    w--;
    if (p == 1)
    {
        G[v].push_back(w);
    }
    else
    {
        G[v].push_back(w);
        G[w].push_back(v);
    }
}
void solve(int N, int M)
{
    G.assign(N, vector<int>());

    for (int i = 0; i < M; i++)
    {
        int V, W, P;
        cin >> V >> W >> P;
        add_aresta(V, W, P);
    }

    bool res = true;
    for (int i = 0; i < N; i++)
    {
        vis.assign(N, false);
        int ans = bfs(i);
        // cout<<ans<<endl;

        if (ans != N)
        {
            res = false;
            break;
        }
    }

    if (res)
        cout << 1 << endl;
    else
        cout << 0 << endl;
}
int main()
{_
    int N, M;
    while (cin >> N >> M)
    {
        if (N == 0 and M == 0)
            break;
        solve(N, M);
    }

    return 0;
}
