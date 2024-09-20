#include <bits/stdc++.h>

using namespace std;

#define LL long long

const LL LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 105001;

int main()
{
    int X, Y, N;
    int teste = 0;

    while (cin >> X >> Y >> N)
    {
        if (X == 0 and Y == 0 and N == 0)
            break;
        teste++;
        cout<<"Teste "<<teste<<endl;
        vector<int> valores;
        int soma = 0;

        for (int i = 0; i < N; i++)
        {
            int a;
            cin >> a;
            valores.push_back(a);
            soma += a;
        }

        if (((X + Y + soma)) % 2 != 0)
        {
            cout << 'N' << endl;
        }
        else
        {
            long long int alvo = ((soma + X + Y) / 2) - X;
            vector<bool> possivel(MAX, false);
            possivel[0] = true;
            long long int maximo = 0;
            for (int k = 0; k < N; k++)
            {
                if (possivel[alvo])
                    break;
                for (int j = maximo; j >= 0; j--)
                {

                    if (possivel[j])
                        possivel[j + valores[k]] = true;
                }
                maximo += valores[k];
            }
            if (possivel[alvo])
                cout << 'S' << endl;
            else
                cout << 'N' << endl;
        }
        cout<<endl;
    }
    return 0;
}