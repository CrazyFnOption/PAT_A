/*

类似于之前的双指针办法，有点意思，同样可以用二分的办法来做这样一道题。
*/
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long ll;
const int maxn = 100005;
int a[maxn];

int main()
{
    int n, p;
    int maxn = 0;
    scanf("%d%d", &n, &p);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i)
    {
        //long long num = a[i] * p;
        //这个地方需要记住，就在于其的长度问题，距离当前的长度是多少的问题，值得在做一遍
        int pos = upper_bound(a + i + 1, a + n, (long long)a[i] * p) - a;
        maxn = max(maxn, pos - i);
    }
    printf("%d", maxn);
    return 0;
}
