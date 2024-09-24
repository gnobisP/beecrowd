#include <iostream>
using namespace std;
#define ll long long int
int main() {
    ll r, g, b;

    cin >> hex >> r >> g >> b;

    ll resultadoR = 1;
    ll resultadoG = (r / g) * (r / g);
    ll resultadoB = resultadoG * (g / b) * (g / b);
    cout << hex << resultadoR + resultadoG + resultadoB << endl;

    return 0;
}
