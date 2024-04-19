#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    int M;
    int L;
    cin >> N >> M >> L;

    vector<int> rest;
    rest.push_back(0);
    rest.push_back(L);

    for (int i = 0; i < N; i++)
    {
        int m;
        cin >> m;
        rest.push_back(m);
    }
    sort(rest.begin(), rest.end());

    int st = 1, en = L;
    int cnt; // 지을 수 있는 휴게소 수
    int ans = L;
    // 간격으로 이분탐색
    while (st <= en)
    {
        cnt = 0;
        int space = (st + en) / 2;
        if (space == 0)
        {
            space++;
        }

        for (int i = 0; i < N + 1; i++)
        {
            int gap = rest[i + 1] - rest[i];
            cnt += gap / space;
            if (gap % space == 0)
            {
                cnt--;
            }
        }

        if (cnt > M)
        {
            st = space + 1;
        }
        else
        {
            ans = min(space, ans);
            en = space - 1;
        }
    }

    cout << ans;
}
