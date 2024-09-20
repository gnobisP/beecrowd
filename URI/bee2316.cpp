#include <bits/stdc++.h>
using namespace std;
const int MAXK = 100 + 5, MAXN = 100 + 5, MAXM = 10000 + 5;
vector<int> qualPosto(MAXK, 0);
vector<pair<pair<int, int>, int>> quantPosto;
bool ordena(pair<pair<int, int>, int> A, pair<pair<int, int>, int> B)
{
    if (A.first.first == B.first.first)
        return B.first.second > A.first.second;
    return A.first.first > B.first.first;
}
int main()
{
    int K, N, M;
    cin >> K >> N >> M;
    quantPosto.assign(N + 1, make_pair(make_pair(0, 0), 0));
    for (int i = 1; i <= N; i++)
    {
        quantPosto[i].second = i;
    }
    for (int i = 0; i < M; i++)
    {
        int X, Y;
        cin >> X >> Y;
        if (qualPosto[X] == Y - 1)
        {
            qualPosto[X] = Y;
            if (qualPosto[X] == K)
                qualPosto[X] = 0;
            quantPosto[X].first.first++;
            quantPosto[X].first.second = i;
        }
    }

    sort(quantPosto.begin(), quantPosto.end(), ordena);
    cout<<quantPosto[0].second;
    for (int i = 1; i < N; i++)
    {
        auto [P, c] = quantPosto[i];
        auto [a, b] = P;
        cout << ' ' << c;
    }
    cout << endl;
}