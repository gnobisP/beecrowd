#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const long long int MAX = 2002;
int X, Y;

bool camera(int a, int b)
{
    if (a >= X - 1 && a <= X + 1 && b >= Y - 1 && b <= Y + 1)
    {
        return true;
    }
    return false;
}

int main()
{
    int N, M;
    cin >> N >> M;
    cin >> X >> Y;
    int K;
    cin >> K;
    int a = 0, b = 0;
    int aux;
    int res = 0;

    // Verifica a posição inicial
   // if (camera(a, b))
       // res++;

    for (int i = 0; i < K; i++)
    {
        cin >> aux;
        switch (aux)
        {
        case 1:
            b++; // Leste
            break;
        case 2:
            b--; // Oeste
            break;
        case 3:
            a++; // Norte
            break;
        case 4:
            a--; // Sul
            break;
        default:
            break;
        }
        if (camera(a, b))
            res++;
    }
        printf("%d\n", res);

    return 0;
}
