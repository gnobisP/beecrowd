#include <bits/stdc++.h>

#define ll long long int

using namespace std;

const long long int MAX = 100000;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

int main()
{_ 
    ll N;cin>>N;
    ll P,Q,R,S,X,Y;cin>>P>>Q>>R>>S>>X>>Y;
    ll I,J; cin>>I>>J;

    vector<ll> linhaA(N);
    for(int k=1;k<=N;k++){
        ll resultado = (P*I+Q*k)%X;
        linhaA[k-1] = resultado;
    }

    vector<ll> colunaB(N);
    for(int k=1;k<=N;k++){
        ll resultado = (R*k+S*J)%Y;
        colunaB[k-1] = resultado;
    }

    ll resultado = 0;
    for(int k=0;k<N;k++){
        resultado += linhaA[k]*colunaB[k];
    }

    cout<<resultado<<endl;



    return 0;
}