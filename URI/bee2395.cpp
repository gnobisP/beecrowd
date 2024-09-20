#include <bits/stdc++.h>
using namespace std;
int main(){
    long long A,B,C; cin>>A>>B>>C;
    long long X,Y,Z;cin>>X>>Y>>Z;
    long long resultado = ceil(X/A) * ceil(Y/B)*ceil(Z/C);
    cout<<resultado<<endl;
}