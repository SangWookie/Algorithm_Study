#include <stdio.h>
int n, arr[16][16], cnt = 0;
void back(int level)
{
    int flag;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            arr[level][j] = 0;
        }
        if (level == 1)
        {
            for (int j = 1; j <= n; j++)
            {
                for (int k = 1; k <= n; k++)
                {
                    arr[j][k] = 0;
                }
            }
        }
        if (level == n + 1)
        {
            return;
        }
        flag = 0;
        for (int j = 1; j <= level; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (level + i == j + k || level - i == j - k || level == j || i == k)
                {
                    if (arr[j][k] == 1)
                    {
                        flag = 1;
                    }
                }
            }
        }
        if (flag == 1)
            continue;
        arr[level][i] = 1;
        if (level == n)
        {
            cnt++;
        }
        back(level + 1);
    }
}
int main()
{
    scanf("%d", &n);
    back(1);
    printf("%d", cnt);
}