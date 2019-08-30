/*
	这道题还是要注意递归里面的全局变量与局部变量的关系，这样一来就决定了递归该怎么写

    另外防止爆内存的办法就是 直接在dfs里面输出结果，就是在子树的时候进行比较。
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

int n,m;
long long s;
int num[105];
vector<int>v[105];
vector<vector<int> > res;

bool cmp (int a,int b) {
    return num[a] > num[b];
}

long long sum;
vector<int>vv;
void dfs(int x,int sum) {
    sum += num[x];
    vv.push_back(num[x]);
    if (sum < s) {
        for (int i = 0; i < v[x].size(); i++) {
            dfs(v[x][i],sum);
        }
        if (!vv.empty()) {
            vv.pop_back();
            return;
        }
    }
    else if (sum > s) vv.pop_back();
    if (sum == s) {
        if (v[x].empty()) {
            printf("%d",vv[0]);
            for (int i = 1; i < vv.size(); i++) {
                printf(" %d",vv[i]);
            }
            printf("\n");
            vv.pop_back();
            return;
        }
        vv.pop_back();
        return;
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    scanf("%lld",&s);
    int id,x,t;
    long long tmp;
    for (int i = 0; i < n; i++) scanf("%d",&num[i]);
    for (int i = 0; i < m; i++) {
        scanf("%d %d",&id,&x);
        for (int j = 0; j < x; j++) {
            scanf("%d",&t);
            v[id].push_back(t);
        }
        sort(v[id].begin(),v[id].end(),cmp);
    }
    sum = 0;
    dfs(0,0);
    

    return 0;
}