#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long
#define MOD 1000000007
#define MAX 100000+10 
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

ll m[MAX];

bool verifica(const string &N, const string &S, int start, int end) {
    int lenS = end - start;
    int lenN = N.length();

    if (lenS < lenN) return true;
    if (lenS > lenN) return false;

    for (int i = 0; i < lenS; ++i) {
        if (S[start + i] < N[i]) return true;
        if (S[start + i] > N[i]) return false;
    }
    return true;
}

ll recorrencia(const string &N, const string &S, int b) {
    if (m[b] != -1)
        return m[b];

    if (S[b] == '0') {
        m[b] = 0;
        return 0;
    }

    ll ans = 0;
    for (int i = b + 1; i <= S.length(); ++i) {
        if (verifica(N, S, b, i))
            ans = (ans + recorrencia(N, S, i)) % MOD;
        else
            break;
    }

    m[b] = ans;
    return ans;
}

int main() {_
    string N, S; cin >> N >> S;

    memset(m, -1, sizeof(m));
    m[S.length()] = 1;

    ll result = recorrencia(N, S, 0);
    cout << result << endl;

    return 0;
}
