#include <iostream>
#include <vector>
#include <list>

using namespace std;

list<int> getParentNodes(int I, vector<int> &parentNode)
{
    list<int> parents;
    parents.push_back(I);

    int i = I;
    while (i != 0)
    {
        parents.push_back(parentNode[i]);
        i = parentNode[i];
    }

    return parents;
}

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        int N;
        cin >> N;

        vector<int> parentNode;
        parentNode.assign(N + 1, 0);

        // 간선 입력
        for (int i = 0; i < N - 1; i++)
        {
            int A, B;
            cin >> A >> B;
            parentNode[B] = A;
        }

        // 공통조상을 구할 두 노드
        int X, Y;
        cin >> X >> Y;

        list<int> Xparents, Yparents;
        Xparents = getParentNodes(X, parentNode);
        Yparents = getParentNodes(Y, parentNode);

        int ans;
        while (true)
        {
            if (Xparents.back() == Yparents.back())
            {
                ans = Xparents.back();
            }
            else
            {
                break;
            }
            Xparents.pop_back();
            Yparents.pop_back();

            if (Xparents.empty() || Yparents.empty())
            {
                break;
            }
        }

        parentNode.clear();

        cout << ans << endl;
    }
}