#include <bits/stdc++.h>

#define ll long long int

using namespace std;

const long long int MAX = 50000;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

int main()
{_ 
    int L,A,P,R;cin>>L>>A>>P>>R;
    double resultado = L*L+A*A+P*P;
    double resultado1 = R*R*4;
    if(resultado1>=resultado)
        cout<<'S'<<endl;
    else
        cout<<'N'<<endl;

    return 0;
}