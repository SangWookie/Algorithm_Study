#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> cnt;
vector<int> preqCnt;
vector<vector<int>> graph;

int main()
{
    int N, M;
    cin >> N >> M;

    preqCnt.assign(N + 1, 0);
    graph.resize(N + 1);
    cnt.assign(N + 1, 0);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        preqCnt[b]++;
        graph[a].push_back(b);
    }

    queue<pair<int, int>> Q;
    for (int i = 1; i < N + 1; i++)
    {
        if (preqCnt[i] == 0)
        {
            Q.push(make_pair(i, 1));
        }
    }

    while (!Q.empty())
    {
        int node = Q.front().first;
        int depth = Q.front().second;
        Q.pop();

        cnt[node] = depth;
        for (int i : graph[node])
        {
            preqCnt[i]--;
            if (preqCnt[i] == 0)
            {
                Q.push(make_pair(i, depth + 1));
            }
        }
    }

    for (int i = 1; i < N + 1; i++)
    {
        cout << cnt[i] << " ";
    }
    return 0;
}