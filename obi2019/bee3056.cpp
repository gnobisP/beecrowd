#include <bits/stdc++.h>

using namespace std;

int main(){
    int quant;
    cin>>quant;
    long long res = 2;
    for(int i=0;i<quant;i++){
        res += pow(2,i);
    }
    res*=res;
    cout<<res<<endl;
    return 0;
}