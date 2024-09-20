#include <iostream>
#include <string>
using namespace std;
int main(){
    char letras[26];
    for(int i=0;i<26;i++){//Recebendo criptografia
        cin >> letras[i];
    }

    string texto;
    getline(cin >> ws, texto);//comando o enter e recebendo o texto
    for(char letra:texto){
        for(int i=0;i<26;i++){
            if(letra == letras[i]){
                printf("%c", i+97);//Usando asc2
            }
        }
    }
    cout<<endl;
    return 0;
}