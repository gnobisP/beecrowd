#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define dgb(x) cout << #x << " = " << x << endl // facilita MUITO o debug

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
int maximalRectangle(vector<vector<int>> matrix)
{
    if (matrix.empty())
        return 0;

    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> heights(n, 0);
    vector<int> left(n, 0);
    vector<int> right(n, n);

    int maxArea = 0;

    for (int i = 0; i < m; ++i)
    {
        int cur_left = 0, cur_right = n;

        for (int j = n - 1; j >= 0; --j)
        {
            if (matrix[i][j] == 1)
            {
                right[j] = min(right[j], cur_right);
            }
            else
            {
                right[j] = n;
                cur_right = j;
            }
        }

        for (int j = 0; j < n; ++j)
        {
            if (matrix[i][j] == 1)
            {
                left[j] = max(left[j], cur_left);
            }
            else
            {
                left[j] = 0;
                cur_left = j + 1;
            }

            if (matrix[i][j] == 1)
            {
                heights[j]++;
            }
            else
            {
                heights[j] = 0;
            }
        }
        for (int j = 0; j < n; ++j)
        {
            maxArea = max(maxArea, ((right[j] - left[j])+1) * (heights[j]+1));
        }
    }

    return maxArea;
}
int main()
{
    _
        ll linha,
        coluna;
    cin >> linha >> coluna;
    vector<vector<ll>> matriz;
    vector<vector<int>> matrizRes;
    for (ll i = 0; i < linha; i++)
    {
        vector<ll> vAux;
        for (int j = 0; j < coluna; j++)
        {
            ll aux;cin >> aux;
            vAux.push_back(aux);
        }
        matriz.push_back(vAux);
    }
    for (ll i = 0; i < linha - 1; i++)
    {
        vector<int> vAux;
        for (int j = 0; j < coluna - 1; j++)
        {
            vAux.push_back(0);
        }
        matrizRes.push_back(vAux);
    }

    for (int i = 0; i < linha - 1; i++)
    {
        for (int j = 0; j < coluna - 1; j++)
        {
            if (matriz[i][j] + matriz[i + 1][j + 1] <= matriz[i + 1][j] + matriz[i][j + 1])
            {
                matrizRes[i][j] = 1;
            }
        }
    }

    ll resultado = maximalRectangle(matrizRes);

    cout << resultado << endl;
    return 0;
}