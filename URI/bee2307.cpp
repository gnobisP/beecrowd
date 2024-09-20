#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000+5;
int main()
{
    int N;cin>>N;
    int a;
    vector<int> pos(MAX);
    int index = 1;
    for(int i=0;i<N;i++){
        cin>>a;
        pos[a] = index;
        index++;
    }
    int res = 1;
    int seq = pos[1];
    for(int i=2;i<=N;i++){
        if(pos[i]<seq)
            res++;
        seq = pos[i];
    }
    cout<<res<<endl;
    return 0;
}