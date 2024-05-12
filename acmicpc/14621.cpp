#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int N, M;
vector<pair<int, int>> connected;
vector<int> parent;
vector<char> MW;
vector<tuple<int, int, int>> weightedGraph;

struct comp
{
    bool operator()(tuple<int, int, int> a, tuple<int, int, int> b)
    {
        return get<2>(a) < get<2>(b);
    }
};

int find(int x)
{
    if (parent[x] == x)
        return x;
    else
        return parent[x] = find(parent[x]);
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        char mw;
        cin >> mw;
        MW.push_back(mw);
    }

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        weightedGraph.push_back(make_tuple(a - 1, b - 1, c));
    }
    sort(weightedGraph.begin(), weightedGraph.end(), comp());
    parent.resize(N);
    for (int i = 0; i < N; i++)
    {
        parent[i] = i;
    }

    int edgeCnt = 0;
    int totalWeight = 0;
    for (tuple<int, int, int> t : weightedGraph)
    {
        int from = get<0>(t);
        int to = get<1>(t);
        int weight = get<2>(t);

        if (edgeCnt == N - 1)
            break;

        if (MW[from] == MW[to])
            continue;

        int f = find(from);
        int d = find(to);
        if (f == d)
            continue;
        else
            parent[f] = d;

        totalWeight += weight;
        edgeCnt++;
        connected.push_back(make_pair(min(from, to), max(from, to)));
    }

    if (edgeCnt != N - 1)
        cout << "-1";
    else
        cout << totalWeight;

    return 0;
}