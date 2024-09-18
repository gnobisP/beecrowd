#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main()
{
    int V, P, soma = 0;
    cin >> V >> P;
    int aux = (V / P) + 1;
    int quant = V % P;
    for (int i = 0; i < quant; i++){
        cout << aux << endl;
        soma += aux;
    }

    while (1)
    {
        cout << V / P << endl;
        soma += V / P;
        if (soma == V)
            break;
    }
    return 0;
}