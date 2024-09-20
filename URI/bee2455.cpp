#include <iostream>

using namespace std;

int main ()
{
  int peso1, peso2;
  int comp1, comp2;

  cin >> peso1;
  cin >> comp1;
  cin >> peso2;
  cin >> comp2;

  int resultado = peso1 * comp1 - peso2 * comp2;

  if (resultado == 0)
    cout << 0;

  else if (resultado > 0)
    cout << -1;

  else if (resultado < 0)
    cout << 1;

  cout << endl;

  return 0;
}
