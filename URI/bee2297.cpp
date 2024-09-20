#include <bits/stdc++.h>
using namespace std;
int main()
{
    int R;
    int var=0;
    while (1)
    {
        cin >> R;
        var++;
        if (R == 0)
            break;
        
        cout<<"Teste "<<var<<endl;
        int A,B;
        A=0;B=0;
        for(int i=0;i<R;i++){
            int aux1,aux2;cin>>aux1>>aux2;
            A+=aux1;B+=aux2;
        }
        if(A>B)
            cout<<"Aldo"<<endl;
        else
            cout<<"Beto"<<endl;
        cout<<endl;
        
    }
    return 0;
}