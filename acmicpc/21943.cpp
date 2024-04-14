#include <stdio.h>
#include <stdlib.h>

#define MAX_N 10

int n, a, b;
int arr[MAX_N];
int ans[MAX_N];
int visit[MAX_N];
int list[MAX_N];
int max = -2147483648;

void dfs(int x, int p, int q);
int calc();

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    scanf("%d %d", &a, &b);
    dfs(0, 0, 0);
    printf("%d\n", max);
    return 0;
}

void dfs(int x, int p, int q) // x - 인덱스
{
    if (p <= a && q <= b)
    {
        if (x == n)
        {
            max = (max > calc()) ? max : calc();
            return;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!visit[i])
        {
            visit[i] = 1;
            list[x] = arr[i];
            if (x == 0)
                dfs(x + 1, p, q);
            else
            {
                ans[x] = 1;
                dfs(x + 1, p + 1, q);
                ans[x] = 2;
                dfs(x + 1, p, q + 1);
                ans[x] = 0;
            }
            visit[i] = 0;
        }
    }
}

int calc()
{
    int temp_list[MAX_N];
    int temp = list[0];
    int temp_index = 0;
    for (int i = 1; i < n; i++)
    {
        if (ans[i] == 1)
            temp += list[i];
        if (ans[i] == 2)
        {
            temp_list[temp_index++] = temp;
            temp = list[i];
        }
    }
    temp_list[temp_index++] = temp;
    temp = 1;
    for (int i = 0; i < temp_index; i++)
        temp *= temp_list[i];
    return temp;
}
