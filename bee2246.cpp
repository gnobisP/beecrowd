#include <bits/stdc++.h>

#define ll long long int

using namespace std;

const long long int MAX = 500;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
const int INF = 0x3f3f3f3f;

vector<vector<int>> matriz(MAX, vector<int>(MAX));
vector<vector<int>> vis(MAX, vector<int>(MAX, 0));
int H, L;

vector<int> dr = {-1, 1, 0, 0};
vector<int> dc = {0, 0, -1, 1};
bool val(int i, int j, int cor)
{
    return (i >= 0 && i < H) && (j >= 0 && j < L) && matriz[i][j] == cor;
}

int floodfillbfs(int i, int j, int cor)
{
    int count = 0;
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = 1;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        count++;

        for (int k = 0; k < 4; ++k)
        {
            int ni = x + dr[k];
            int nj = y + dc[k];
            if (val(ni, nj, cor) and !(vis[ni][nj]))
            {
                q.push({ni, nj});
                vis[ni][nj] = 1;
            }
        }
    }

    return count;
}
int main()
{
    cin >> H >> L;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < L; j++)
        {
            cin >> matriz[i][j];
        }
    }

    int resultado = INF;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < L; j++)
        {
            if (vis[i][j]==0)
                resultado = min(floodfillbfs(i, j, matriz[i][j]), resultado);
        }
    }
    cout<<resultado<<endl;

    return 0;
}