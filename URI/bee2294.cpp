#include <bits/stdc++.h>
using namespace std;
vector<int> dr = {-1,1,0,0};
vector<int> dc = {0,0,-1,1};

const int MAX  = 20;

int qLinha,qColuna;
vector<vector<int>> vis(MAX,vector<int>(MAX,0));
vector<vector<int>> lago(MAX,vector<int>(MAX));
vector<vector<int>> dist(MAX,vector<int>(MAX,-1)); 

bool val(int i, int j){
    return (i>= 0 && i <qLinha) && (j>=0 && j<qColuna) && (lago[i][j] != 2);
}
int floodfillbfs(int i, int j){
    int count = 0;
    queue<pair<int,int>> q;
    q.push({i,j});
    vis[i][j] = 1;
    dist[i][j] = 0; 
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        count++;
        for(int k=0;k<4;++k){
            int ni = x+dr[k];
            int nj = y+dc[k];
            if(val(ni,nj) and !(vis[ni][nj])){
                if(lago[ni][nj] == 0)
                    return dist[x][y] + 1;
                q.push({ni,nj});
                vis[ni][nj] = 1;
                dist[ni][nj] = dist[x][y] + 1;
            }
        }
    }
    return -1;
}
int main(){
    int linhai,colunai;
    cin>>qLinha>>qColuna;

    for(int i=0;i<qLinha;i++){
        for(int j=0;j<qColuna;j++){
            int aux;cin>>aux;
            if(aux == 3){
                linhai = i;
                colunai = j;
            }

            lago[i][j]=aux;
        }
    }

    int resultado = floodfillbfs(linhai,colunai);
    cout<<resultado<<endl;

    return 0;

}