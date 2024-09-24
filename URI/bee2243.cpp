#include <bits/stdc++.h>

#define ll long long int

using namespace std;

const long long int MAX = 50000;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

int main()
{_
    int N;
    cin >> N;
    vector<int> vetor;
    for (int i = 0; i < N; ++i)
    {
        int aux;
        cin >> aux;
        vetor.push_back(aux);
    }

    vector<int> D(vetor.size(), 1);
    for (int i = N - 2; i > -1; --i)
    {
        D[i] = min(vetor[i], D[i + 1] + 1);
    }

    vector<int> E(vetor.size(), 1);
    for (int i = 1; i < N; ++i)
    {
        E[i] = min(vetor[i], E[i - 1] + 1);
    }

    int resposta = -1;
    for (int i = 0; i < N; ++i)
    {
        resposta = max(resposta, min(E[i], D[i]));
    }
    cout << resposta << endl;

    return 0;
}