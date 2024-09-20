#include <bits/stdc++.h>

#define ll long long int

using namespace std;

const long long int MAX = 50000;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

int main()
{
    _
        ll A,
        N;
    cin >> A >> N;
    int resultado = 0;
    for (int n = 0; n < N; n++)
    {
        ll aux;
        cin >> aux;
        if (aux * A >= 40000000)
            resultado++;
    }

    cout << resultado << endl;

    return 0;
}