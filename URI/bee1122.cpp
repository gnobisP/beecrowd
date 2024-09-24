#include <bits/stdc++.h>

using namespace std;

#define _                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

const int MAX_VAL = 0x3f3f3f3f;

using ll = long long;

vector<ll> values;
vector<bool> addOperations;
vector<bool> subOperations;
ll target;
ll tamanho;
unordered_map<ll, unordered_map<ll, bool>> memoizationMap;

bool attempt(int index, ll currentSum) {
    if (index == values.size())
        return currentSum == target;

    if (memoizationMap[index].count(currentSum))
        return memoizationMap[index][currentSum];

    bool addResult = attempt(index + 1, currentSum + values[index]);
    if (addResult)
        addOperations[index] = true;

    bool subResult = attempt(index + 1, currentSum - values[index]);
    if (subResult)
        subOperations[index] = true;

    memoizationMap[index][currentSum] = addResult || subResult;
    return memoizationMap[index][currentSum];
}

string operationsToString() {
    string result;
    for (int i = 0; i < values.size(); i++) {
        if (addOperations[i] && subOperations[i])
            result += '?';
        else if (addOperations[i])
            result += '+';
        else
            result += '-';
    }
    return result;
}

int main() {_
    while (cin >> tamanho) {
        if (tamanho == 0)
            break;

        cin >> target;
        values.resize(tamanho);
        addOperations.assign(tamanho, false);
        subOperations.assign(tamanho, false);
        memoizationMap.clear();

        for (int i = 0; i < tamanho; i++) {
            cin >> values[i];
        }

        if (!attempt(0, 0))
            cout << "*" << endl;
        else
            cout << operationsToString() << endl;
    }

    return 0;
}
