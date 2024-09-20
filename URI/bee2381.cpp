#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, M; cin>>N>>M;
    vector<string>nomes;
    while(N--){
        string a; cin>>a;
        nomes.push_back(a);
    }
    sort(nomes.begin(), nomes.end());
    cout<<nomes[M-1]<<endl;
    return 0;
}