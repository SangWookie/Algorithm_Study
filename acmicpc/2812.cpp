#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> digits;
    digits.resize(N);

    string inputVal;
    cin >> inputVal;

    int a = 0;
    for (char c : inputVal)
    {
        digits[a] = c - '0';
        a++;
    }

    vector<int> ans;

    int remainingDels = K;
    for (int i = 0; i < N; i++)
    {
        if (N - i - remainingDels == 0) // 확인해야할 숫자랑 지워야하는 숫자랑 같으면
        {
            break;
        }

        if (remainingDels == 0) // 지울수 있는 숫자가 없으면 나머지 다 출력
        {
            for (int j = i; j < N; j++)
            {
                ans.push_back(digits[j]);
            }
            break;
        }

        int maxInd = i, maxVal = digits[i];
        // 남은 지울수있는 숫자 범위 내에 최댓값 찾기
        for (int j = i; j < i + remainingDels; j++)
        {
            if (maxVal < digits[j + 1])
            {
                maxInd = j + 1;
                maxVal = digits[j + 1];
            }
            if (maxVal == 9) // 9를 찾으면(이미 최댓값) 루프 종료
            {
                break;
            }
        }
        remainingDels = remainingDels - (maxInd - i); // 지운 숫자만큼 차감
        i = maxInd;
        ans.push_back(maxVal);
    }

    for (int i : ans)
    {
        cout << i;
    }
}