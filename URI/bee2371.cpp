#include <bits/stdc++.h>

#define ll long long int

using namespace std;

const long long int MAX = 105;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

vector<vector<int>> matriz(MAX, vector<int>(MAX));
vector<vector<bool>> visitados(MAX, vector<bool>(MAX));

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
int qLinha, qColuna;

void floydWarshall(int a, int b, int n)
{
    queue<pair<int, int>> fila;
    fila.push(make_pair(a, b));
    while (!fila.empty())
    {
        int i, j;
        i = fila.front().first;
        j = fila.front().second;
        fila.pop();
        matriz[i][j] = n;
        for (int k = 0; k < dx.size(); k++)
        {
            if ((i + dy[k] < qLinha && i + dy[k] >= 0) and (j + dx[k] < qColuna && j + dx[k] >= 0) and matriz[i + dy[k]][j + dx[k]] == 1)
            {
                if (visitados[i + dy[k]][j + dx[k]] == false)
                {
                    visitados[i + dy[k]][j + dx[k]] = true;
                    fila.push(make_pair(i + dy[k], j + dx[k]));
                }
            }
        }
    }
}
int main()
{
    _
            cin >>
        qLinha >> qColuna;

    for (int i = 0; i < qLinha; i++)
    {
        for (int j = 0; j < qColuna; j++)
        {
            char c;
            cin >> c;
            int aux;
            if (c == '#')
                aux = 1;
            else
                aux = 0;

            matriz[i][j] = aux;
        }
    }

    int n = 0;
    for (int i = 0; i < qLinha; i++)
    {
        for (int j = 0; j < qColuna; j++)
        {
            if (visitados[i][j] == false and matriz[i][j] == 1)
            {
                n++;
                if (n == 46)
                    n++;
                floydWarshall(i, j, n);
            }
        }
    }

    int qTiros;
    cin >> qTiros;
    vector<pair<int, int>> tiros;
    for (int i = 0; i < qTiros; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        tiros.push_back(make_pair(a, b));
    }
    for (int i = 0; i < qTiros; i++)
    {
        matriz[tiros[i].first][tiros[i].second] = 0;
    }
    unordered_set<int> barcos;
    for (int i = 0; i < qLinha; i++)
    {
        for (int j = 0; j < qColuna; j++)
        {
            if (matriz[i][j] != 0)
            {
                barcos.insert(matriz[i][j]);
            }
        }
    }
    if (n >= 46)
        n--;
    cout << n - barcos.size() << endl;

    return 0;
}