#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;

vector<int> plantas(MAX,0);
int N, K; 
#define ll long long

int main(){
    cin>>N>>K;
    for(int i=0;i<K;i++){
        int a; cin>>a;
        plantas[a]++;
    }
    
    ll auxDias = 0;
    ll ans = 0;
    for(int i=0; i<N; i++){
        char c; cin>>c;
        if(c == 'C')
            auxDias++;
        else
            auxDias--;
        
        for(int i=0; i<100; i++){
            if(auxDias + i == 0){
              plantas[i]=0;
            }
            ans += plantas[i]*(i+auxDias);
        }
    }
    cout<<ans<<endl;
    
    return 0;
}