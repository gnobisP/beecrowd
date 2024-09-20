#include <bits/stdc++.h>
using namespace std;
const int MAX = 105;
vector<vector<int>> M(MAX, vector<int>(MAX));
int main()
{

    int qLinha, qColuna;
    cin >> qLinha >> qColuna;

    for (int i = 0; i < qLinha; i++)
    {
        for (int j = 0; j < qColuna; j++)
        {
            cin >> M[i][j];
        }
    }
    long long int soma = 0;

    for (int i = 0; i < qLinha; i++)
    {
        long long int aux = 0;
        for (int j = 0; j < qColuna; j++)
        {
            aux += M[i][j];
        }
        soma = max(soma, aux);
    }
    for (int j = 0; j < qColuna; j++)
    {
        long long int aux = 0;
        for (int i = 0; i < qLinha; i++)
        {
            aux += M[i][j];
        }
        soma = max(soma, aux);
    }
    cout << soma << endl;

    return 0;
}