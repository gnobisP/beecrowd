#include <iostream>
#include <string>
using namespace std;

int main()
{
    string texto;
    bool pSeguido = false;

    getline(cin >> ws, texto);
    for (char c : texto){
        if (c != 'p'){
            cout << c;
            pSeguido = false;
        }
        else{
            if (pSeguido == true){
                pSeguido = false;
                cout << c;
                continue;
            }
            pSeguido = true;
        }
    }
    cout << endl;
    return 0;
}
