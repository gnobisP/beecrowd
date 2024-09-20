#include <bits/stdc++.h>

using namespace std;
const int MAX = 10005;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

int main()
{
    vector<int> dist(610, 0);
    for (int i = 0; i < 3; i++)
    {
        int a;
        cin >> a;
        dist[a] += 1;
        dist[a + 200] += -1;
    }
    int acumula = 0;
    int ans = 0;

    for (int i = 0; i < 600; i++)
    {
        acumula += dist[i];
        if (acumula == 0)
            ans++;
    }

    cout<<ans*100<<endl;
    return 0;
}