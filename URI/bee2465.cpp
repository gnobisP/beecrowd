#include <iostream>
#include <vector>

using namespace std;
int soma =0;
vector<vector<int>> matrizVisitado;
vector<vector<int>> matriz;

void percorrePonto(int linha, int coluna){

    if(matrizVisitado[linha][coluna] == 0){
        soma++;
        matrizVisitado[linha][coluna] = 1;
        if((linha - 1 >= 0))
            if(matriz[linha-1][coluna] >= matriz[linha][coluna])
                percorrePonto(linha-1, coluna);
            
        if(coluna - 1 >= 0)
            if((matriz[linha][coluna-1] >= matriz[linha][coluna]))
                percorrePonto(linha, coluna-1);
        
        if(linha+1 < matriz.size())
             if((matriz[linha+1][coluna] >= matriz[linha][coluna]))
                percorrePonto(linha+1, coluna);
        
        if(coluna+1 < matriz.size())
            if((matriz[linha][coluna+1] >= matriz[linha][coluna]))
             percorrePonto(linha, coluna+1);
        
    }
    
}
int main()
{
    int quant;
    cin>>quant;
    int I_linha, I_coluna; cin>>I_linha>>I_coluna;
    I_linha--;I_coluna--;
    for(int i=0; i<quant; i++){//Criação da matriz de alunos
        vector<int> vetor;
        for(int j=0;j<quant;j++){
            int n;cin>>n;
            vetor.push_back(n);
        }   
        matriz.push_back(vetor);
    }
    
    for(int i=0; i<quant; i++){//Criação da matriz de visitados
        vector<int> vetor;
        for(int j=0; j<quant; j++){
            vetor.push_back(0);
        }   
        matrizVisitado.push_back(vetor);
    }
     percorrePonto(I_linha, I_coluna);   
    cout<<soma<<endl;
    
    

    return 0;
}