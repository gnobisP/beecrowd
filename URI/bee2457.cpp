#include <iostream>
#include <string>

using namespace std;

int main()
{
    char letra;
    char rascunho;
    string texto;
    cin >> letra;

    getline(cin >> ws, texto);

    int quantpalavras = 1;
    int palavrasCLetra = 0;
    bool encontrouLetra = false;
    bool encontrouEspaco = false;

    for (char c : texto)
    {
        if (c >= 'a' && c <= 'z' && encontrouEspaco)
        {
            quantpalavras++;
            encontrouEspaco = false;
        }
        if (c == ' ')
        {
            encontrouEspaco = true;
            encontrouLetra = false;
        }

        if (c == letra && encontrouLetra == false)
        {
            encontrouLetra = true;
            palavrasCLetra++;
        }
    }
    float porcentagem = (float(palavrasCLetra) / quantpalavras) * 100;
    printf("%.1f\n", porcentagem);
    return 0;
}
