#include <iostream>
#include <queue>
using namespace std;

struct comp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.second == b.second)
        {
            return a.first < b.first;
        }

        return a.second > b.second;
    }
};

bool visited[100001];

int main()
{
    int N, K;
    cin >> N >> K;
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> Q;

    Q.push(make_pair(N, 0));
    // visited[N] = true;
    int ans;
    while (!Q.empty())
    {
        int num = Q.top().first;
        int sec = Q.top().second;
        Q.pop();
        if (visited[num] == true)
            continue;
        visited[num] = true;
        if (num == K)
        {
            ans = sec;
            break;
        }
        if (num * 2 < 100001 && visited[num * 2] == false)
            Q.push(make_pair(num * 2, sec));

        if (num + 1 < 100001 && visited[num + 1] == false)
            Q.push(make_pair(num + 1, sec + 1));

        if (num - 1 >= 0 && visited[num - 1] == false)
            Q.push(make_pair(num - 1, sec + 1));
    }

    cout << ans;
}