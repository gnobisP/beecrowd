#include <bits/stdc++.h>
using namespace std;
int main() {

    int n;cin>>n;
    int pontCarlos; cin>>pontCarlos;
    bool venceu = true;
    for(int i=1;i<n;i++){
        int aux;cin>>aux;
        if(aux>pontCarlos){
            venceu = false;
        }
    }
    if(venceu)
        cout<<"S"<<endl;
    else
        cout<<"N"<<endl;
 
    return 0;
}
