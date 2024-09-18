#include <bits/stdc++.h>

using namespace std;

int main()
{
    int quantL, quantC;
    cin >> quantL >> quantC;
    cin.ignore();
    int k;
    vector<string> prateleiras;
    for (int ctrl = 0; ctrl < quantL; ctrl++)
    {
        string aux;
        getline(cin, aux);
        prateleiras.push_back(aux);
    }
    for (int i = 0; i < quantL; i++)
    {
        for (int j = 0; j < quantC; j++)
        {
            if (i % 2 != 0)
            {
                if (i - 1 != -1) // respeitar limites
                    if (prateleiras[i - 1][j] == 'o' && prateleiras[i][j] != '#' && prateleiras[i][j] == '.')
                    {
                        if (i + 1 < quantL)
                            prateleiras[i + 1][j] = 'o';
                        prateleiras[i][j] = 'o';
                    }
            }
            if (i % 2 == 0)
            {
                if (prateleiras[i][j] == 'o' && prateleiras[i][j] != '#' && prateleiras[i][j] != '.')
                {

                    if (i + 1 != quantL) // respeitar limites
                    {
                        if (prateleiras[i + 1][j] == '#')
                        {
                            k = j;
                            while (k >= 0)
                            {
                                prateleiras[i][k] = 'o';

                                if (prateleiras[i + 1][k] == '.' || prateleiras[i + 1][k] == 'o')
                                {
                                    prateleiras[i][k] = 'o';
                                    break;
                                }
                                k--;
                            }
                            k = j;
                            while (k < quantC)
                            {
                                prateleiras[i][k] = 'o';

                                if (prateleiras[i + 1][k] == '.' || prateleiras[i + 1][k] == 'o')
                                {
                                    prateleiras[i][k] = 'o';
                                    break;
                                }
                                k++;
                            }
                        }
                    }
                }
            }
        }
    }

    for (string s : prateleiras)
    {
        cout << s << endl;
    }
    return(0);
}