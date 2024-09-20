#include <bits/stdc++.h>

using namespace std;
const int MAX = 10005;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

int main()
{
    int xi,yi,xf,yf; cin>>xi>>yi>>xf>>yf;
    int ans = abs(xi-xf) + abs(yi-yf);
    cout<<ans<<endl;
    
    return 0;
}