#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> A;
vector<bool> robot;

void clearRobot()
{
    if (robot[N - 1] == true)
        robot[N - 1] = false;
}

int belt()
{
    int step = 0;
    while (1)
    {
        step++;
        // 1번 과정
        int tmp = A[2 * N - 1];
        bool rTmp = robot[2 * N - 1];
        for (int i = 2 * N - 1; i > 0; i--)
        {
            A[i] = A[i - 1];
            robot[i] = robot[i - 1];
        }
        A[0] = tmp;
        robot[0] = rTmp;

        clearRobot();
        // 2번
        for (int i = N - 1; i > 1; i--)
        {
            if ((A[i] > 0) && (robot[i] == false) && robot[i - 1] == true)
            {
                robot[i] = true;
                robot[i - 1] = false;
                A[i] = A[i] - 1;
            }
        }
        clearRobot();
        // 3번
        if (A[0] != 0)
        {
            robot[0] = true;
            A[0]--;
        }

        // 4번
        int zeroCnt = 0;
        for (int i : A)
            if (i == 0)
                zeroCnt++;

        if (zeroCnt >= K)
            break;
    }
    return step;
}

int main()
{
    cin >> N >> K;
    for (int i = 0; i < 2 * N; i++)
    {
        int n;
        cin >> n;
        A.push_back(n);
        robot.push_back(false);
    }
    cout << belt();
}