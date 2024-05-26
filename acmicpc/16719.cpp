#include <iostream>
#include <vector>
using namespace std;

vector<int> nextInd;
vector<bool> ifPrint;
string input;

string answerPrinter(int i)
{
    ifPrint[nextInd[i]] = true;
    string output;
    for (int k = 0; k < input.length(); k++)
    {
        if (ifPrint[k])
            output.push_back(input[k]);
    }
    return output;
}

void orderManager(int st, int ed)
{
    if (st > ed)
        return;

    int next;
    char minChar = 'Z' + 1;

    for (int i = st; i <= ed; i++)
    {
        if (minChar > input[i])
        {
            minChar = input[i];
            next = i;
        }
    }
    nextInd.push_back(next);

    orderManager(next + 1, ed);
    orderManager(st, next - 1);
}

int main()
{
    cin >> input;

    orderManager(0, input.length() - 1);

    ifPrint.assign(input.length(), false);

    for (int i = 0; i < input.length(); i++)
    {
        cout << answerPrinter(i) << endl;
    }
}
