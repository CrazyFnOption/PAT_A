/*
	其实用并查集的思想也可以写这道题 网上很多并查集的用法都有点复杂 我的比较简洁

    注意初始化的时候 不要出错了
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

const int maxn = 1e4 + 5;

int fa[maxn];
bool vis[maxn];
int n,k,x,y,t;
int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void unite(int x,int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) fa[fy] = fx;
}

void init () {
    for (int i = 0; i <= maxn; i++) {
        fa[i] = i;
    }
}


int main()
{
    scanf("%d",&n);
    init();
    int Max = -1;
    for (int i = 0; i < n; i++) {
        scanf("%d %d",&x,&y);
        Max = max(Max,y);
        vis[y] = true;
        for (int i = 0; i < x - 1; i++) {
            scanf("%d",&t);
            Max = max(Max,t);
            vis[t] = true;
            unite(y,t);
        }
    }
    int res = 0;
    int ans = 0;
    Max = max(Max,n);
    for (int i = 0; i <= Max; i++) {
        if (vis[i]) {
            res++;
            if (i == fa[i]) ans++;
        }
        
    }
    printf("%d %d\n",ans,res);
    scanf("%d",&k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d",&x,&y);
        if (find(x) == find(y)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}