#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

void toInt(string s, vector<int> &intArr)
{
    for (char c : s)
    {
        if (c == 'A')
            intArr.push_back(0);
        else
            intArr.push_back(1);
    }
}

void dfs(vector<int> st, vector<int> ed)
{
    bool check = false;
    if (st.size() == ed.size())
    {
        check = true;
        for (long long unsigned int i = 0; i < ed.size(); i++)
        {
            if (st[i] != ed[i])
            {
                check = false;
                break;
            }
        }
        if (check)
        {
            cout << 1;
            exit(0);
        }

        return;
    }

    vector<int> newEd, newEd2;
    copy(begin(ed), end(ed), back_inserter(newEd));
    if (ed[ed.size() - 1] == 0)
    {
        newEd.pop_back();
        dfs(st, newEd);
    }

    if (ed[0] == 1)
    {
        for (int i = ed.size() - 1; i > 0; i--)
        {
            newEd2.push_back(ed[i]);
        }
        dfs(st, newEd2);
    }
}

int main()
{
    string A, B;
    cin >> A >> B;

    vector<int> intA, intB;
    toInt(A, intA);
    toInt(B, intB);

    dfs(intA, intB);
    cout << 0;
}