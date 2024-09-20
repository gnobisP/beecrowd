#include <bits/stdc++.h>

#define ll long long int

using namespace std;

const long long int MAX = 50000;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

int main(){_
    int quantidade; cin>>quantidade;
    int contagem = 0;
    int anterior = -1;
    for(int i=0;i<quantidade;i++){
        int aux;cin>>aux;
        if(aux != anterior){
            anterior = aux;
            contagem++;
        }
    }
    cout<<contagem<<endl;
    return 0;
}