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
        ll quantA;
    cin >> quantA;
    ll quantB;
    cin >> quantB;
 
    unordered_set<ll> A, B;
 
    for (ll i = 0; i < quantA; i++)
    {
        ll numA;
        cin >> numA;
        A.insert(numA);
    }
 
    for (ll i = 0; i < quantB; i++)
    {
        ll numB;
        cin >> numB;
 
        auto num1 = A.find(numB);
        if (num1 != A.end())
        {
            B.insert(numB);
            continue;
        }
 
        auto num2 = B.find(numB / 2);
        if (num2 != B.end())
        {
            B.insert(numB);
            continue;
        }
 
        bool flag = true;
        for (ll numero : B)
        {
            ll dif = numB - numero;
            auto num3 = B.find(dif);
 
            if (num3 != B.end())
            {
                B.insert(numB);
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << numB << endl;
            return 0;
        }
    }
    cout << "sim" << endl;
    return 0;
}