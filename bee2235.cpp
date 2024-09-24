#include <bits/stdc++.h>

#define ll long long int

using namespace std;

const long long int MAX = 50000;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

int main()
{
    _ int A, B, C;
    cin >> A >> B >> C;
    if (A == B or A == C or B == C)
    {
        cout << 'S' << endl;
        return 0;
    }

    if ((A + B) == C or (A + C) == B or (C + B) == A)
    {
        cout << 'S' << endl;
        return 0;
    }
    cout << 'N' << endl;
    return 0;
}