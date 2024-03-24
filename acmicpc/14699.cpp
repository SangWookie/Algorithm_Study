#include <iostream>
#include <vector>
#include <stack>
#include <list>

using namespace std;

vector<int> max_depth;
vector<list<int>> dp;

int dfs(int node)
{
    if (max_depth[node] != 0)
        return max_depth[node];

    for (int i : dp[node])
    {
        max_depth[node] = max(max_depth[node], dfs(i));
    }

    max_depth[node]++;
    return max_depth[node];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    max_depth.resize(N + 1, 0);

    vector<int> height(N + 1); // 각 쉼터 높이 입력
    for (int i = 0; i < N; i++)
    {
        int h;
        cin >> h;
        height[i + 1] = h;
    }

    dp.resize(N + 1, list<int>());

    int v1, v2;
    for (int i = 0; i < M; i++) // 위로 올라가는 경로만 표시
    {
        cin >> v1 >> v2;
        int start, dest;
        if (height[v1] > height[v2])
        {
            start = v2;
            dest = v1;
        }
        else
        {
            start = v1;
            dest = v2;
        }
        dp[start].push_back(dest);
    }

    for (int i = 1; i <= N; i++)
    {
        dfs(i);
    }

    for (int i = 1; i <= N; i++)
    {
        cout << max_depth[i] << "\n";
    }
}