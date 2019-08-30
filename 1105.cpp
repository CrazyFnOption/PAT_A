#include <iostream>
#include <initializer_list>
#include <algorithm>
#include <string>
#include <string.h>
#include <thread>
#include <cmath>
#include <vector>

using namespace std;
const int maxn = 1e4 + 5;
int n, m, k;
int num[maxn];
int mapp[maxn][maxn];
void show()
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            printf("%d%c", mapp[i][j], j == n - 1 ? '\n' : ' ');
}
int main()
{
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
        scanf("%d", num + i);
    sort(num, num + k, greater<int>());
    //这里就是求取两个因子且两个因子之间的差最小，首先就是先找到一个能被k整除最大的i
    //自己的思路已经很接近这个地方了，自己的想法就是在其的开根号左右两边去寻找，但是这样不好控制，因为控制最大最小需要很多时间，
    //不如就直接跟着这种做法来确定 算一个最大能被其整除的i，而且这个i必定是在其开根号的左边
    for (int i = 1; i * i <= k; i++)
        if (k % i == 0)
            n = i;
    m = k / n;
    int cnt = 0, L = 0, R = n, U = 0, D = m, j;
    while (cnt < k)
    {
        j = L;
        //这里循环一个过程，然后每一整个大循环最后的结果就是缩小边界
        while (j < R && cnt < k)
            mapp[U][j++] = num[cnt++];
        j = U + 1;
        while (j < D && cnt < k)
            mapp[j++][R - 1] = num[cnt++];

        j = R - 2;
        while (j >= L && cnt < k)
            mapp[D - 1][j--] = num[cnt++];
        j = D - 2;
        while (j > U && cnt < k)
            mapp[j--][L] = num[cnt++];
        U++, D--, L++, R--;
    }
    show();
}