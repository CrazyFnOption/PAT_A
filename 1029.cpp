/*
	这是一道好题，以前没有碰过

    打acm的时候都在优化时间，从来没有考虑过原来内存也会超限，从来没有考虑过这种情况。

    对于这道题而言，主要的难点就在于比较的过程了，怎么找到前面cnt个数，以及相应cnt个数的构造

    最后需要分情况去讨论。
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

const int maxn = 2e5 + 10;
int num[maxn];

int main()
{
    int n,m;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) scanf("%d",&num[i]);
    scanf("%d",&m);
    int cnt = (n + m + 1) / 2;
    int index = 1;
    int t;

    for (int i = 0; i < m; i++) {
        scanf("%d",&t);
        //针对一种情况正好大于到前cnt个数，那么不就正好可以输出这个数了吗？
        while (t > num[index] && index <= n) {
            cnt--;
            if (!cnt) printf("%d",num[index]);
            index++;
        }
        cnt--;
        //如果都不比当前的数字大，那么就一定要考虑的是输出的n个数字的时候正好是n-1的时候了，那么此时的中位数，
        //一定是在第二个我没有存储下来的数组里面的
        if (!cnt) printf("%d",t);
    }
    //最后一种情况就是，我的第一个数组的数量远大于第二个数组，还没有到前cnt个数字的时候
    //就已经全部取完了，记住这种情况。
    while (index <= n) {
        cnt--;
        if (!cnt) {
            printf("%d",num[index]);
            break;
        }
        index++;
    }

    return 0;
}