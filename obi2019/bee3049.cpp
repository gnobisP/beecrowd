#include <bits/stdc++.h>

#define ll long long int

using namespace std;

const long long int MAX = 50000;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

int main()
{
    _ int B, T;
    float A1, A2;
    cin >> B >> T;
    if (B > T)
        swap(B, T);
    A1 = B * 70 + ((T-B) * 70) / 2;
    A2 = 70 * 160 - A1;

    if (A1 == A2)
        cout << 0;
    else if (A1 > A2)
        cout << 1;
    else
        cout << 2;

    cout << endl;
}