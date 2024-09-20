#include <bits/stdc++.h>

#define ll long long int

using namespace std;

const long long int MAX = 50000;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

int main()
{

    vector<char> resultado(32);
    for (int i = 0; i < 16; i++)
        resultado[i] = 'A' + i;
    
    for (int i = 16; i < 31; i++)
    {
        int timeA, timeB;
        cin >> timeA >> timeB;
        if (timeA > timeB)
            resultado[i] = resultado[(i-16) * 2];
        else
            resultado[i] = resultado[(i-16) * 2 + 1];
    }


    cout<<resultado[30]<<endl;



    return 0;
}