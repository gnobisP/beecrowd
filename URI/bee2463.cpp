#include <iostream>
#include <vector>

using namespace std;

int main()
{
    unsigned int quant; 
    cin>>quant;
    vector<int> casas(quant);
    for(int i=0;i<quant;i++){
        cin>>casas[i];
    }
    
    long int max, melhorMax;
    max = casas[0];
    melhorMax = casas[0];
    
    for(int i=1; i<quant; i++){
        if(melhorMax > 0){
            melhorMax += casas[i];
        }else{
            melhorMax = casas[i];
        }
        if(melhorMax>max)
            max = melhorMax;
    }
    cout<<max<<endl;

    return 0;
}
