#include <bits/stdc++.h>

#define ll long long int

using namespace std;

const long long int MAX = 50000;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

int main()
{_ 
    int L;cin>>L;
    ll valor;

    if (L < 10)
        valor = 7;
    else if (L < 30)
        valor = 7 + (L - 10) * 1;
    else if (L < 100)
        valor = 7 + 20 + (L - 30) * 2;
    else
        valor = 7 + 20 + 140 + (L - 100) * 5;
        
    cout << valor << endl;
    return 0;
}