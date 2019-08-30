/*
	千算万算没有想到是一道01背包题目，考虑了暴力，dfs以及二分查找，但是就是没有扯到背包上面去想

    主要是自己做的背包题，都是板子裸题，还没有想清楚一些背包题目的应用于实际联系到一起。

    不过这道题目并不是单纯的01背包裸题，需要在加入背包里面计算出最小序列。

    以后涉及到 取或者不取的问题 都有可能是背包题目。
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<cstdio>
#include<queue>
#include<map>
#include<cmath>

using namespace std;

int n,m;
int num[10005];
int dp[105];
bool vis[10005][105];
bool cmp (int a,int b) {return a > b;}

int main()
{
	scanf("%d %d",&n,&m);
    //vector<int>res;
    for (int i = 1; i <= n; i++) scanf("%d",&num[i]);
    //这里进行一个从大到小的排序，就是为了方便后面的判断条件，一旦有相等的情况，便说明取到了后面的数
    //然而这里保证后面的数一定小，所以取到之后就保证一定是最小的序列。
    sort(num + 1,num + 1 + n,cmp);
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= num[i]; j--) {
            if (dp[j] <= dp[j - num[i]] + num[i]) {
                dp[j] = dp[j - num[i]] + num[i];
                vis[i][j] = true;
                //最先开始的做法就是使用res存入每一个比较的结果
                //但是 后面发现一个问题，只要比较在这个位置去取了的，那么一定装入到背包里面
                //如果存在更新的问题，那么就会出现问题，所以最好有一个标记我在背包容量为多少的时候，取出的硬币
                //res.push_back(num[i]);
            }
        }
    }
    if (dp[m] != m) printf("No Solution");
    else {
        //另外包括后面求值的时候，都是从最大的往后面输入
        // 根据代码 这里的j一定要写的大于0 不能大于等于0
        for (int i = n,j = m; (i >= 0 || j > 0); i--) {
            if (vis[i][j]) {
                printf("%d",num[i]);
                j = j - num[i];
                if (j != 0) printf(" ");
            }
        }

    }
	
    return 0;
}