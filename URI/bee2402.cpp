#include <bits/stdc++.h>

using namespace std;

#define dgb(x) cout << #x << " = " << x << endl;
#define ll long long
const int INF = 0x3f3f3f3f;
const long long int MAX = 2010;

ll lowestPrimeFactor(ll n, ll startPrime = 2)
{
    if (startPrime <= 3)
    {
        if (not(n & 1))
            return 2;
        if (not(n % 3))
            return 3;
        startPrime = 5;
    }
    for (ll i = startPrime; i * i <= n; i += (i + 1) % 6 ? 4 : 2)
        if (not(n % i))
            return i;
    return n;
}

bool isPrime(ll n)
{
    return n > 1 and lowestPrimeFactor(n) == n;
}

int main()
{
    ll N;
    cin >> N;
    if(N<4)
        cout<<'N'<<endl;
    else{
        if(isPrime(N))
            cout<<'N'<<endl;
        else
            cout<<'S'<<endl;
    }

    return 0;
}