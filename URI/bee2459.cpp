#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <numeric>

#define f 0
#define g 1

using namespace std;

const int MAX = 100;
vector<int> id, sz; // id=conjunto com os representantes
vector<tuple<int, int, int, int>> reformas;

int find(int x)
{
    if (id[x] == x)
        return x;
    else
    {
        return (find(id[x]));
    }
}
void uni(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) // camihno que leva a ele mesmo descarta
        return;
    id[x] = y;
}
int main()
{
    int quantCid, quantFer, quantEst;
    cin >> quantCid >> quantFer >> quantEst;

    id = vector<int>(quantCid);
    sz = vector<int>(quantCid, 1);

    iota(id.begin(), id.end(), 0); // 1,2,3...

    int v1, v2, custo;
    for (int i = 0; i < quantFer; i++)
    {
        cin >> v1 >> v2 >> custo;
        v1--, v2--;
        reformas.push_back(make_tuple(f, custo, v1, v2));
    }

    for (int i = 0; i < quantEst; i++)
    {
        cin >> v1 >> v2 >> custo;
        v1--, v2--;
        reformas.push_back(make_tuple(g, custo, v1, v2));
    }

    int custoTotal = 0;
    sort(reformas.begin(), reformas.end()); // ordenar o vetor baseando em prioridade(f ou e, custo)
    for (auto [a, b, c, d] : reformas)
    {
        if (find(c) != find(d))
        {              // se a aresta não foi construida
            uni(c, d); // cria a aresta
            custoTotal += b;
        }
    }
    cout << custoTotal << endl;
    return 0;
}