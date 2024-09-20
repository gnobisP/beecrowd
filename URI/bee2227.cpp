#include <bits/stdc++.h>
using namespace std;
const int MAX = 101;
int main()
{
    int teste = 0;
    int A, V;
    while (cin >> A >> V)
    {
        if(A == 0 and V==0)
            break;
        teste++;
        cout<<"Teste "<<teste<<endl;
        vector<int> aviao(MAX, 0);
        for (int i = 0; i < V; i++)
        {
            int a, b;
            cin >> a >> b;
            aviao[a]++;
            aviao[b]++;
        }
        int maior = -1;
        for (int i = 1; i <= A; i++)
        {
            maior = max(maior, aviao[i]);
        }

        for (int i = 1; i <= A; i++)
        {
            if (maior == aviao[i])
            {

                cout << i << ' ';
            }
        }
        printf("\n\n");
    }

    return 0;
}