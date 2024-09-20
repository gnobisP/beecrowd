#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
    vector<int> fila;
    unsigned int quantInicio;
    cin >> quantInicio;
    for (int i = 0; i < quantInicio; i++)
    {
        unsigned int num;
        cin >> num;
        fila.push_back(num);
    }

    unsigned int quantDes;
    cin >> quantDes;
    vector<unsigned int> desistente;
    for (int i = 0; i < quantDes; i++)
    {
        unsigned int num;
        cin >> num;
        desistente.push_back(num);
    }

    int quant = 0;
    for (int i = 0; i < quantDes; i++)
    {
        for (int j = 0; j < quantInicio; j++)
            if (fila[j] == desistente[i])
            {
                fila.erase(fila.begin() + j);
                break;
            }
    }

    for (int num = 0; num < quantInicio - quantDes; num++)
    {
        if (num != quantInicio - quantDes - 1)
            cout << fila[num] << ' ';
        else
            cout << fila[num];
    }
    cout << endl;
}