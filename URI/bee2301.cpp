#include <bits/stdc++.h>
using namespace std;
int main()
{

    int teste = 0;
    int P, R;
    bool primeiro = true;
    while (cin >> P >> R)
    {
        if (P == 0 and R == 0)
            break;
        teste++;
        cout << "Teste " << teste << endl;

        vector<int> participantes;

        for (int i = 0; i < P; i++)
        {
            int aux1;
            cin >> aux1;
            participantes.push_back(aux1);
        }

        for (int i = 0; i < R; i++)
        {

            int qPart;
            cin >> qPart;
            int movAtual;
            cin >> movAtual;
            vector<int> mov;
            int aux12 = qPart;
            for (int j = 0; j < qPart; j++)
            {
                int aux;
                cin >> aux;
                if (aux != movAtual)
                {
                    participantes.erase(participantes.begin() + j);
                    qPart--;
                    j--;
                }
            }
        }
        for (auto i : participantes)
        {
            cout << i << endl;
        }
        cout << endl;
    }
    return 0;
}
