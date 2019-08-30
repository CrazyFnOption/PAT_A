/*
	这道题果然跟我最先开始想的思路是一模一样的
    记录每一个数字出现的次数，然后相加乘以就行了
    因为只有200ms的缘故，如果遍历的话 一定会超时的
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

const int maxn = 1e5 + 10;

double sum[maxn];

int main()
{
    int n;
    scanf("%d",&n);
    double x;
    double res = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lf",&x);
        //这个规律就是 看看是当前第几个数 然后乘以其的位数
        //所以第i个数 出现的次数就是 (n - i + 1) * i
        res = res + x * (n - i + 1) * i;
    }
    
    
    printf("%.2lf",res);
    return 0;
}