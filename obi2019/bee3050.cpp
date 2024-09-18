#include <bits/stdc++.h>

using namespace std;

int main(){
    int quantidade;cin>>quantidade;
    vector<int> andares;
    
    for(int i=0;i<quantidade;i++){
        int num;
        cin>>num;
        andares.push_back(num);
    }
    
    long long maiorDist=-3233;
    
    for(int i=0;i<quantidade;i++){
        for(int j=i;j<quantidade;j++){
            long long distancia;
            distancia = abs(i-j)+andares[j]+andares[i];
            if(distancia>maiorDist)
                maiorDist = distancia;
        }
    }
    cout<<maiorDist<<endl;
}