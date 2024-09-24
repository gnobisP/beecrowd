#include <iostream>
using namespace std;
#define ll long long int
int main() {
    int A,B,C,D;
    int resposta = -1;
    cin>>A>>B>>C>>D;
    if(C%A!=0 or A%B==0 or D%C==0)
        resposta = -1;
    else{
        for(int i = A;i<=C;i+=A){
            
            if(C%i == 0 && i%B != 0 && D%i != 0){
                resposta = i;
                break;
            }else{
                resposta = -1;
            }
            
        }
    }
    cout<<resposta<<endl;

    return 0;
}
