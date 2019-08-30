/*
	模拟归并排序和插入排序  
    真的感觉 在这个考试中 像这样的基础排序题 真的很常见
    题目说了 one more iteration ...
    这道题需要自己再写一遍 正好加深自己对于归并排序与快速排序的记忆
*/
#include <iostream>
#include <algorithm>
using namespace std;
int ori[110], temp[110], ans[110], n;
void show(int a[])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        if (i != n - 1)
            printf(" ");
    }
}
bool issame(int a[])
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] != ans[i])
            return false;
    }
    return true;
}
bool isInsert(int a[])
{
    bool flag = false;
    for (int i = 1; i < n; i++)
    {
        if (i != 1 && issame(a))
        {
            flag = true;
        }
        int num = a[i], j;
        for (j = i - 1; j >= 0; j--)
        {
            if (num < a[j])
                a[j + 1] = a[j];
            else
                break;
        }
        a[++j] = num;
        if (flag)
            return true;
    }
    return false;
}
void Mergesort(int a[])
{
    bool flag = false;
    for (int step = 2; step / 2 <= n; step *= 2)
    {
        if (step != 1 && issame(a))
        {
            flag = true;
        }
        for (int i = 0; i < n; i += step)
        {
            //这里就是归并排序的原理了，每次多个step进行排序
            //这里的比较最小值就是为了防止越界
            sort(a + i, a + min(i + step, n));
        }
        if (flag)
            break;
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ori[i]);
        temp[i] = ori[i];
    }
    for (int i = 0; i < n; i++)
        scanf("%d", &ans[i]);
    if (isInsert(ori))
    {
        printf("Insertion Sort\n");
        show(ori);
    }
    else
    {
        printf("Merge Sort\n");
        Mergesort(temp);
        show(temp);
    }
    return 0;
}