#include <bits/stdc++.h>

using namespace std;

int calcular_soma_linha(int matriz[3][3], int linha)
{
    if ((matriz[linha][0] == 0) + (matriz[linha][1] == 0) + (matriz[linha][2] == 0) == 0)
        return matriz[linha][0] + matriz[linha][1] + matriz[linha][2];
    return 0;
}

int calcular_soma_coluna(int matriz[3][3], int coluna)
{
    if ((matriz[0][coluna] == 0) + (matriz[1][coluna] == 0) + (matriz[2][coluna] == 0) == 0)
        return matriz[0][coluna] + matriz[1][coluna] + matriz[2][coluna];
    return 0;
}

int calcular_soma_diagonal(int matriz[3][3], int principal)
{
    if (principal)
    {
        if ((matriz[0][0] == 0) + (matriz[1][1] == 0) + (matriz[2][2] == 0) == 0)
            return matriz[0][0] + matriz[1][1] + matriz[2][2];
    }
    else
    {
        if ((matriz[0][2] == 0) + (matriz[1][1] == 0) + (matriz[2][0] == 0) == 0)
            return matriz[0][2] + matriz[1][1] + matriz[2][0];
    }
    return 0;
}

int main(void)
{
    int matriz[3][3], soma_magica = 0;
    int linha, coluna, iteracoes;

    for (int linha = 0; linha < 3; ++linha)
        for (int coluna = 0; coluna < 3; ++coluna)
            cin >> matriz[linha][coluna];

    for (int linha = 0; linha < 3; ++linha)
        if (calcular_soma_linha(matriz, linha) > 0)
            soma_magica = calcular_soma_linha(matriz, linha);

    for (int coluna = 0; coluna < 3; ++coluna)
        if (calcular_soma_coluna(matriz, coluna) > 0)
            soma_magica = calcular_soma_coluna(matriz, coluna);

    if (calcular_soma_diagonal(matriz, 1) > 0)
        soma_magica = calcular_soma_diagonal(matriz, 1);

    if (calcular_soma_diagonal(matriz, 0) > 0)
        soma_magica = calcular_soma_diagonal(matriz, 0);

    if (soma_magica == 0)
    {
        for (int linha = 0; linha < 3; ++linha)
            for (int coluna = 0; coluna < 3; ++coluna)
                soma_magica += matriz[linha][coluna];
        soma_magica /= 2;
    }
    for (iteracoes = 0; iteracoes < 3; ++iteracoes)
    {
        for (int linha = 0; linha < 3; ++linha)
        {
            for (int coluna = 0; coluna < 3; ++coluna)
            {
                int zero_na_linha = (matriz[linha][0] == 0) + (matriz[linha][1] == 0) + (matriz[linha][2] == 0);
                int zero_na_coluna = (matriz[0][coluna] == 0) + (matriz[1][coluna] == 0) + (matriz[2][coluna] == 0);

                if (matriz[linha][coluna] == 0 && zero_na_linha == 1)
                    matriz[linha][coluna] = soma_magica - matriz[linha][0] - matriz[linha][1] - matriz[linha][2];

                if (matriz[linha][coluna] == 0 && zero_na_coluna == 1)
                    matriz[linha][coluna] = soma_magica - matriz[0][coluna] - matriz[1][coluna] - matriz[2][coluna];
            }
        }
    }

    for (int linha = 0; linha < 3; ++linha)
    {
        for (int coluna = 0; coluna < 3; ++coluna)
        if(coluna != 2)
            cout << matriz[linha][coluna] << ' ';
        else
            cout << matriz[linha][coluna];
        cout << endl;
    }

    return 0;
}
