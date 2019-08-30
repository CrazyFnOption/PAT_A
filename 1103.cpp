/*
	这道题算是一道非常难的题了  
    至少对于我来说，像这样找数 的题，要么dfs加上背包 要么就只能暴力了

    以后写dfs 还是将会变的量直接设置成局部变量算了
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

int n,k,p;
const int maxn = 100;
int num[maxn];
int tot = 1;
vector<int>tempres,res;
int Max = -1;

void init() {
    int tmp = 0;
    while (tmp <= n) {
        num[tot] = pow(tot,p);
        tmp = num[tot];
        tot++;
    }
}

void dfs(int x,int level,int sum,int realsum) {
    //这里必须限制level的个数，要不然就拥有都不会输出impossible这个答案了
    //因为只有这样才能进入到下面的 Max 与 sum的比较中
    if (realsum == n && level == k) {
        if (Max < sum) {
            Max = sum;
            res = tempres;
        }
        return;
    }

    if (level > k || realsum > n) return;
    //这个地方要注意一下顺序，既然是从大到小的顺序来看的话 必须倒叙
    //并且这里的写法与你一般写dfs的过程是不一样的，因为他涉及到每一个递归层数只有两个选择
    //要么选择，要么不选，不像图论里面的对于一个点的子节点 任意挑选，这个属于同一层里面的递归。
    //如果像这样的循环的话，那么久相当于每一层都要像这样的一整个循环，一定一定会爆栈的。
    if (x >= 1) {
        tempres.push_back(x);
        dfs(x,level + 1,sum + x,realsum + num[x]);
        tempres.pop_back();
        dfs(x - 1,level,sum,realsum);
    }
}


int main()
{
    scanf("%d%d%d",&n,&k,&p);
    init();
    dfs(tot - 1,0,0,0);
    if (Max == -1)
        printf("Impossible\n");
    else {
        printf("%d = %d^%d", n, res[0], p);
		for (int i = 1; i < res.size(); ++i) {
			printf(" + %d^%d", res[i], p);
		}

    }
    return 0;
}