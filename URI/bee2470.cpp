#include <bits/stdc++.h>

using namespace std;
#define ll long long int
const long long int MAX = 50002;
#define _                         \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);

vector<vector<ll>> g(MAX);

void dfs(ll u, ll p, vector<vector<ll>> &memo, vector<ll> &lev, ll log)
{
	memo[u][0] = p;
	for (ll i = 1; i <= log; i++)
		memo[u][i] = memo[memo[u][i - 1]][i - 1];
	for (ll v : g[u])
	{
		if (v != p)
		{
			lev[v] = lev[u] + 1;
			dfs(v, u, memo, lev, log);
		}
	}
}

ll lca(ll u, ll v, ll log, vector<ll> &lev, vector<vector<ll>> &memo)
{

	if (lev[u] < lev[v])
		swap(u, v);

	for (ll i = log; i >= 0; i--)
		if ((lev[u] - pow(2, i)) >= lev[v])
			u = memo[u][i];

	if (u == v)
		return u;

	for (ll i = log; i >= 0; i--)
	{
		if (memo[u][i] != memo[v][i])
		{
			u = memo[u][i];
			v = memo[v][i];
		}
	}

	return memo[u][0];
}

// Driver Code
int main()
{
	
		ll quant;
	cin >> quant;
	vector<ll> cartas(quant);
	for (ll i = 0; i < quant; i++)
	{ // criação das cartas
		ll num;
		scanf("%lld", &num);
		cartas[i] = num;
	}

	for (ll i = 0; i < quant - 1; i++)
	{ // Criação do grafo(arestas)
		ll pos, vizinho;
		scanf("%lld %lld", &pos, &vizinho);
		g[vizinho].push_back(pos);
		g[pos].push_back(vizinho);
	}
	vector<pair<ll, ll>> pares((quant / 2) + 1, make_pair(-1, -1));

	for (ll i = 0; i < quant; i++)
	{
		if (pares[cartas[i]].first == -1)
			pares[cartas[i]].first = i;
		else
			pares[cartas[i]].second = i;
	}

	ll log = (ll)ceil(log2(quant));

	vector<vector<ll>> memo(quant + 1, vector<ll>(log + 1, -1));
	vector<ll> lev(quant + 1);

	dfs(1, 1, memo, lev, log);

	ll distancia = 0;
	for (ll i = 1; i <= (quant / 2); i++)
	{
		ll dist1 = lev[pares[i].first + 1];
		ll dist2 = lev[pares[i].second + 1];
		ll dist3 = lev[lca(pares[i].first + 1, pares[i].second + 1, log, lev, memo)];
		distancia += dist1 + dist2 - (2 * dist3);
	}
	cout << distancia << endl;

	return 0;
}
