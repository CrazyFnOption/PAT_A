/*
	简单题 写的时候怀疑人生了 原来是题目说的不清楚，
    明明说了第一个数的范围，竟然可以超出范围 我也是醉了 垃圾题目
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

int main()
{

    long long ta, tb, tc;
    long long da, db, dc;
    scanf("%lld.%lld.%lld", &ta, &tb, &tc);
    scanf("%lld.%lld.%lld", &da, &db, &dc);
    ta += da;
    tb += db;
    tc += dc;
    long long c = tc / 29;
    if (c != 0)
    {
        tb += c;
        tc = tc % 29;
    }
    long long b = tb / 17;
    if (b != 0)
    {
        ta += b;
        tb = tb % 17;
    }
    ta = ta % 100000000;
    printf("%lld.%lld.%lld", ta, tb, tc);
    return 0;
}