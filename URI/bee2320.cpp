#include <bits/stdc++.h>

using namespace std;

const int MAX_LENGTH = 1000;
const int INF = 0x3f3f3f3f;

char sequenceOne[MAX_LENGTH + 1];
char sequenceTwo[MAX_LENGTH + 1];

int dpTable[MAX_LENGTH + 1][MAX_LENGTH + 1];
int nextIndex[MAX_LENGTH + 1]['z' - 'a' + 1];

int length1, length2;


void search(int i, int j) {
    if (dpTable[i][j] != 0)
        return;

    if (j == 0) {
        dpTable[i][0] = 1;
        return;
    }

    if (i == 0) {
        dpTable[0][j] = (nextIndex[j][sequenceOne[0] - 'a'] == 0) ? 1 : INF;
        return;
    }

    if (nextIndex[j][sequenceOne[i] - 'a'] == 0) {
        dpTable[i][j] = 1;
        return;
    }

    search(i - 1, j);
    search(i - 1, nextIndex[j][sequenceOne[i] - 'a'] - 1);

    dpTable[i][j] = min(dpTable[i - 1][j],
                             dpTable[i - 1][nextIndex[j][sequenceOne[i] - 'a'] - 1] + 1);
}

void computeSolution() {
    length1 = strlen(sequenceOne);
    length2 = strlen(sequenceTwo);

    for (char i = 'a'; i <= 'z'; i++) {
        nextIndex[0][i - 'a'] = 0;
    }

    for (int i = 1; i <= length2; i++) {
        for (char j = 'a'; j <= 'z'; j++) {
            nextIndex[i][j - 'a'] = nextIndex[i - 1][j - 'a'];
            if (sequenceTwo[i - 1] == j) {
                nextIndex[i][j - 'a'] = i;
            }
        }
    }

    search(length1 - 1, length2);
}


int main() {
    int a,b;cin>>a>>b;
     cin >> sequenceOne >> sequenceTwo;
    computeSolution();
   cout << dpTable[length1 - 1][length2] << endl;
    return 0;
}
