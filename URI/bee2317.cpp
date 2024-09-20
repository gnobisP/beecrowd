#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

const int MAX = 255;

int R, C;
bool possivel(vector<vector<int>> &g, vector<vector<bool>> &vis, int i, int j)
{
    if ((i >= 0 and i < R) and (j >= 0 and j < C))
        if ((g[i][j] != -1) and (vis[i][j] == false))
            return true;
    return false;
}

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

void floodfill(vector<vector<int>> &g, vector<vector<bool>> &vis, pair<int, int> &ans, int i, int j)
{

    int contO = 0;
    int contL = 0;

    queue<pair<int, int>> q;

    q.push({i, j});
    vis[i][j] = true;

    while (!q.empty())
    {
        auto [a, b] = q.front();
        q.pop();
        if (g[a][b] == 1)
            contO++;

        else if (g[a][b] == 2)
            contL++;

        for (int k = 0; k < 4; k++)
        {
            int ni = a + dr[k];
            int nj = b + dc[k];

            if (possivel(g, vis, ni, nj))
            {
                q.push({ni, nj});

                vis[ni][nj] = true;
            }
        }
    }

    if (contO > contL)
        ans.first += contO;
    else
        ans.second += contL;
}

int main()
{

    cin >> R >> C;
    vector<vector<int>> g(MAX, vector<int>(MAX));
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            char a;
            cin >> a;
            switch (a)
            {
            case '.':
                g[i][j] = 0;
                break;
            case '#':
                g[i][j] = -1;
                break;
            case 'k':
                g[i][j] = 1;
                break;
            case 'v':
                g[i][j] = 2;
                break;
            }
        }
    }

    vector<vector<bool>> vis(MAX, vector<bool>(MAX, false));
    pair<int, int> ans = {0, 0};
     for (int i = 0; i < R; i++)
     {
         for (int j = 0; j < C; j++)
         {
             if (possivel(g, vis, i, j))
                 floodfill(g, vis, ans, i, j);
         }
     }

    cout << ans.first << ' ' << ans.second << endl;

    return 0;
}