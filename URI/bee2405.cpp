#include <bits/stdc++.h>
#define ll long long
using namespace std;
const long long MAX = 205;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

vector<int> dr = {-1, 1, 0, 0, 1, -1, -1, 1};
vector<int> dc = {0, 0, -1, 1, 1, -1, 1, -1};

vector<vector<bool>> vis(MAX, vector<bool>(MAX, false));
vector<vector<int>> matriz(MAX, vector<int>(MAX, 0));

int qLinha, qColuna;
bool val(int i, int j)
{
    return (i >= 0 and i < qLinha) && (j >= 0 and j < qColuna) and (matriz[i][j] != -1);
}
int floodfill(int i, int j)
{
    int count = 0;
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = true;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        count++;
        for (int k = 0; k < 8; k++)
        {
            int ni = x + dr[k];
            int nj = y + dc[k];
            if (val(ni, nj) and !(vis[ni][nj]))
            {
                q.push({ni, nj});
                vis[ni][nj] = true;
            }
        }
    }
    return count;
}
int main()
{_
    cin >> qLinha >> qColuna;
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        matriz[a][b] = -1;
    }
    int resultado = floodfill(x, y);
    cout << resultado << endl;
    return 0;
}