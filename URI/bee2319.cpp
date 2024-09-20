#include <bits/stdc++.h>
using namespace std;

#define MAX 1005
#define INF 0x3f3f3f3f

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

vector<int> memo2(1000000 + 1, -1);
vector<int> memo5(1000000 + 1, -1);

int contaDivisores5(int x)
{
    if (memo5[x] != -1)
    {
        return memo5[x];
    }

    int original_x = x;
    int count = 0;

    while (x % 5 == 0 && x != 0)
    {
        if (memo5[x] != -1)
        {
            count += memo5[x];
            break;
        }
        count++;
        x /= 5;
    }

    memo5[original_x] = count;
    return count;
}

int contaDivisores2(int x)
{
    if (memo2[x] != -1)
    {
        return memo2[x];
    }

    int original_x = x;
    int count = 0;

    while (x % 2 == 0 && x != 0)
    {
        if (memo2[x] != -1)
        {
            count += memo2[x];
            break;
        }
        count++;
        x /= 2;
    }

    memo2[original_x] = count;
    return count;
}

int main()
{_
    vector<vector<int>>M_A(2,vector<int>(MAX));
    vector<vector<int>>M_F(2,vector<int>(MAX));

    int n; cin >> n;
    for (int i = 0; i < 2; ++i) {
        M_A[i][1] = 0;
        for (int j = 2; j <= n; ++j)
            M_A[i][j] = INF;
        M_F[i][0] = INF;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int a; cin >> a;

            for (int k = 0; k < 2; ++k)
            {
                if (!a)
                    M_F[k][j] = INF;
                else
                {
                    if (k == 0)
                        M_F[k][j] = contaDivisores5(a) + min(M_F[k][j - 1], M_A[k][j]);
                    else
                        M_F[k][j] = contaDivisores2(a) +  min(M_F[k][j - 1], M_A[k][j]);
                }
            }
        }

        for (int j = 0; j < 2; ++j)
            for (int k = 1; k <= n; ++k)
                M_A[j][k] = M_F[j][k];
    }

    int res = min(M_F[0][n], M_F[1][n]);
    cout << res << endl;

    return 0;
}
