#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX = 101;

vector<vector<int>> mapa(MAX, vector<int>(MAX, 0));

int qLinha, qColuna;
bool val(int i, int j)
{
    return (i >= 0 && i < qLinha) and (j >= 0 && j < qColuna);
}

int main()
{
    int N;
    cin >> N;
    int K;
    cin >> K;
    qLinha = N;
    qColuna = N;
    for (int i = 0; i < K; i++)
    {
        int x, y, d;
        cin >> x >> y >> d;
        int a = d, b = 0;
        while (a != -1)
        {
            vector<vector<bool>> vis(MAX, vector<bool>(MAX, false));
            if (val(x + a, y + b))
                if (!vis[x + a][y + b])
                {
                    mapa[x + a][y + b] += 1;
                    vis[x + a][y + b] = true;
                }
            if (val(x - a, y + b))
                if (!vis[x - a][y + b])
                {
                    mapa[x - a][y + b] += 1;
                    vis[x - a][y + b] = true;
                }
            if (val(x + a, y - b))
                if (!vis[x + a][y - b])
                {
                    mapa[x + a][y - b] += 1;
                    vis[x + a][y - b] = true;
                }
            if (val(x - a, y - b))
                if (!vis[x - a][y - b])
                {
                    mapa[x - a][y - b] += 1;
                    vis[x - a][y - b] = true;
                }
            a--;
            b++;
        }
    }
    int contador = 0, cx, cy;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            //cout<<mapa[i][j]<<' ';
            if(mapa[i][j] == K){
                cx = i; cy=j;
                contador++;
            }
            
        }
        //cout<<endl;

    }
    if (contador != 1)
        cout << -1 << ' ' << -1 << endl;
    else
        cout <<cx<<' '<<cy<<endl;
    return 0;
}