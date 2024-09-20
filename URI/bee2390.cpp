#include <bits/stdc++.h>

#define ll long long int

using namespace std;

const long long int MAX = 50000;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

int main()
{
    _ int N;
    cin >> N;
    ll resultado = 0;
    int tempoFinal = 0;
    for (int n = 0; n < N; n++)
    {
        int aux;
        cin >> aux;
        if (aux < tempoFinal)
        {
            resultado -= tempoFinal - aux;
        }
        resultado += 10;
        tempoFinal = aux + 10;
    }

    cout << resultado << endl;

    return 0;
}