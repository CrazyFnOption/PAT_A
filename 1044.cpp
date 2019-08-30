/*
	对于这道题而言，最主要的问题应该就是爆内存了。
    题目里面是十的5次方，所以问题可能不能直接开两倍的数组了

    不过 以后和可以只开一倍的数组来试试
    sum[i - j] = sum[i] - sum[j]; 

    并且必须使用二分法来做
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int sum[maxn];
int n, S, nearS = 100000010;
int upper_bound(int left, int right, int num)
{ //寻找第一个大于num的数
    int mid;
    while (left < right)
    {
        mid = (right + left) / 2;
        if (sum[mid] > num)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}
int main()
{
    scanf("%d%d", &n, &S);
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &sum[i]);
        sum[i] += sum[i - 1];
    }
    //之前还在考虑 用二分怎么样才能用二分
    //因为二分的要求就是需要 排好序的序列
    //然后这里 直接排好序的递增和 正好符合条件
    for (int i = 1; i <= n; i++)
    {
        int j = upper_bound(i - 1, n + 1, sum[i - 1] + S);
        if (sum[j - 1] - sum[i - 1] == S)
        { //sum[j-1]可能就是要找的数
            nearS = S;
            break;
        }
        else if (j <= n && sum[j] - sum[i - 1] < nearS)
        { //若没找这个数，就存下大于它的第一个数
            nearS = sum[j] - sum[i - 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int j = upper_bound(i - 1, n + 1, sum[i - 1] + nearS);
        if (sum[j - 1] - sum[i - 1] == nearS)
        {
            printf("%d-%d\n", i, j - 1);
        }
    }
    return 0;
}