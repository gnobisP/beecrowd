#include <bits/stdc++.h>

#define ll long long int

using namespace std;

const long long int MAX = 50000;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

int main()
{_ 
    double H,P;cin>>H>>P;
    double resultado = H/P;
    cout<<fixed<<setprecision(2)<<resultado<<endl;


    return 0;
}