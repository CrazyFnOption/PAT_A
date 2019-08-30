/*
	果然这个样子做 一定会超时一个 所以 换另外一种办法
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
#include <iomanip>
using namespace std;

const int maxn = 1e5 + 5;
int n;
double p,r;
vector<int> v[maxn];
vector<int>re;
double mindep = 99999999;
int res = 0;

//先开始自己的做法就是在递归中直接计算出num的值，这样同样会超时的原因就在于计算过程超时
//跟自己前面逐点遍历的原因是一样的，主要是pow的函数使用次数过多，导致超时
//不需要最后遍历的时候去比较，完全可以直接在dfs里面比较清楚
void dfs(int u,double p) {
    
    if (v[u].empty()) {
        if (mindep == p) res ++;
        if (p < mindep) {
            res = 1;
            mindep = p;
        }
        return;
    }
    for (int i = 0; i < v[u].size(); i++) {
        dfs(v[u][i],p * (1 + r));
    }
}

int main()
{
    scanf("%d %lf %lf",&n,&p,&r);
    r = r / 100;
    int x,t;
    for (int i = 0; i < n; i++) {
        scanf("%d",&x);
        if (x == 0) {
            re.push_back(i);
            continue;
        }
        for (int j = 0; j < x; j++) {
            scanf("%d", &t);
            v[i].push_back(t);
        }
    }
    dfs(0,p);
    printf("%.4lf %d\n",mindep,res);
    
    return 0;
}