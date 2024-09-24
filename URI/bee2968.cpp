#include <bits/stdc++.h>

using namespace std;
#define LL long long
const LL LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 10010;

int main()
{

    long long V, N;
    cin >> V >> N;
    long long totPlacas = V * N;

    long long vecPor;
    long long int porcentual = 10;
    long double acumula = 0;
    for (int i = 0; i < 9; i++)
    {
        if ((porcentual * totPlacas) % 100 == 0)
            printf("%lld", (porcentual * totPlacas) / 100);
        else
            printf("%lld", (porcentual * totPlacas) / 100 + 1);
        if(i!=8)
            printf(" ");
        porcentual += 10;
    }
    cout<<endl;

    return 0;
}
