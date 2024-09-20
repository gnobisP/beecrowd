#include <bits/stdc++.h>
using namespace std;
int main()
{
    int E, L;
    int aux = 0;
    while (1)
    {
        cin >> E >> L;
        if (E == 0 and L == 0)
            break;
        aux++;
        cout<<"Teste "<<aux<<endl;
        vector<vector<int>> con(E);
        vector<bool> vis(E);

        // recebendo entradas
        for (int i = 0; i < L; i++)
        {
            int x, y;
            cin >> x >> y;
            x--;y--;
            con[x].push_back(y);
            con[y].push_back(x);
        }

        // criando a bfs
        queue<int> q;
        q.push(0);vis[0]=true;
        while(!q.empty()){
            int v = q.front();q.pop();
            for(auto u :con[v]){
                if(!vis[u]){
                    q.push(u);vis[u]=1;
                }
            }
        }

        bool aux = false;
        for (int i = 0; i < E; i++)
        {
            if (vis[i] == false)
            {
                aux = true;
                break;
            }
        }
        if (aux)
            cout << "falha" << endl;
        else
            cout << "normal" << endl;
        cout<<endl;
    }
    return 0;
}