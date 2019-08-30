/*
	这道题就是一道 最长公共子序列的模板题

    不过 自己没有想出来的原因就是因为自己只做过不重复的，没有做过重复的题目

    重复与不重复的规律已经在下面总结了

    现在这道题还有一种做法 最长不上升子序列的做法 通过标记
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
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m,l;
    cin >> n >> m;
    int a[m + 5];
    for (int i = 1; i <= m; i++) cin >> a[i];
    cin >> l;
    int b[l + 5];
    for (int i = 1; i <= l; i++) cin >> b[i];
    int dp[m + 5][l + 5];
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= l; j++) {
            //这个地方 如果是可以重复的话是找前面和上面的最大值并且加1
            //但是如果不重复的话 就是直接上斜上方的值加一即可。
            if (a[i] == b[j]) dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]) + 1;
            else dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
        }
    }

    cout << dp[m][l] << endl;

    return 0;
}