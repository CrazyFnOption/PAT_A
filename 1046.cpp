/*
	就是一个求解用和来求解最短路的问题 可以直接写出来

    属于一道简单题吧  不过 看到有很多题解都想的特别复杂就不知道为什么了。

    两条路 要么正走，要么倒走
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;
int sum[MAXN];
int n, x;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &sum[i]), sum[i] = sum[i - 1] + sum[i];
    int m, x, y;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d", &x, &y);
        if (x > y)
            swap(x, y); // x <= y
        printf("%d\n", min(sum[y - 1] - sum[x - 1], sum[n] - sum[y - 1] + sum[x - 1]));
    }
    return 0;
}