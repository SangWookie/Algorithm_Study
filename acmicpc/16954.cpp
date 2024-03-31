#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

struct cmp
{
    bool operator()(tuple<int, int, int> &a, tuple<int, int, int> &b)
    {
        return std::get<0>(a) > std::get<0>(b);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    char board[9][9];
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> board[i][j];
        }
    }

    vector<pair<int, int>> nextMove = {
        // 다음 턴에 갈 수 있는 칸들의 모음
        make_pair(-1, -1),
        make_pair(-1, 0),
        make_pair(-1, 1), // 1
        make_pair(0, -1),
        make_pair(0, 0),
        make_pair(0, 1), // 2
        make_pair(1, -1),
        make_pair(1, 0),
        make_pair(1, 1) // 3
    };

    // seconds passed, row, column
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, cmp> pq;
    pq.push(make_tuple(0, 7, 0));

    int board_sec = 0; // 체스판의 시간이 얼마나 흘렀는가
    int canEsc = 0;    // 탈출 가능한가
    while (!pq.empty())
    {
        tuple<int, int, int> info = pq.top();
        pq.pop();
        int sec = get<0>(info);
        int i = get<1>(info);
        int j = get<2>(info);

        if (sec == board_sec + 1) // 1초가 지나서 보드를 업데이트 해야 함
        {
            for (int col = 0; col < 8; col++)
            {
                for (int row = 7; row > 0; row--)
                {
                    board[row][col] = board[row - 1][col];
                }
                board[0][col] = '.';
            }
            board_sec++;
        }
        if (board[i][j] == '#') // 현재 위치가 벽인 경우
            continue;

        if (i == 0 && j == 7)
        {
            canEsc = 1;
            break;
        }

        for (pair<int, int> ind : nextMove)
        {
            int i_next = i + get<0>(ind);
            int j_next = j + get<1>(ind);

            if (board[i_next][j_next] != '#' &&
                i_next >= 0 && i_next <= 7 &&
                j_next >= 0 && j_next <= 7)
            {
                pq.push(make_tuple(sec + 1, i_next, j_next));
            }
        }
    }

    cout << canEsc << endl;
}