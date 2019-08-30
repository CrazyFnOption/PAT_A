/*
	这里应该是被背包弄到魔障了，宛如一个智障

    就是一个简单的贪心，我竟然考虑多重背包，重量为1数量有限，直接选取每一个单价最多的不就行了吗？？？ 直接买光额...

    我真的醉了。

    以后25分的题目 就不要去想太多了。
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

struct Mooncake
{
    double amount;
    double price;
    double perpro;

} mooncake[1001];

bool comp(Mooncake m1, Mooncake m2)
{
    return m1.perpro > m2.perpro;
}

int main()
{
    int N, i;
    double profit = 0.0, D;
    scanf("%d%lf", &N, &D);
    for (i = 0; i < N; i++)
    {
        scanf("%lf", &mooncake[i].amount);
    }
    for (i = 0; i < N; i++)
    {
        scanf("%lf", &mooncake[i].price);
        mooncake[i].perpro = float(mooncake[i].price) / mooncake[i].amount;
    }
    sort(mooncake, mooncake + N, comp);
    for (i = 0; i < N; i++)
    {
        if (mooncake[i].amount <= D)
        {
            profit += mooncake[i].price;
            D -= mooncake[i].amount;
        }
        else
        {
            profit += D * mooncake[i].perpro;
            break;
        }
    }
    printf("%.2f", profit);
    return 0;
}