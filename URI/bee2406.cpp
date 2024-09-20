#include <bits/stdc++.h>

using namespace std;

#define dgb(x) cout << #x << " = " << x << endl;
#define ll long long
const int INF = 0x3f3f3f3f;
const long long int MAX = 2010;
bool testaString1(string texto)
{
    stack<char> cadeia;

    for (auto c : texto)
    {
        switch (c)
        {
        case '(':
            cadeia.push('(');
            break;

        case ')':
        
            if(cadeia.empty())
                return false;
            if (cadeia.top() != '(')
                return false;
            cadeia.pop();
            break;

        case '[':
            cadeia.push('[');
            break;

        case ']':
        
            if(cadeia.empty())
                return false;
            if (cadeia.top() != '[')
                return false;
            cadeia.pop();
            break;

        case '{':
            cadeia.push('{');
            break;

        case '}':
            if(cadeia.empty())
                return false;
            if (cadeia.top() != '{')
                return false;
            cadeia.pop();
            break;
        }
    }
    return (cadeia.empty());
}

int main()
{
    int N;
    cin >> N;
    string texto;
    cin.ignore();
    for (int i = 0; i < N; i++)
    {
        getline(cin, texto);
        bool resultado = true;
        resultado &= testaString1(texto);

        if (resultado)
            cout << 'S' << endl;
        else
            cout << 'N' << endl;
    }

    return 0;
}