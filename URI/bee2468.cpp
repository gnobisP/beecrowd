#include <bits/stdc++.h>

#define ll long long int

using namespace std;

const ll MAX = 100005;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

vector<ll> id(MAX);
vector<ll> sz(MAX,1);
vector<tuple<ll, ll, ll>> estradas;

ll find(ll p){ // O(a(N)) amortizado
    return id[p] = (id[p] == p ? p : find(id[p]));
}

ll uni(ll p, ll q){ // O(a(N)) amortizado
    p = find(p), q = find(q);
    if (p == q)
        return 0;
    if (sz[p] > sz[q])
        swap(p, q);
    id[p] = q, sz[q] += sz[p];
    return sz[q];
}

int main(){_
    ll quant; cin>>quant;

    for(ll i=0;i<quant-1;i++){
        ll prioridade,ponto1,ponto2;
        cin>>ponto1>>ponto2>>prioridade;
        ponto1--,ponto2--;
        estradas.push_back(make_tuple(prioridade,ponto1,ponto2));
    }

    iota(id.begin(),id.end(),0);
    for(auto[p,a,b]: estradas){
        if(p == 0)
            uni(a,b);
    }
    ll resultado = 0;
    for(auto[p,a,b]: estradas){
        if(p == 1){
            resultado += sz[find(a)]*sz[find(b)];
            uni(a,b);
        }
            
    }
    cout<<resultado<<endl;
    return 0;
}