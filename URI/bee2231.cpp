#include <bits/stdc++.h>

using namespace std;
#define LL long long
const LL LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 10010;
int main()
{

    LL N, M;
    int teste = 0;
    while (1)
    {
        cin >> N >> M;
        if (N == 0 and M == 0)
            break;
        teste++;
        cout<<"Teste "<<teste<<endl;

        LL maiorMedia = -LINF;
        LL menorMedia = LINF;
        LL soma = 0;

        vector<LL> somas(MAX, 0);

        for (int i = 1; i <= N; i++)
        {
            int a;
            cin >> a;
            soma += a;
            somas[i] = soma;
        }

        for (int i = M; i <= N; i++)
        {
            menorMedia = min(menorMedia, ((somas[i] - somas[i - M]) / M));
            maiorMedia = max(maiorMedia, ((somas[i] - somas[i - M]) / M));
        }
        cout << menorMedia << ' ' << maiorMedia << endl<<endl;
    }

    return 0;
}