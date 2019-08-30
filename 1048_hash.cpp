/*
	竟然还有这种做法，标记大法好

    这样时间复杂度的话就特别低，用空间去交换时间
*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int main()
{
    int n, m, a, hashTable[maxn] = {0}, flag = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        hashTable[a]++;
    }
    for (int i = 1; i < m; i++)
    { //m 用得很妙
        if (hashTable[i] != 0 && hashTable[m - i] != 0)
        {
            if (i == m - i && hashTable[i] <= 1)
            {
                continue;
            }
            printf("%d %d", i, m - i);
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        printf("No Solution");
    return 0;
}