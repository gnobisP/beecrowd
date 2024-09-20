#include <bits/stdc++.h>

using namespace std;
#define LL long long
const LL LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 10010;

int main()
{
    int teste = 0;
    while(1){
        int n;cin>>n;
        if(n == -1)
            break;
        teste++;
        cout<<"Teste "<<teste<<endl;
        long long int resultado = pow(4,n) + pow(2,n+1)+ 1;
        cout<<resultado<<endl<<endl;
    }

    
    return 0;
}