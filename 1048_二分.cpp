/*
	长见识了，竟然还可以这样写，完全没有想到的做法，
    直接在两个数里面去找，然后通过二分找到最大的相等的那一个

    不过二分的函数要记住怎么写的。
    因为怕到时候考场上不允许写这种东西。
*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int arr[maxn];
int upper_bound(int left, int right, int num)
{
    int mid;
    while (left <= right)
    {
        mid = (right + left) / 2;
        if (arr[mid] == num)
        {
            return mid;
        }
        else if (arr[mid] > num)
        {
            right = mid - 1;
        }
        else if (arr[mid] < num)
        {
            left = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int n, num;
    scanf("%d%d", &n, &num);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n);
    int i = 0;
    for (; i < n; i++)
    {
        int pos = upper_bound(i, n - 1, num - arr[i]);
        if (pos > 0 && pos != i)
        { //注意i、pose重复
            printf("%d %d", arr[i], arr[pos]);
            break;
        }
    }
    if (i == n)
        printf("No Solution");
    return 0;
}