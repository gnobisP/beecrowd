#include <bits/stdc++.h>

using namespace std;

bool isSubsetSum(vector<int> set, int n, int sum)
{
    vector<bool> prev(sum + 1, false);

    prev[0] = true;

    vector<bool> curr(sum + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (j < set[i - 1])
                curr[j] = prev[j];
            else
                curr[j] = prev[j] || prev[j - set[i - 1]];
        }
        prev = curr;
    }

    return prev[sum];
}

int main()
{
    int V, M;
    cin >> V >> M;
    vector<int> set(M);
    for(int i = 0; i < M; i++){
        cin >> set[i];
    }
    if (isSubsetSum(set, M, V) == true)
        cout << "S";
    else
        cout << "N";
    cout<<endl;
    return 0;
}
