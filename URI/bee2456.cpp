#include <iostream>

using namespace std;

int main()
{
    int cartaAnterior, cartaAtual;

    cin >> cartaAnterior;
    cin >> cartaAtual;
    
    int i = 0;
    
    if (cartaAnterior > cartaAtual)
    { // decrescente
        cartaAnterior = cartaAtual;
        for (i = 0; i < 3; i++)
        {
            cin >> cartaAtual;
            if (cartaAnterior < cartaAtual)
                break;
            cartaAnterior = cartaAtual;
        }
        if (i == 3)
            cout << 'D';
    }
    else
    { // crescente
         cartaAnterior = cartaAtual;
        for (i = 0; i < 3; i++)
        {
            cin >> cartaAtual;
            if (cartaAnterior > cartaAtual)
                break;
            cartaAnterior = cartaAtual;
        }
        if (i == 3)
            cout << 'C';
         
    }
    if(i != 3)
        cout << 'N';
    cout << endl;

    return 0;
}
