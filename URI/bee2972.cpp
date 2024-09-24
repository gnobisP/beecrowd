#include <bits/stdc++.h>

using namespace std;

long long int func(long long int n) {
    long long int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main()
{
    long long int A;
    cin >> A;
    long long int resultado = pow(2,func(A));
    cout << resultado << endl;
    return 0;
}
