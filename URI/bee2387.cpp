#include <bits/stdc++.h>

#define ll long long int

using namespace std;

const long long int MAX = 50000;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

bool cmp(pair<int,int> a, pair<int,int> b){
 if(a.second != b.second)
     return a.second<b.second;

 else
     return a.first<b.first;
}
int main()
{
    vector<pair<int,int>> horarios;
    int quant;cin>>quant;
    for(int i=0;i<quant;i++){
        int a,b;cin>>a>>b;
        horarios.push_back(make_pair(a,b));
    }
    sort(horarios.begin(), horarios.end(),cmp);
    int ultimoHorario = -1;
    int resultado = 0;
    for(auto[a,b]: horarios){
        if(ultimoHorario<=a){
            ultimoHorario = b;
            resultado++;
        }
    }
    cout<<resultado<<endl;
    return 0;
}