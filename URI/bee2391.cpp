#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N; cin >> N;
    vector<int> num;
    for (int i = 0; i < N; i++)
    {
        int a; cin >> a;
        num.push_back(a);
    }
    int contador = 1;
    int diferencaA = num[0] - num[1];
    for (int i = 1; i < N; i++)
    {
        if (diferencaA != num[i - 1] - num[i])
        {
            diferencaA = num[i] - num[i+1];
            contador++;
            i++;
        }
    }
    cout<<contador<<endl;
    return 0;
}