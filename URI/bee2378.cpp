#include <bits/stdc++.h>

#define ll long long int

using namespace std;

const long long int MAX = 50000;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

int main()
{_ 
    int quant,cap;cin>>quant>>cap;
    int resultado = 0;
    for(int n=0;n<quant;n++){
        int S,E;cin>>S>>E;
        resultado+=E-S;
        if(resultado>cap)
        {
            cout<<'S'<<endl;
            return 0;
        }
    }
    cout<<'N'<<endl;
    return 0;
}