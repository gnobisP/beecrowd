#include <bits/stdc++.h>

using namespace std;

int main()
{
    int aux;cin >> aux;

    float minimo = FLT_MIN;
    for (int i = 0; i < aux; i++)
    {
        float preco; int peso; cin >> preco >> peso;
        float total = preco / (float(peso) / 1000);
        if (minimo == FLT_MIN || minimo > total)
            minimo = total;
    }
    printf("%.2lf\n", minimo);
    return 0;
}