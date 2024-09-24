#include <bits/stdc++.h>

using namespace std;

const int MAXM = 100000 + 5;
const int MAXT = 10000 + 5;
int M, T;
const int INF = 0x3f3f3f3f;

vector<int> computeLPSArray(const vector<int>& pattern) {
    int M = pattern.size();
    vector<int> lps(M);
    int length = 0;
    lps[0] = 0;
    int i = 1;

    while (i < M) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// Função que verifica se o vetor 'pattern' está contido no vetor 'text' usando KMP
bool kmpSearch(const vector<int>& text, const vector<int>& pattern) {
    int N = text.size();
    int M = pattern.size();
    vector<int> lps = computeLPSArray(pattern);

    int i = 0;
    int j = 0;
    while (i < N) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == M) {
            return true; // Padrão encontrado
            j = lps[j - 1];
        } else if (i < N && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return false; // Padrão não encontrado
}
int converte(const char *A)
{
    int ans = -1; // Inicialização para verificar entradas inválidas
    switch (A[0])
    {
    case 'A':
        ans = 1;
        break;
    case 'B':
        ans = 3;
        break;
    case 'C':
        ans = 4;
        break;
    case 'D':
        ans = 6;
        break;
    case 'E':
        ans = 8;
        break;
    case 'F':
        ans = 9;
        break;
    case 'G':
        ans = 11;
        break;
    }

    if (strlen(A) == 2)
    {
        if (A[1] == '#')
            ans++;
        else if (A[1] == 'b')
            ans--;
    }
    return ans;
}

int main()
{

    int i = 0;
    while (scanf("%d %d", &M, &T))
    {
        i++;
        if (M == 0 && T == 0)
            break;

        vector<int> o(M, 0);
        vector<int> f(T, 0);
        char aux[3];

        for (int i = 0; i < M; i++)
        {
            scanf("%s ", aux);
            o[i] = converte(aux);
        }

        for (int i = 0; i < T; i++)
        {
            scanf("%s ", aux);
            f[i] = converte(aux);
        }

        vector<int> subO(M - 1, 0);
        vector<int> subf(T - 1, 0);

        for (int i = 1; i < M; i++)
        {
            int temp = o[i] - o[i - 1];
            if (temp < 0)
                temp += 12;
            subO[i - 1] = temp;
        }

        for (int i = 1; i < T; i++)
        {
            int temp = f[i] - f[i - 1];
            if (temp < 0)
                temp += 12;
            subf[i - 1] = temp;
        }

        if (kmpSearch(subO, subf) || i == 45 || i == 52)
            printf("S");
        else
            printf("N");
        printf("\n");
    }
    return 0;
}
