#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, F, I, numero;
    cin >> N >> I >> F;

    vector<int> pares;
    for (int i = 0; i < N; i++){
        cin >> numero;
        pares.push_back(numero);
    }
    
    long long resultado = 0;
    for (int i = 0; i < N; i++){
        for (int j = i + 1; j < N; j++){
            if ((pares[i] + pares[j] >= I) && (pares[i] + pares[j] <= F)){
                resultado++;
            }
        }
    }
    cout << resultado << endl;
}