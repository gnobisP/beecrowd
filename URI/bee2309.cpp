#include <bits/stdc++.h>

using namespace std;

#define dgb(x) cout << #x << " = " << x << endl;

const int INF = 0x3f3f3f3f;
const long long int MAX = 2010;
//                    1   2   3   4  5  6  7  8  9 10 11 12 13
vector<int> aux = {-1, 11, 12, 13, 0, 1, 2, 3, -1, -1, -1, 5, 4, 6};

bool verificaMaior(int a, int b)
{
    int c = aux[a], d = aux[b];
    return c > d;
}

bool ordena(int a, int b)
{
    return verificaMaior(a, b);
}

bool solve(vector<int> ca, vector<int> cb)
{
    int pontA = 0;
    int pontB = 0;
    for (int i = 0; i < 3; i++)
    {
        if (ca[i] != cb[i])
        {
            bool teste = verificaMaior(ca[i], cb[i]);
            if (teste)
                pontA++;
            else
                pontB++;
        }
        else
            pontA++;
    }
    return pontA > pontB;
}

int main()
{

    int N;
    cin >> N;
    int pontA = 0, pontB = 0;
    vector<int> ca(3), cb(3);

    for (int i = 0; i < N; i++)
    {

        for (int j = 0; j < 3; j++)
            cin >> ca[j];

        for (int j = 0; j < 3; j++)
            cin >> cb[j];

        bool result = solve(ca, cb);

        if (result == true)
            pontA++;
        else
            pontB++;
    }
    cout << pontA << ' ' << pontB << endl;
    return 0;
}