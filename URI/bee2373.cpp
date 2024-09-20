#include <bits/stdc++.h>

#define ll long long int

using namespace std;

const long long int MAX = 50000;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

int main()
{_ 
    int N; cin>>N;
    int L,C; 
    int resultado = 0;

    for(int quant=0;quant<N;quant++){
        cin>>L>>C;  
        if(L>C)
            resultado+=C;
    }
    cout<<resultado<<endl;

    return 0;
}