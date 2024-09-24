#include <bits/stdc++.h>

using namespace std;

#define dgb(x) cout << #x << " = " << x << endl;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

const int INF = 0x3f3f3f3f;
const long long int MAX = 5 + 1e5;

class No
{

public:
    int Id;
    int conC, conE;
    No(int Id, int conC, int conE) : Id(Id), conC(conC), conE(conE) {}
};

vector<int> pont(MAX, 0);

bool ordena(No a, No b)
{
    return a.Id < b.Id;
}

int bfs(vector<No> &g, int s)
{
    queue<int> q;
    int res = 0;
    q.push(s);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        auto a = g[v];

        if (a.conC != 0)
            q.push(a.conC);
        if (a.conE != 0)
            q.push(a.conE);
        pont[a.conC] = pont[v] + 1;
        pont[a.conE] = 0;
        if (a.conC != 0)
            res = max(res, pont[a.conC]);
    }

    return res;
}
int bfs2(vector<No> &g, int s)
{
    queue<int> q;
    int res = 0;
    q.push(s);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        auto a = g[v];
        if (a.conC != 0)
            q.push(a.conC);
        pont[a.conC] = pont[v] + 1;
        if (a.conC != 0)
            res = max(res, pont[a.conC]);
    }

    return res;
}

int main()
{
    _ int N;
    cin >> N;
    int I, L, K;
    vector<No> gE;
    gE.push_back(No(0, 0, 0));
    for (int i = 0; i < N; i++)
    {
        cin >> I >> L >> K;
        No aux(I, K, L);
        gE.push_back(aux);
    }

    int M;
    cin >> M;
    int P, Q, R;
    vector<No> gD;
    gD.push_back(No(0, 0, 0));
    for (int i = 0; i < M; i++)
    {
        cin >> P >> Q >> R;
        No aux(P, Q, R);
        gD.push_back(aux);
    }

    sort(gE.begin(), gE.end(), ordena);
    sort(gD.begin(), gD.end(), ordena);

    int resu1 = bfs(gD, 1);
    pont.assign(MAX, 0);
    int resu2 = bfs(gE, 1);
    pont.assign(MAX, 0);
    int resu3 = bfs2(gE, 1);
    pont.assign(MAX, 0);
    int resu4 = bfs2(gD, 1);

    int res = max(min(resu1, resu3), min(resu2, resu4));
    cout << N + M - res -1<< endl;
    return 0;
}