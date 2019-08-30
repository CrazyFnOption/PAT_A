/*
	有想法就去写出来，就去实现，不过竟然没有超时 让我非常的惊讶。

    不过这道题 我写的有点复杂 有第二种做法 可以直接去利用并查集去写
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
#include <set>

using namespace std;
int n,k;
vector<int>tree[10004];
vector<int>bird[10004];
set<int>s[10004];
bool vis[10004];
int tot = 0;
void dfs(int x,int tot) {
    if (vis[x]) return;
    vis[x] = true;
    for (int i = 0; i < tree[x].size(); i++) {
        int u = tree[x][i];
        s[tot].insert(u);
        for (int j = 0; j < bird[u].size(); j++) {
            dfs(bird[u][j],tot);
        }
    }
}

int main()
{
    scanf("%d",&n);
    int x,t;
    for (int i = 1;i <= n; i++) {
        scanf("%d",&x);
        for (int j = 0; j < x; j++) {
            scanf("%d",&t);
            tree[i].push_back(t);
            bird[t].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i,tot);
            tot++;
        }
    }
    int sum = 0;
    for (int i = 0; i < tot; i++) {
        sum += s[i].size();
    }

    printf("%d %d\n",tot,sum);
    scanf("%d",&k);
    int a,b;
    for (int i = 0; i < k; i++) {
        scanf("%d %d",&a,&b);
        for (int j = 0; j < tot; j++) {
            auto it = s[j].find(a);
            if (it == s[j].end()) continue;
            auto it2 = s[j].find(b);
            if (it2 == s[j].end()) printf("No\n");
            else printf("Yes\n");
            break;
        }
    }
    

    return 0;
}