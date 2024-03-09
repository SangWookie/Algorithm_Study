#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
using namespace std;

// 가중치 그래프에서 두 리프 사이 간격의 최댓값 찾기

int main()
{
    int n;
    vector<vector<pair<int, int>>> edges;

    // 입력값 받기
    cin >> n;
    edges.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;

        edges[a].push_back(make_pair(b, w));
    }

    // stack
    stack<tuple<int, int, int>> S; // parent, child, weight

    // 각 노드 기준 반지름 최댓값 저장할 배열 생성, 초기화
    vector<int> max_weights;
    max_weights.resize(n + 1);
    for (int i = 0; i < n + 1; i++)
    {
        max_weights[i] = 0;
    }

    // dfs 그래프 탐색(리프 노드 찾기)
    queue<int> Q; // child

    for (int i = 0; i < edges[1].size(); i++)
    {
        Q.push(edges[1][i].first);
        S.push(make_tuple(1, edges[1][i].first, edges[1][i].second));
        while (!Q.empty())
        {
            // queue의 값 받아오기
            int child = Q.front();

            Q.pop();

            for (int i = 0; i < edges[child].size(); i++)
            {
                // 계속 리프 노드 찾기
                Q.push(edges[child][i].first);

                // 부모(상위) 노드들을 먼저 방문하기 위해 스택에 push
                S.push(make_tuple(child, edges[child][i].first, edges[child][i].second));
            }
        }
    }

    int ans = 0;

    while (!S.empty())
    {
        tuple<int, int, int> top = S.top();
        int parent = get<0>(top);
        int child = get<1>(top);
        int weight = get<2>(top);

        S.pop();

        if (ans < max_weights[child] + weight + max_weights[parent])
        {
            ans = max_weights[child] + weight + max_weights[parent];
        }

        if (max_weights[parent] == 0)
        {
            max_weights[parent] = max_weights[child] + weight;
        }
        else
        {
            if (max_weights[child] + weight > max_weights[parent])
            {
                max_weights[parent] = max_weights[child] + weight;
            }
        }
    }

    cout << ans;
}