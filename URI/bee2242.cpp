#include <bits/stdc++.h>

#define ll long long int

using namespace std;

const long long int MAX = 50000;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

int main()
{_
    string risada;
    getline(cin,risada);
    string vogais;
    for(char c: risada){
        if(c == 'a' or c == 'e' or c == 'i'  or c == 'o'  or c == 'u' ){
            vogais+=c;
        }
    }
    string copiaVogais = vogais;
    reverse(copiaVogais.begin(),copiaVogais.end());
    if(vogais == copiaVogais)
        cout<<'S';
    else
        cout<<'N';
    cout<<endl;

    return 0;
}