#include <bits/stdc++.h>

#define ll long long int

using namespace std;

const long long int MAX = 1001;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

vector<int> dr = {-1, 1, 0, 0};
vector<int> dc = {0, 0, -1, 1};
vector<vector<int>> vis(MAX, vector<int>(MAX, 0));
vector<vector<char>> lago(MAX, vector<char>(MAX));
int qLinha, qColuna;

bool val(int i, int j)
{
    return (i >= 0 && i < qLinha) && (j >= 0 && j < qColuna) && (lago[i][j] == '1');
}

void floodfillbfs(int i, int j)
{
    int ultimoX = i, ultimoY = j;

    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = 1;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; ++k)
        {
            int ni = x + dr[k];
            int nj = y + dc[k];
            if (val(ni, nj) and !(vis[ni][nj]))
            {
                q.push({ni, nj});
                vis[ni][nj] = 1;
                ultimoX = ni, ultimoY = nj;
            }
        }
    }
    cout << ultimoX + 1 << ' ' << ultimoY + 1<<endl;
}

int main()
{
    cin >> qLinha >> qColuna;
    int I, J;
    cin >> I >> J;
    I--,J--;
    for (int i = 0; i < qLinha; i++)
        for (int j = 0; j < qColuna; j++)
            cin >> lago[i][j];

    floodfillbfs(I, J);

    return 0;
}
