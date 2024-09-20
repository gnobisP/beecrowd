#include <bits/stdc++.h>

using namespace std;

#define dgb(x) cout << #x << " = " << x << endl;

const int INF = 0x3f3f3f3f;
const long long int MAX = 2010;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> sapos;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        sapos.push_back(make_pair(a, b));
    }
    vector<bool> pedras(N, false);
    for (auto [a, b] : sapos)
    {
        for (int i = a; i < N; i += b)
            pedras[i] = true;
        
        for (int i = a; i >= 0; i -= b)
            pedras[i] = true;
        
    }
    for(auto a: pedras){
        cout<<a<<endl;
    }

    return 0;
}