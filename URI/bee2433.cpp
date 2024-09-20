#include <bits/stdc++.h>

using namespace std;

vector<int> n1;
const int INF = 0x3f3f3f3f;

void imprime(vector<int> &n1)
{
    for (auto n : n1)
        cout << n << ' ';

    cout << endl;
}

int main()
{

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        n1.push_back(a);
    }

    sort(n1.begin(), n1.end());
    // imprime(n1);
    int l = 0, r = N - K-1;
    int minimo = INF;
    while (r < N)
    {
        minimo = min(minimo, n1[r] - n1[l]);
        //cout << ' ' << l << ' ' << r << ' ' << minimo << endl;
        l++;
        r++;
    }
    cout << minimo << endl;

    return 0;
}