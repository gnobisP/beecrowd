#include <bits/stdc++.h>

using namespace std;

#define dgb(x) cout << #x << " = " << x << endl;

const int INF = 0x3f3f3f3f;
const long long int MAX = 2010;

int main()
{
    int N, M;
    cin >> N >> M;
    int menorTempo = INF, index;
    for (int i = 0; i < N; i++)
    {
        int aux = 0;
        for (int j = 0; j < M; j++)
        {
            int a;
            cin >> a;
            aux += a;
        }
        if (menorTempo > aux)
        {
            menorTempo = aux;
            index = i;
        }
    }
    index++;
    cout<<index<<endl;

    return 0;
}