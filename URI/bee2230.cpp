#include <bits/stdc++.h>

using namespace std;
const int MAX = 52;
#define _ios_base::sync_with_stdio(0);cin.tie(0);
vector<vector<int>> con(MAX);
vector<int> dist(MAX, -1);

void bfs(int s)
{
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto u : con[v])
            if (dist[u] == -1)
            {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
    }
}
int main()
{
    int teste = 0;
    while (1)
    {
        int C, E, L, P;
        cin >> C >> E >> L >> P;
        if (C == 0 and E == 0 and L == 0 and P == 0)
            break;
        teste++;
        cout<<"Teste "<<teste<<endl;
        con.assign(MAX, vector<int>());
        dist.assign(MAX, -1);
        for (int i = 0; i < E; i++)
        {
            int a, b;
            cin >> a >> b;
            a--, b--;
            con[a].push_back(b);
            con[b].push_back(a);
        }

        bfs(L - 1);
        int iterador = 1;
        for (auto n : dist)
        {
            if (n != 0 and n != -1 and n <= P)
            {
                cout << iterador << ' ';
            }
            iterador++;
        }
        cout<<endl<<endl;
    }
    return 0;
}
